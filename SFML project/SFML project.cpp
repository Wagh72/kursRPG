

#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;
class TileMap : public Drawable, public Transformable
{
public:

    Texture m_tileset;
    VertexArray m_vertices;
    string tileset = "GrassAndTrails.png";
    //функція для завантажування тайлів і текстури для них
    bool load(const string& tileset, Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
    {
        if (!m_tileset.loadFromFile(tileset))
            return false;
        //робимо "основу" тайлів які будуть зроблені з двух трикутників, тому і 6 вершин
        m_vertices.setPrimitiveType(sf::Triangles);
        m_vertices.resize(width * height * 6);

        //у цих двох циклах ми заповнюємо тайли проходячись по ним
        for (unsigned int i = 0; i < width; ++i)
        {
            for (unsigned int j = 0; j < height; ++j)
            {
                int tileNumber = tiles[i + j * width];  //повертає положення тайлу на мапі
                //знаходження потрібного тайлу у тайлсеті (файл з тайлами)
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x); //знаходження тайлу по горизонталі   //m_tileset.getSize().x - ширина усієї текстури, tileSize.x - ширина самого тайлу,
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x); //знаходження тайлу по вертикалі     //.x - використовується щоб знайти ширину текстури (у пікселях)
                //вказівник на позицію вершин трикутників актуального тайлу
                Vertex* triangles = &m_vertices[(i + j * width) * 6];

                //визначаємо по 6 вершин трикутників
                triangles[0].position = Vector2f(i * tileSize.x, j * tileSize.y);
                triangles[1].position = Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                triangles[2].position = Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
                triangles[3].position = Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
                triangles[4].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                triangles[5].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);

                //визначаємо текстурні координати для вершин 
                triangles[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                triangles[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                triangles[2].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
                triangles[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
                triangles[4].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                triangles[5].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);

            }
            return true;
        }
    }

private:
    //Рендер тайлів
    virtual void draw(RenderTarget& target, RenderStates states)  const
    {
        states.transform *= getTransform();
        states.texture = &m_tileset;
        target.draw(m_vertices, states);
    }
    
};
int main()
{
    RenderWindow window(VideoMode(1024, 1024), "Tilemap");
    //Робимо мапу через масив
    const int level[] =
    {
    1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,35,36,5,6,19,19,2,3,4,1,2,3,4,1,2,5,6,
    9,6,7,19,19,21,22,19,19,19,11,12,21,22,11,43,44,13,14,19,9,10,11,12,9,10,5,5,6,10,5,6,
    17,14,15,19,21,19,19,19,19,19,19,19,19,30,19,51,52,21,19,19,6,24,5,6,6,18,19,19,19,5,6,14,
    25,22,21,23,19,19,19,19,19,6,19,19,19,26,27,35,36,5,19,19,19,32,19,14,14,19,19,21,19,19,19,22,
    30,13,21,19,19,6,19,19,1,14,6,7,19,2,3,43,44,13,14,19,22,2,19,22,22,2,3,4,1,21,22,4,
    30,21,11,19,32,6,19,12,6,7,14,15,29,30,11,51,52,21,22,19,5,5,19,12,9,10,23,24,9,10,11,12,
    17,29,19,20,17,19,19,22,19,15,22,23,29,30,19,51,52,18,19,19,13,19,19,20,5,6,31,32,17,18,19,20,
    25,29,30,19,19,14,19,22,30,23,23,15,25,26,19,51,52,26,27,21,21,19,19,28,13,14,27,28,25,26,27,28,
    1,29,29,19,19,22,19,22,19,22,23,23,29,19,19,43,44,2,3,23,23,19,19,19,21,22,3,4,1,5,6,4,
    9,10,11,19,19,19,19,30,6,7,30,19,9,19,11,35,36,10,11,5,6,31,32,19,19,23,19,24,9,13,14,12,
    17,19,19,19,19,19,19,6,21,15,19,19,19,19,19,43,44,18,19,13,14,18,19,20,17,19,19,32,17,21,22,20,
    19,19,23,29,19,19,19,19,22,19,19,19,19,19,27,35,36,26,27,21,22,26,27,28,25,19,19,19,25,26,27,28,
    1,2,31,32,1,2,31,22,21,23,3,4,1,3,4,43,44,2,3,21,22,2,5,6,6,6,3,23,24,24,5,6,
    9,10,11,29,30,10,11,12,9,10,11,23,24,3,4,35,36,10,11,12,9,10,13,14,14,14,11,31,32,32,13,14,
    17,29,29,30,17,21,19,20,21,21,19,31,32,22,4,35,36,5,6,20,17,18,21,22,22,22,19,20,17,18,21,22,
    25,26,27,29,30,26,23,24,25,26,27,28,29,30,4,35,36,13,14,28,25,26,27,28,25,26,27,28,25,26,27,28,
    37,38,39,40,40,37,37,38,40,38,39,40,40,38,39,61,62,37,38,37,38,39,37,37,38,37,37,37,37,38,37,38,
    45,46,45,48,45,45,45,46,45,46,45,45,48,46,45,58,57,45,46,45,46,47,45,45,46,45,45,45,45,46,45,46,
    17,5,6,7,8,8,8,8,5,6,5,5,6,7,8,35,36,21,22,20,17,18,19,20,17,18,19,20,17,18,19,20,
    25,5,14,14,14,14,15,16,8,8,8,6,7,8,16,35,36,29,30,28,25,26,27,28,25,26,7,8,25,26,27,28,
    5,5,19,19,19,14,5,15,16,16,16,6,7,8,24,43,44,2,3,4,1,2,3,4,1,2,15,16,1,2,7,8,
    13,14,14,19,19,15,5,15,16,16,16,16,16,16,32,35,36,10,11,7,7,8,11,7,8,10,23,24,9,7,8,8,
    21,22,22,22,14,5,5,19,16,5,24,24,24,24,16,35,36,18,19,15,15,16,19,15,16,18,19,20,17,15,16,16,
    29,30,30,30,22,19,19,19,14,5,5,32,32,32,24,35,36,26,27,23,23,24,27,23,24,8,8,28,25,23,24,24,
    19,19,31,32,5,19,19,19,14,5,5,19,19,19,14,35,36,2,3,4,7,8,8,4,15,16,16,4,7,8,3,4,
    19,31,29,14,5,5,19,5,19,13,13,19,5,19,22,43,44,10,11,12,15,16,16,12,23,24,24,19,19,16,19,12,
    30,19,19,19,5,13,13,5,19,21,21,19,19,5,5,51,52,18,19,20,23,24,24,20,17,18,19,19,19,23,19,20,
    30,19,19,19,13,21,21,13,5,30,31,19,19,13,13,51,52,26,27,28,19,19,19,13,21,21,15,29,19,31,19,28,
    30,19,19,19,21,13,21,19,19,19,19,5,31,19,21,51,52,2,21,13,13,19,19,13,19,23,23,24,19,21,19,22,
    29,30,19,19,5,21,21,21,21,19,19,19,5,19,31,43,5,10,13,19,19,13,19,19,19,15,19,19,19,19,19,22,
    17,29,5,19,19,19,19,19,19,21,21,21,13,32,19,51,13,18,13,19,19,13,13,19,19,19,19,19,19,30,19,19,
    25,26,13,21,21,21,29,19,19,31,32,21,21,24,27,28,25,29,19,18,14,19,19,29,19,19,18,18,18,13,14,28
    };


    TileMap map;
    if (!map.load("GrassAndTrails.png", Vector2u(32, 32), level, 1024, 1024))

        return -1;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(map);
        window.display();
    }
    return 0;
}
/*
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* int width = 16;
    int height = 16;
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
*  square[0].color = Color::Red;
    square[1].color = Color::Blue;
    square[2].color = Color::Green;


    Window window(VideoMode(800, 800), "game");
    while (window.isOpen())
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.scancode == sf::Keyboard::Scan::Escape)
                {
                    window.close();
                }
            }
        }

    Event event;
    Event event1;
    Clock clock;
    Time elapsed1 = clock.getElapsedTime();
    Window window(VideoMode(800, 600), "time window");
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

    }


if (t1 == seconds(10))
Window window(VideoMode(300, 200), "bye");
cout << "Time is enlapsed, your time is", elapsed1;
while (window.pollEvent(event1))
{
    if (event1.type == Event::Closed)
        window.close();
        */
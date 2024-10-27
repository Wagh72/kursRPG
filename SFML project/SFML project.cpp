

#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;
class TileMap : public Drawable, public Transformable
{
public:

    string tileset = "image.png";
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

private:
    //Рендер тайлів
    virtual void draw(RenderTarget& target, RenderStates states)  const
    {
        states.transform *= getTransform();
        states.texture = &m_tileset;
        target.draw(m_vertices, states);
    }
    Texture m_tileset;
    VertexArray m_vertices;
};
int main()
{
    RenderWindow window(VideoMode(512, 256), "Tilemap");
    //Робимо мапу через масив
    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };


    TileMap map;
    if (!map.load("image.png", Vector2u(32, 32), level, 16, 8)) // 16х8 - ширина на висоту мапи

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
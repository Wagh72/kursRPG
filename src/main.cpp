#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>
#include <iostream>
#include <cmath>

const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 1024;

const int TILE_SIZE = 32;

const int LAYER_WIDTH = 32;
const int LAYER_HEIGHT = 32;

int layer1[LAYER_HEIGHT][LAYER_WIDTH] =
{
1,2,3,4,1,2,3,38,39,40,3,5,1,2,3,67,68,2,6,7,6,7,22,23,1,2,3,4,1,2,3,4,
17,6,7,20,17,18,19,38,39,40,19,20,17,18,19,83,84,18,22,23,22,23,19,20,17,18,19,20,6,7,6,7,
6,22,23,5,5,5,5,54,55,56,35,36,33,34,35,99,100,34,35,36,19,34,35,38,39,40,40,40,6,7,6,7,
22,23,39,40,40,40,21,5,38,39,40,5,6,6,40,67,68,50,51,52,54,55,51,54,55,56,56,56,22,23,6,7,
1,54,55,56,56,56,38,19,19,38,38,5,6,22,56,83,84,2,5,5,54,54,55,4,38,19,40,6,7,7,6,7,
17,18,5,54,19,19,54,55,19,19,54,21,22,18,19,99,100,18,21,5,5,54,19,6,6,55,38,22,23,23,22,23,
33,6,7,6,7,34,35,5,6,19,39,40,23,34,35,83,84,34,24,21,5,5,21,19,22,55,19,39,40,39,35,36,
49,22,23,22,19,38,39,40,6,19,55,56,38,39,40,99,100,50,24,24,21,5,6,19,49,37,19,19,6,6,51,52,
1,2,37,38,19,54,55,56,38,19,40,4,54,55,56,83,84,2,54,24,54,55,7,7,6,7,54,21,19,22,6,7,
17,6,7,20,19,19,55,19,19,19,39,19,17,18,19,99,100,24,24,55,54,24,7,23,22,23,19,20,17,18,22,23,
33,22,23,5,6,19,55,56,54,19,39,40,38,39,40,67,68,24,24,24,55,24,23,39,7,19,6,7,6,6,7,7,
49,5,6,7,7,19,19,56,55,38,39,40,38,39,40,83,84,39,54,55,24,24,24,19,7,54,55,55,22,22,23,23,
5,6,7,7,38,38,39,40,1,54,55,38,39,3,40,67,68,38,24,39,23,7,24,6,7,54,55,22,22,23,3,4,
5,6,7,23,54,54,55,56,17,18,19,38,39,40,56,83,84,37,38,38,39,40,7,7,19,37,37,38,38,39,40,20,
70,71,72,69,70,71,72,69,70,71,72,69,70,71,72,117,118,69,70,71,69,70,71,72,69,70,71,69,69,70,71,72,
86,87,88,85,86,87,88,85,86,87,88,85,86,87,88,114,113,85,86,87,85,86,87,88,85,86,87,85,85,86,87,88,
1,2,3,38,54,19,55,56,22,23,3,4,38,39,5,67,68,2,3,4,1,37,38,39,38,39,19,19,6,2,54,55,
38,38,38,39,19,19,56,56,38,39,40,40,38,38,21,83,84,18,19,20,17,19,38,39,38,19,19,19,19,6,6,20,
54,54,54,19,19,19,55,56,54,19,19,56,54,54,38,99,100,39,40,38,39,19,40,40,38,39,19,19,21,22,22,36,
54,55,54,19,56,19,40,39,40,19,55,56,56,50,54,83,84,55,56,54,55,56,56,56,54,19,19,19,19,40,7,52,
38,39,19,19,55,56,56,39,19,19,3,4,1,2,3,99,100,2,3,4,1,2,3,54,38,6,7,19,56,56,23,4,
54,19,19,19,40,40,38,38,19,40,38,38,39,40,19,83,84,39,40,40,17,18,19,20,38,22,23,19,19,40,39,7,
39,19,19,55,19,5,6,38,38,39,54,54,55,56,35,99,100,40,40,56,33,34,38,39,38,19,19,55,19,19,39,23,
39,21,6,7,19,6,6,54,54,55,54,55,56,50,51,83,84,56,56,52,49,50,38,39,54,55,6,7,7,37,38,39,
55,56,22,23,19,6,22,38,39,19,19,19,19,2,3,99,100,2,3,4,1,2,54,55,19,19,22,23,23,5,6,6,
17,38,39,5,19,19,40,38,38,21,22,22,40,18,19,67,68,40,38,39,40,5,19,19,19,39,40,22,23,21,22,22,
38,39,40,19,19,19,56,40,54,54,5,5,6,34,35,83,84,39,40,40,38,19,19,40,54,55,56,5,19,21,22,36,
54,55,5,19,6,55,56,56,49,54,21,19,5,6,38,99,100,40,56,56,19,21,22,56,19,50,19,6,19,56,51,52,
38,39,21,22,22,54,55,56,40,2,38,19,19,22,40,67,68,56,19,19,21,22,3,4,19,5,19,19,19,2,3,4,
39,38,39,40,55,56,54,55,56,19,38,19,19,40,38,83,84,40,19,40,5,6,19,20,19,21,22,20,5,5,6,20,
38,38,39,40,40,34,35,36,33,19,54,55,19,56,39,99,100,56,56,56,21,22,35,36,33,34,35,5,21,21,22,36,
54,54,55,56,56,50,51,38,38,54,55,54,55,56,55,115,116,54,55,56,49,50,51,52,49,50,51,21,22,50,51,52

};

int layer2[LAYER_HEIGHT][LAYER_WIDTH] =
    {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,10,11,12,13,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,14,15,16,0,0,0,0,0,0,25,26,27,28,29,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,30,31,32,0,0,0,0,0,0,41,42,43,44,45,0,0,0,0,0,0,0,0,0,0,0,
0,0,9,10,11,12,13,46,47,48,0,9,10,11,12,13,57,58,59,60,61,0,14,15,16,0,0,0,0,0,0,0,
0,0,25,26,27,28,29,62,63,64,0,25,26,27,28,29,73,74,75,76,77,0,30,31,32,0,9,10,11,12,13,0,
0,0,41,42,43,44,45,78,79,80,0,41,42,43,44,45,9,10,11,12,13,0,46,47,48,0,25,26,27,28,29,0,
0,0,57,58,59,60,61,0,0,0,0,57,58,59,60,61,25,26,27,28,29,0,62,63,64,0,41,42,43,44,45,0,
10,11,12,13,75,76,77,0,0,0,0,73,74,75,76,77,41,42,43,44,45,0,78,79,80,0,57,58,59,60,61,0,
26,27,28,29,0,0,0,14,15,16,0,9,10,11,12,13,57,58,59,60,61,14,15,16,0,0,73,74,75,76,77,0,
42,43,44,45,0,0,0,30,31,32,0,25,26,27,28,29,73,74,75,76,77,30,31,32,0,0,0,0,0,0,0,0,
58,59,60,61,0,0,0,46,47,48,0,41,42,43,44,45,0,0,0,0,0,46,47,48,0,0,0,0,0,0,0,0,
74,75,76,77,0,0,0,62,63,64,0,57,58,59,60,61,0,0,0,0,0,62,63,64,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,78,79,80,0,73,74,75,76,77,0,0,0,0,0,78,79,80,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,14,15,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,30,31,32,0,0,0,0,14,15,16,0,0,0,14,15,16,0,0,0,0,0,0,14,15,16,0,0,0,
0,0,0,0,46,47,48,0,0,0,0,30,31,32,0,0,0,30,31,32,0,0,0,0,0,0,30,31,32,0,0,0,
9,10,11,12,62,63,64,0,0,0,0,46,47,48,0,0,0,46,47,48,0,0,0,0,0,0,46,47,48,0,0,0,
25,26,27,28,78,79,80,0,0,0,0,62,63,64,0,0,0,62,63,64,0,0,0,0,0,0,62,63,64,0,0,0,
41,42,43,44,45,0,0,0,0,0,0,78,79,80,0,0,0,78,79,80,10,11,12,13,0,0,78,79,80,0,0,0,
57,58,59,60,61,0,0,0,0,0,0,0,0,0,0,0,0,0,0,25,26,27,28,29,0,0,0,0,0,0,0,0,
73,74,75,76,77,0,0,0,0,0,0,0,0,0,0,0,0,0,0,41,42,43,44,45,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,57,58,59,60,61,0,0,0,0,0,14,15,16,
0,0,0,0,0,0,0,0,0,9,10,11,12,13,0,0,0,0,0,73,74,75,76,77,0,0,0,0,0,30,31,32,
0,0,0,0,0,0,0,0,0,25,26,27,28,29,0,0,9,10,11,12,13,0,0,0,0,0,0,0,0,46,47,48,
0,0,0,9,10,11,12,13,0,41,42,43,44,45,0,0,25,26,27,28,29,0,0,0,0,0,0,0,0,62,63,64,
0,0,0,25,26,27,28,29,0,57,58,59,60,61,0,0,41,42,43,44,45,0,0,9,10,11,12,13,0,78,79,80,
0,0,0,41,42,43,44,45,0,73,74,75,76,77,0,0,57,58,59,60,61,0,0,25,26,27,28,29,0,0,0,0,
0,0,0,57,58,59,60,61,0,0,0,0,0,0,0,0,73,74,75,76,77,0,0,41,42,43,44,45,0,0,0,0,
0,0,0,73,74,75,76,77,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,57,58,59,60,61,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,73,74,75,76,77,0,0,0,0
};

bool loadTexture(sf::Texture &texture, const std::string &path)
{
    return texture.loadFromFile(path);
}

void drawMap(sf::RenderWindow& window, const sf::Texture& texture1)
{
    sf::Sprite sprite;
    const int ACTUAL_TILE_SIZE = 32; // Розмір одного тайлу
    const int TEXTURE_ATLAS_WIDTH = 512; // Ширина атласу текстур

    sprite.setTexture(texture1);

    // Рендеринг першого шару
    for (int y = 0; y < LAYER_HEIGHT; ++y)
    {
        for (int x = 0; x < LAYER_WIDTH; ++x)
        {
            int tileNumber = layer1[y][x];
            if (tileNumber > 0) // Пропустити пусті тайли
            {
                sprite.setTextureRect(sf::IntRect(
                    (tileNumber - 1) % (TEXTURE_ATLAS_WIDTH / ACTUAL_TILE_SIZE) * ACTUAL_TILE_SIZE,
                    (tileNumber - 1) / (TEXTURE_ATLAS_WIDTH / ACTUAL_TILE_SIZE) * ACTUAL_TILE_SIZE,
                    ACTUAL_TILE_SIZE, ACTUAL_TILE_SIZE));
                sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
                window.draw(sprite);
            }
        }
    }

    // Рендеринг другого шару
    for (int y = 0; y < LAYER_HEIGHT; ++y)
    {
        for (int x = 0; x < LAYER_WIDTH; ++x)
        {
            int tileNumber = layer2[y][x];
            if (tileNumber > 0) // Пропустити пусті тайли
            {
                sprite.setTextureRect(sf::IntRect(
                    (tileNumber - 1) % (TEXTURE_ATLAS_WIDTH / ACTUAL_TILE_SIZE) * ACTUAL_TILE_SIZE,
                    (tileNumber - 1) / (TEXTURE_ATLAS_WIDTH / ACTUAL_TILE_SIZE) * ACTUAL_TILE_SIZE,
                    ACTUAL_TILE_SIZE, ACTUAL_TILE_SIZE));
                sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
                window.draw(sprite);
            }
        }
    }
}

void drawPlayer(sf::RenderWindow& window, sf::Sprite& Player, int x, int y)
{
   Player.setPosition(x, y);
   window.draw(Player);
}
void PlayerMovement(sf::Sprite& Player, int& x, int& y)
{
    int speed = 1;

    // Оновлення координат залежно від натискань клавіш
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        x -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        x += speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        y -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        y += speed;
    }

    // Перевірка на межі вікна
    if (x < 0) x = 0;
    if (x >= WINDOW_WIDTH) x = WINDOW_WIDTH - 32;
    if (y < 0) y = 0;
    if (y >= WINDOW_HEIGHT) y = WINDOW_HEIGHT - 32;
    std::cout << "x: " << x << ", y: " << y << std::endl;
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "test");
    sf::Texture texture1, PlayerTexture;
    sf::Sprite Player;
    if (!loadTexture(texture1, "src/textures/ReBild1.png"))
        std::cerr << "Error loading texture1" << std::endl;
    if (!loadTexture(PlayerTexture, "src/textures/Pltexture.png"))
        std::cerr << "Error loading Player Texture" << std::endl;
    Player.setTexture(PlayerTexture);
    int x = 512;
    int y = 512;
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        drawMap(window, texture1);
        drawPlayer(window, Player, x, y);
        PlayerMovement(Player, x, y);
        window.display();

        static int frameCount = 0;
        static float elapsedTime = 0.0f;
        frameCount++;
        elapsedTime += clock.restart().asSeconds();

        if (elapsedTime >= 1.0f)
        {
            std::stringstream title;
            title << "FPS: " << frameCount;
            window.setTitle(title.str());
            frameCount = 0;
            elapsedTime = 0.0f;
        }
    }
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










int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "test");
    sf::Texture texture1, PlayerTexture;
    sf::Sprite Player;
    if (!loadTexture(texture1, "src/textures/ReBild1.png"))
        std::cerr << "Error loading texture1" << std::endl;
    if (!loadTexture(PlayerTexture, "src/textures/Pltexture.png"))
        std::cerr << "Error loading Player Texture" << std::endl;
    Player.setTexture(PlayerTexture);
    int x = 0;
    int y = 0;
    bool keyProcessed = false;
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        drawMap(window, texture1);
        drawPlayer(window, Player, x, y);

        if (event.type == sf::Event::KeyPressed && !keyProcessed)
        {
            if (event.key.code == sf::Keyboard::Right)
            {
                x += 100;
                keyProcessed = true;
            }

            if (event.key.code == sf::Keyboard::Left)
            {
                x -= 100;
                keyProcessed = true;
            }

            if (event.key.code == sf::Keyboard::Up)
            {
                 y -= 100;
                keyProcessed = true;
            }

            if (event.key.code == sf::Keyboard::Down)
            {
                y += 100;
                keyProcessed = true;
            }
        }

        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Right)
            {
                keyProcessed = false;
            }

            if (event.key.code == sf::Keyboard::Left)
            {
                //x -= 100;
                keyProcessed = false;
            }
            if (event.key.code == sf::Keyboard::Up)
            {
                keyProcessed = false;
            }

            if (event.key.code == sf::Keyboard::Down)
            {
                // y += 100;
                keyProcessed = false;
            }
        }

        PlayerMovement(Player);
        window.display();

        static int frameCount = 0;
        static float elapsedTime = 0.0f;
        frameCount++;
        elapsedTime += clock.restart().asSeconds();

        if (elapsedTime >= 1.0f)
        {
            std::stringstream title;
            title << "FPS: " << frameCount;
            window.setTitle(title.str());
            frameCount = 0;
            elapsedTime = 0.0f;
        }




int layer3[LAYER_HEIGHT][LAYER_WIDTH] =
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 10, 11, 12, 13},
    {0, 1, 2, 3, 4, 5, 0, 0, 0, 0, 0, 17, 18, 19, 20, 21},
    {0, 9, 10, 11, 12, 13, 0, 0, 0, 0, 0, 25, 26, 27, 28, 29},
    {0, 17, 18, 19, 20, 21, 0, 0, 0, 0, 0, 33, 34, 35, 36, 37},
    {0, 25, 26, 27, 28, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 33, 34, 35, 36, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };




    sprite.setTexture(texture2);
    for (int y = 0; y < LAYER_HEIGHT; ++y)
    {
        for (int x = 0; x < LAYER_WIDTH; ++x)
        {
            int tileNumber = layer2[y][x];
            if (tileNumber > 0)
            {
                sprite.setTextureRect(sf::IntRect((tileNumber - 1) % (TEXTURE_GRASS_ATLAS_WIDTH / ACTUAL_TILE_SIZE) * ACTUAL_TILE_SIZE,
                    (tileNumber - 1) / (TEXTURE_GRASS_ATLAS_WIDTH / ACTUAL_TILE_SIZE) * ACTUAL_TILE_SIZE,
                    ACTUAL_TILE_SIZE, ACTUAL_TILE_SIZE));
                sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
                window.draw(sprite);
            }
        }
    }



    sf::Sprite Player;
    Player.setTexture(PlayerTexture);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        Player.move(1.f, 0.f);
    }





    sprite.setTexture(texture3);
    for (int y = 0; y < LAYER_HEIGHT; ++y)
    {
        for (int x = 0; x < LAYER_WIDTH; ++x)
        {
            int tileNumber = layer3[y][x];
            if (tileNumber > 0)
            {
                sprite.setTextureRect(sf::IntRect((tileNumber - 1) % (TEXTURE_ATLAS_WIDTH / ACTUAL_TILE_SIZE) * ACTUAL_TILE_SIZE,
                                                  (tileNumber - 1) / (TEXTURE_ATLAS_WIDTH / ACTUAL_TILE_SIZE) * ACTUAL_TILE_SIZE,
                                                  ACTUAL_TILE_SIZE, ACTUAL_TILE_SIZE));
                sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
                window.draw(sprite);
            }
        }
    }
 */
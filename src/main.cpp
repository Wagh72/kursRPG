#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>
#include <iostream>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int TILE_SIZE = 32;

const int LAYER_WIDTH = 16;
const int LAYER_HEIGHT = 16;

int layer1[LAYER_HEIGHT][LAYER_WIDTH] =
    {
        {5, 6, 7, 9, 9, 1, 1, 1, 2, 3, 4, 4, 4, 4, 4, 4},
        {5, 6, 7, 17, 17, 9, 9, 1, 1, 2, 3, 4, 5, 6, 7, 12},
        {5, 5, 6, 7, 25, 17, 17, 29, 30, 31, 2, 5, 13, 14, 15, 20},
        {13, 5, 5, 6, 7, 25, 25, 29, 30, 31, 1, 13, 21, 22, 23, 2},
        {21, 13, 5, 5, 5, 6, 7, 29, 30, 31, 31, 21, 21, 22, 23, 1},
        {17, 21, 13, 13, 13, 14, 15, 1, 29, 30, 31, 31, 22, 23, 4, 1},
        {25, 25, 21, 21, 21, 22, 23, 9, 9, 29, 30, 31, 1, 1, 1, 2},
        {25, 1, 9, 9, 17, 17, 17, 17, 17, 17, 17, 9, 9, 9, 1, 1},
        {37, 38, 39, 40, 55, 56, 37, 61, 62, 39, 40, 37, 37, 38, 39, 40},
        {45, 46, 47, 48, 47, 48, 45, 45, 46, 47, 33, 34, 45, 46, 47, 48},
        {26, 25, 25, 26, 27, 28, 5, 6, 7, 7, 41, 42, 29, 30, 31, 25},
        {27, 25, 26, 27, 5, 6, 7, 7, 7, 15, 49, 50, 29, 29, 30, 31},
        {27, 28, 5, 6, 7, 7, 7, 15, 15, 23, 57, 58, 12, 29, 30, 31},
        {27, 5, 6, 7, 7, 15, 15, 23, 23, 20, 12, 12, 29, 30, 31, 31},
        {26, 13, 14, 15, 15, 23, 23, 28, 28, 29, 30, 31, 31, 31, 31, 10},
        {9, 21, 22, 23, 23, 28, 25, 26, 27, 28, 28, 28, 28, 28, 17, 18}};

int layer2[LAYER_HEIGHT][LAYER_WIDTH] =
    {
        {0, 0, 0, 0, 1, 2, 3, 4, 5, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 9, 10, 11, 12, 13, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 17, 18, 19, 20, 21, 1, 2, 3, 4, 5, 0, 0},
        {1, 2, 3, 4, 25, 26, 27, 28, 29, 9, 10, 11, 12, 13, 0, 0},
        {9, 10, 11, 12, 33, 34, 35, 36, 37, 17, 18, 19, 20, 21, 43, 44},
        {17, 18, 19, 20, 21, 0, 0, 0, 0, 25, 26, 27, 28, 29, 51, 52},
        {25, 26, 27, 28, 29, 0, 50, 0, 0, 33, 34, 35, 36, 37, 0, 0},
        {33, 34, 35, 36, 37, 6, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0},
};

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
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

bool loadTexture(sf::Texture &texture, const std::string &path)
{
    return texture.loadFromFile(path);
}

void drawMap(sf::RenderWindow &window, const sf::Texture &texture1, const sf::Texture &texture2, const sf::Texture &texture3)
{
    sf::Sprite sprite;

    const int ACTUAL_TILE_SIZE = 32; // 256 / 8 = 32 (256x256 .png = 8(32x32) - tiles)
    const int TEXTURE_ATLAS_WIDTH = 256;

    sprite.setTexture(texture1);
    for (int y = 0; y < LAYER_HEIGHT; ++y)
    {
        for (int x = 0; x < LAYER_WIDTH; ++x)
        {
            int tileNumber = layer1[y][x];
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

    sprite.setTexture(texture2);
    for (int y = 0; y < LAYER_HEIGHT; ++y)
    {
        for (int x = 0; x < LAYER_WIDTH; ++x)
        {
            int tileNumber = layer2[y][x];
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
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "test");

    sf::Texture texture1, texture2, texture3;
    if (!loadTexture(texture1, "src/textures/GrassAndTrails.png") ||
        !loadTexture(texture2, "src/textures/TX_PlantFix.png") ||
        !loadTexture(texture3, "src/textures/layer3test.png"))
    {
        std::cerr << "Error loading texture" << std::endl;
        return -1;
    }

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
        drawMap(window, texture1, texture2, texture3);
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

    return 0;
}
#ifndef GAME_H
#define GAME_H

#include <map>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include "playership.h"
#include "laser.h"
#include "enemyship.h"

class Game
{
    enum Difficulty
    {
        EASY,
        HARD
    };
private:
    Difficulty difficulty;
    sf::RenderWindow* window;

    std::map<std::string, sf::Texture*> textures;
    std::vector<Laser*> lasers;

    sf::Font font;
    sf::Text pointText;

    sf::Text gameOverText;
    sf::Text youWinText;

    sf::Texture Background;
    sf::Sprite worldBackground;

    unsigned points;

    PlayerShip* playerShip;
    EnemyShip* enemyShip;

    sf::RectangleShape playerHPbar;
    sf::RectangleShape playerHPbarMax;

    float enemySpawnTimer;
    float enemySpawnTimerMax;
    std::vector<EnemyShip*> enemyShips;


    bool inMenu;
    sf::Text playText;
    sf::Text quitText;
    sf::Text difficultyText;
    sf::Text instructionsText;
    int selectedMenuItem;


    sf::Texture menuBackgroundTexture;
    sf::Sprite menuBackground;

    void openWindow();
    void openTextures();
    void openText();
    void openBackground();
    void openSystems();

    void openPlayer();
    void openEnemies();
    void openMenu();

public:
    Game();
    virtual ~Game();

    void run();

    void updatePollEvents();
    void updateInput();
    void updateText();

    void updateWorld();
    void updateCollision();
    void updateLaser();
    void updateEnemies();
    void updateEnemyLaser();

    void update();
    void updateMenu();
    void renderMenu();

    void renderWorld();
    void renderText();
    void render();
};

#endif // GAME_H

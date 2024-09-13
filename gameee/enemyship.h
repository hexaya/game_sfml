#ifndef ENEMYSHIP_H
#define ENEMYSHIP_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
class EnemyShip
{
private:

    sf::CircleShape shape;

    int type;
    int speed;
    int hp;
    int hpMax;
    int dmg;
    int pts;


    void openVariables();
    void openShape();

public:

    unsigned pointCount;

    EnemyShip(float pos_x, float pos_y);
    virtual ~EnemyShip();

    const sf::FloatRect getBounds() const;
    const int& getPoints() const;
    const int& getDamage()const;


    void update();
    void render(sf::RenderTarget* target);
};

#endif // ENEMYSHIP_H

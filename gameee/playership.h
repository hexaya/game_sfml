#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
class PlayerShip
{
private:
    sf::Sprite sprite;
    sf::Texture texture;

    float movementSpeed;

    float attackCooldown;
    float attackCooldownMax;

    int hp;
    int hpMax;

    void  openVariables();
    void  openTexture();
    void  openSprite();


public:
    PlayerShip();
    virtual ~PlayerShip();

    const sf::Vector2f& getPos() const;
    const sf::FloatRect getBounds() const;
    const int& getHp() const;
    const int& getHpMax() const;



    void setPosition(const sf::Vector2f pos);
    void setPosition(const float x, const float y);
    void setHp(const int hp);
    void loseHp(const int value);


    void move(const float dirX, const float dirY);

    bool attackCDup();
    void updateAtackCD();
    void update();
    void render(sf::RenderTarget& target);
};

#endif // PLAYERSHIP_H

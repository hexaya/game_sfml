#include "playership.h"

void PlayerShip::openVariables()
{
    this->movementSpeed =15.f;
    this->attackCooldownMax=20.f;
    this->attackCooldown = this->attackCooldownMax;

    this->hpMax = 100;
    this->hp = this->hpMax;
}

void PlayerShip::openTexture()
{
    if(!this->texture.loadFromFile("C:/Users/kamil/OneDrive/Pulpit/ie/gameee/Textures/ship.png"))
    {
        // std::cout << "ERROR::PLAYER::OPENTEXTURE::Could not load file." << "\n";
    }

}

void PlayerShip::openSprite()
{
    this->sprite.setTexture(this->texture);

    this->sprite.scale(0.2f, 0.2f);
}

PlayerShip::PlayerShip()
{

    this->openVariables();
    this->openTexture();
    this->openSprite();
}

PlayerShip::~PlayerShip()
{

}

const sf::Vector2f &PlayerShip::getPos() const
{
    return this->sprite.getPosition();

}

const sf::FloatRect PlayerShip::getBounds() const
{
    return this->sprite.getGlobalBounds();
}

const int &PlayerShip::getHp() const
{
    return this->hp;
}

const int &PlayerShip::getHpMax() const
{
    return this->hpMax;
}

void PlayerShip::setPosition(const sf::Vector2f pos)
{
    this->sprite.setPosition(pos);
}

void PlayerShip::setPosition(const float x, const float y)
{
    this->sprite.setPosition(x,y);
}

void PlayerShip::setHp(const int hp)
{
    this-> hp = hp;
}

void PlayerShip::loseHp(const int value)
{
    this->hp-=value;
    if(this->hp <0)
        this->hp=0;
}

void PlayerShip::move(const float dirX, const float dirY)
{
    this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

bool PlayerShip::attackCDup()
{
    if(this->attackCooldown >= this->attackCooldownMax)
    {
        this->attackCooldown = 0.5f;
        return true;
    }
    return false;

}

void PlayerShip::updateAtackCD()
{
    if(this->attackCooldown < this->attackCooldownMax)
        this->attackCooldown += 1.f;
}

void PlayerShip::update()
{
    this->updateAtackCD();
}

void PlayerShip::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}

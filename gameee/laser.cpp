#include "laser.h"

Laser::Laser()
{

}


Laser::Laser(sf::Texture * texture, float pos_x, float pos_y, float dir_x, float dir_y, float laser_ms)
{
    this->shape.setTexture(*texture);

    this->shape.setPosition(pos_x, pos_y);
    this->direction.x = dir_x;
    this->direction.y = dir_y;
    this->movementSpeed = laser_ms;
    this->shape.scale(0.1f, 0.1f);
}

Laser::~Laser()
{

}

const sf::FloatRect Laser::getBounds() const
{
    return this->shape.getGlobalBounds();
}

void Laser::update()
{
    this->shape.move(this->movementSpeed * this->direction);
}

void Laser::render(sf::RenderTarget * target)
{
    target->draw(this->shape);
}



#include "enemyship.h"



    void EnemyShip::openVariables()
{
    this->pointCount = rand() % 8 + 3;
    this->type = 0;
    this->speed = static_cast<float>(this->pointCount/2.5);
    this->hpMax = static_cast<int>(this->pointCount);
    this->hp = this->hpMax;
    this->dmg = this->pointCount;
    this->pts = this->pointCount;


}

void EnemyShip::openShape()
{
    this->shape.setRadius(this->pointCount*5);
    this->shape.setPointCount(this->pointCount);
    this->shape.setFillColor(sf::Color(rand()%255+1,rand()%255+1,255));
}

EnemyShip::EnemyShip(float pos_x, float pos_y)
{

    this->openVariables();
    this->openShape();
    this->shape.setPosition(pos_x, pos_y);

}

EnemyShip::~EnemyShip()
{

}

const sf::FloatRect EnemyShip::getBounds() const
{
    return this->shape.getGlobalBounds();
}

const int &EnemyShip::getPoints() const
{
    return this->pts;
}

const int &EnemyShip::getDamage() const
{
    return this->dmg;
}



void EnemyShip::update()
{
    this->shape.move(0.f, this->speed);
}

void EnemyShip::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}

#ifndef LASER_H
#define LASER_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class Laser
{
private:
    sf::Sprite shape;


    sf::Vector2f direction;
    float movementSpeed;

public:
    Laser();
    Laser(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float laser_ms);
    virtual ~Laser();

    const sf::FloatRect getBounds() const;

    void update();
    void render(sf::RenderTarget* target);
};

#endif // LASER_H

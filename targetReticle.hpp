#pragma once
#include <SFML/Graphics.hpp>
class TargetReticle : public sf::CircleShape
{
public:
    TargetReticle(float newRadius, const sf::Vector2f& newPos,
        const sf::Color& newColor) :
        sf::CircleShape(newRadius)
    {
        //this->setRadius(newRadius);
        this->setPosition(newPos);
        this->setFillColor(newColor);
    }

    ~TargetReticle() {

    }

    void mouseLockOn(sf::Window& window) 
    {

        setPosition(sf::Mouse::getPosition(window).x - getRadius(), sf::Mouse::getPosition(window).y - getRadius());

    }

private:

protected:


};
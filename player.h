#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
using namespace std;

class PlayerCharacter : public sf::CircleShape
{
public:
    //Default constructor for now, will need to add stuff.
    PlayerCharacter(sf::Vector2f& newSize, const sf::Vector2f& newPos,
        const sf::Color& newColor) :
        sf::CircleShape(25.f, 25.f) {
        this->setFillColor(newColor);
        this->setPosition(newPos);
    }

    //deconstructor
    ~PlayerCharacter() {

    }

    //MemberFunctions

    void movementFunction() {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->getPosition().y < 950)
        {
            move(0, 15);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->getPosition().y > 0)
        {
            move(0, -15);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->getPosition().x < 950)
        {
            move(15, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->getPosition().x > 0)
        {
            move(-15, 0);
        }
    }

private:

};

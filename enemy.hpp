#pragma once
#include <SFML/Graphics.hpp>
class Enemy : public sf::RectangleShape
{
public:
    Enemy(sf::Vector2f& newSize, const sf::Vector2f& newPos,
        const sf::Color& newColor, int setHealth) :
        RectangleShape(newSize)
    {
        this->setFillColor(newColor);
        this->setPosition(newPos);
        health = setHealth;
    }

    ~Enemy() {

    }

    int getHealth() {
        return health;
    }

    void setHealth(int newHealth) {
        health = newHealth;
    }

    void damage() {
        --health;
    }

    virtual void enemyMovement() {

    }

    virtual void enemyAttack() {

    }

private:

protected:

    int health;
};
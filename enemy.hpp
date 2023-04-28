#pragma once
#include <SFML/Graphics.hpp>
class Enemy : public sf::RectangleShape
{
public:
    Enemy(sf::Vector2f& newSize, const sf::Vector2f& newPos,
        const sf::Color& newColor, int setHealth, int setDamage) :
        RectangleShape(newSize)
    {
        this->setFillColor(newColor);
        this->setPosition(newPos);
        health = setHealth;
        damage = setDamage;
    }

    ~Enemy() {

    }

    virtual void enemyMovement() {

    }

    virtual void enemyAttack() {

    }

private:

protected:

    int health;
    int damage;

};
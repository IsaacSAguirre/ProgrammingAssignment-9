#pragma once
#include "enemy.hpp"
#include "player.h"

class SillyFella : public Enemy
{
public:
    SillyFella(sf::Vector2f& newSize, const sf::Vector2f& newPos,
        const sf::Color& newColor, int& health, int& damage) :
        Enemy(newSize, newPos, newColor, health, damage) {

    }

    ~SillyFella() {

    }

    void enemyMovement(PlayerCharacter Player) {
        /*
        * Trig that should work to find an angle
        *
        * arctan((playerPosY-thisPosY)/(playerPosX-thisPosX))
        */

        float xDirection, yDirection, totalLength, compareFloat;
        //Always targets top left corner for now.
        xDirection = Player.getPosition().x - getPosition().x;
        yDirection = Player.getPosition().y - getPosition().y;
        totalLength = sqrt((pow(xDirection, 2) + pow(yDirection, 2)));
        compareFloat = 3 / totalLength;
        sf::Vector2f directon(xDirection *compareFloat, yDirection * compareFloat);
        move(directon);
    }

    void enemyAttack() {

    }
private:

};

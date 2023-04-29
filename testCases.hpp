#pragma once
#include "player.h"
#include "targetReticle.hpp"
#include "Fella.hpp"
class PA9_TestCase
{
public:
    PA9_TestCase() {

    }

    ~PA9_TestCase() {

    }

    void MovementTest() {

        sf::Vector2f testPlayerVector(50, 50);
        sf::Vector2f testPlayerPosition(0, 0);

        PlayerCharacter testPlayer(testPlayerVector,
            testPlayerPosition,
            sf::Color::White);

        testPlayer.move(5, 0);
        testPlayer.move(5, 4);
        testPlayer.move(-3, 2);
        testPlayer.move(1, -1);

        if (testPlayer.getPosition() == sf::Vector2f(8, 5)) {
            printf("Movement functions are working\n");
        }
        else {
            printf("Movement funcitons are borked up\n");
        }
    }

    void enemyTest() {

        sf::Vector2f testPlayerVector(50, 50);
        sf::Vector2f testPlayerPosition(100, 100);

        PlayerCharacter testPlayer(testPlayerVector,
            testPlayerPosition,
            sf::Color::White);

        sf::Vector2f testEnemyVector(50, 50);
        sf::Vector2f testEnemyPosition(0, 0);
        int num = 1;

        SillyFella testEnemy(testEnemyVector,
            testEnemyPosition,
            sf::Color::White,
            1,
            1);
        for (int i = 0; i < 20; i++) {
            testEnemy.enemyMovement(testPlayer);
        }

        if (testEnemy.getPosition() != sf::Vector2f(0, 0)) {
            printf("Enemy has moved\n");
        }
        else {
            printf("Enemy has not moved (gone braindead)\n");
        }
    }
    void frameTest(int frameCount)
    {
        int failure = 0;
        if (frameCount == 150) {
            ++failure;
        }
    }
    void deathTest(int health)
    {
        bool death;
        if (health <= 0) {
            death == true;
        }
    }
    void hurtTest(int health)
    {
        bool hurt;
        if (health != 3) {
            hurt == true;
        }
    }

};
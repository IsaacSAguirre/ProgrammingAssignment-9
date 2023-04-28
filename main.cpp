
#include <SFML/Graphics.hpp>
#include "player.h"
#include "bullet.h"
#include "targetReticle.hpp"
#include "Fella.hpp"
#include <math.h>
using namespace sf;
using namespace std;
int main()
{
    //Window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Zombie Game 2D");
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);

    //Player
    Vector2f playerVec(50.f, 50.f);
    int i = 0;
    
    PlayerCharacter p1( playerVec, Vector2f(window.getPosition().x/2 , window.getPosition().y /2), Color::White);
    /*p1.setFillColor(sf::Color::White);*/
    Color c = Color::Yellow;
    
    //Enemy
    Vector2f eSize(25.f, 25.f);
    Vector2f e1Pos(200, 0), e2Pos(400, 100), e3Pos(600, 0), e4Pos(800, 0), e5Pos(0, 300), e6Pos(0, 700), e7Pos(1000, 300), e8Pos(1000, 700), e9Pos(200, 1000), e10Pos(400, 1000), e11Pos(600, 1000), e12Pos(800, 1000);
    SillyFella e1(eSize, e1Pos, c, i), e2(eSize, e2Pos, c, i), e3(eSize, e3Pos, c, i), e4(eSize, e4Pos, c, i), e5(eSize, e5Pos, c, i), e6(eSize, e6Pos, c, i), e7(eSize, e7Pos, c, i), e8(eSize, e8Pos, c, i), e9(eSize, e9Pos, c, i), e10(eSize, e10Pos, c, i), e11(eSize, e11Pos, c, i), e12(eSize, e12Pos, c, i);
   
    
    
    //Bullet
    Vector2f pPos;
    Vector2f mPos;
    Vector2f aimDir;
    Vector2f aimDirNorm;
    Bullet b1;
    vector<Bullet> bullets;

    TargetReticle t(10.f, mPos, sf::Color::Red);
    bullets.push_back(Bullet(b1));

    int bulletCooldown = 0;
    

    //Temp Variables 
    Vector2f hell(5000, 5000);

    int frameCount = 0;
    int roundDifficulty = 1;



    while (window.isOpen())
    {
        //PLAYER INPUT SCRIPT
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        p1.movementFunction();

       
        //BULLET MATH
        pPos = Vector2f(p1.getPosition().x + p1.getRadius(),
        p1.getPosition().y + p1.getRadius());
        mPos = Vector2f(Mouse::getPosition(window));
        aimDir = mPos - pPos;
        aimDirNorm = Vector2f(aimDir.x / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)), aimDir.y / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));


        
        //ENEMY INFORMATION
        e1.enemyMovement(p1);
        e2.enemyMovement(p1);
        e3.enemyMovement(p1);
        e4.enemyMovement(p1);
        e5.enemyMovement(p1);
        e6.enemyMovement(p1);
        e7.enemyMovement(p1);
        e8.enemyMovement(p1);
        e9.enemyMovement(p1);
        e10.enemyMovement(p1);
        e11.enemyMovement(p1);
        e12.enemyMovement(p1);

        //If enemy gets player
        if (e1.getGlobalBounds().intersects(p1.getGlobalBounds()) || e2.getGlobalBounds().intersects(p1.getGlobalBounds()) || e3.getGlobalBounds().intersects(p1.getGlobalBounds()) || e4.getGlobalBounds().intersects(p1.getGlobalBounds()) || e5.getGlobalBounds().intersects(p1.getGlobalBounds()) || e6.getGlobalBounds().intersects(p1.getGlobalBounds()) || e7.getGlobalBounds().intersects(p1.getGlobalBounds()) || e8.getGlobalBounds().intersects(p1.getGlobalBounds()) || e9.getGlobalBounds().intersects(p1.getGlobalBounds()) || e10.getGlobalBounds().intersects(p1.getGlobalBounds()) || e11.getGlobalBounds().intersects(p1.getGlobalBounds()) || e12.getGlobalBounds().intersects(p1.getGlobalBounds())) {
            window.close();
        }



        //Round Starter
        if (frameCount >= 100) { //if round timer is done
            switch (roundDifficulty) {
            case 1:
                e1.setHealth(3);
                e1.setPosition(200, 0);
                frameCount = 0;
                ++roundDifficulty;
                break;
            case 2:
                e1.setHealth(3);
                e2.setHealth(3);
                e1.setPosition(200, 0);
                e2.setPosition(400, 100);
                frameCount = 0;
                ++roundDifficulty;
                break;
            case 3:
                e1.setHealth(3);
                e2.setHealth(3);
                e3.setHealth(3);
                e1.setPosition(200, 0);
                e2.setPosition(400, 100);
                e3.setPosition(600, 0);
                frameCount = 0;
                ++roundDifficulty;
                break;
            case 4:
                e1.setHealth(3);
                e2.setHealth(3); 
                e3.setHealth(3);
                e4.setHealth(3);
                e1.setPosition(200, 0);
                e2.setPosition(400, 100);
                e3.setPosition(600, 0);
                e4.setPosition(800, 0);
                frameCount = 0;
                ++roundDifficulty;
                break;
            case 5:
                e1.setHealth(3);
                e2.setHealth(3);
                e3.setHealth(3);
                e4.setHealth(3);
                e5.setHealth(3);
                e1.setPosition(200, 0);
                e2.setPosition(400, 100);
                e3.setPosition(600, 0);
                e4.setPosition(800, 0);
                e5.setPosition(0, 300);
                frameCount = 0;
                ++roundDifficulty;
                break;
            case 6:
                e1.setHealth(3);
                e2.setHealth(3);
                e3.setHealth(3);
                e4.setHealth(3);
                e5.setHealth(3);
                e6.setHealth(3);
                e1.setPosition(200, 0);
                e2.setPosition(400, 100);
                e3.setPosition(600, 0);
                e4.setPosition(800, 0);
                e5.setPosition(0, 300);
                e6.setPosition(0, 700);
                frameCount = 0;
                ++roundDifficulty;
                break;
            case 7:
                e1.setHealth(3);
                e2.setHealth(3);
                e3.setHealth(3);
                e4.setHealth(3);
                e5.setHealth(3);
                e6.setHealth(3);
                e7.setHealth(3);
                e1.setPosition(200, 0);
                e2.setPosition(400, 100);
                e3.setPosition(600, 0);
                e4.setPosition(800, 0);
                e5.setPosition(0, 300);
                e6.setPosition(0, 700);
                e7.setPosition(1000, 300);
                frameCount = 0;
                ++roundDifficulty;
                break;
            case 8:
                e1.setHealth(3);
                e2.setHealth(3);
                e3.setHealth(3);
                e4.setHealth(3);
                e5.setHealth(3);
                e6.setHealth(3);
                e7.setHealth(3);
                e8.setHealth(3);
                e1.setPosition(200, 0);
                e2.setPosition(400, 100);
                e3.setPosition(600, 0);
                e4.setPosition(800, 0);
                e5.setPosition(0, 300);
                e6.setPosition(0, 700);
                e7.setPosition(1000, 300);
                e8.setPosition(1000, 700);
                frameCount = 0;
                ++roundDifficulty;
                break;
            case 9:
                e1.setHealth(3);
                e2.setHealth(3);
                e3.setHealth(3);
                e4.setHealth(3);
                e5.setHealth(3);
                e6.setHealth(3);
                e7.setHealth(3);
                e8.setHealth(3);
                e9.setHealth(3);
                e1.setPosition(200, 0);
                e2.setPosition(400, 100);
                e3.setPosition(600, 0);
                e4.setPosition(800, 0);
                e5.setPosition(0, 300);
                e6.setPosition(0, 700);
                e7.setPosition(1000, 300);
                e8.setPosition(1000, 700);
                e9.setPosition(200, 1000);
                frameCount = 0;
                ++roundDifficulty;
                break;
            case 10:
                e1.setHealth(3);
                e2.setHealth(3);
                e3.setHealth(3);
                e4.setHealth(3);
                e5.setHealth(3);
                e6.setHealth(3);
                e7.setHealth(3);
                e8.setHealth(3);
                e9.setHealth(3);
                e10.setHealth(3);
                e1.setPosition(200, 0);
                e2.setPosition(400, 100);
                e3.setPosition(600, 0);
                e4.setPosition(800, 0);
                e5.setPosition(0, 300);
                e6.setPosition(0, 700);
                e7.setPosition(1000, 300);
                e8.setPosition(1000, 700);
                e9.setPosition(200, 1000);
                e10.setPosition(400, 1000);
                frameCount = 0;
                ++roundDifficulty;
                break;
            case 11:
                e1.setHealth(3);
                e2.setHealth(3);
                e3.setHealth(3);
                e4.setHealth(3);
                e5.setHealth(3);
                e6.setHealth(3);
                e7.setHealth(3);
                e8.setHealth(3);
                e9.setHealth(3);
                e10.setHealth(3);
                e11.setHealth(3);
                e1.setPosition(200, 0);
                e2.setPosition(400, 100);
                e3.setPosition(600, 0);
                e4.setPosition(800, 0);
                e5.setPosition(0, 300);
                e6.setPosition(0, 700);
                e7.setPosition(1000, 300);
                e8.setPosition(1000, 700);
                e9.setPosition(200, 1000);
                e10.setPosition(400, 1000);
                e11.setPosition(600, 1000);
                frameCount = 0;
                ++roundDifficulty;
                break;
            Default:
                e1.setHealth(3 + roundDifficulty - 12);
                e2.setHealth(3 + roundDifficulty - 12);
                e3.setHealth(3 + roundDifficulty - 12);
                e4.setHealth(3 + roundDifficulty - 12);
                e5.setHealth(3 + roundDifficulty - 12);
                e6.setHealth(3 + roundDifficulty - 12);
                e7.setHealth(3 + roundDifficulty - 12);
                e8.setHealth(3 + roundDifficulty - 12);
                e9.setHealth(3 + roundDifficulty - 12);
                e10.setHealth(3 + roundDifficulty - 12);
                e11.setHealth(3 + roundDifficulty - 12);
                e12.setHealth(3 + roundDifficulty - 12);

                e1.setPosition(200, 0);
                e2.setPosition(400, 100);
                e3.setPosition(600, 0);
                e4.setPosition(800, 0);
                e5.setPosition(0, 300);
                e6.setPosition(0, 700);
                e7.setPosition(1000, 300);
                e8.setPosition(1000, 700);
                e9.setPosition(200, 1000);
                e10.setPosition(400, 1000);
                e11.setPosition(600, 1000);
                e12.setPosition(800, 1000);


                frameCount = 0;
                ++roundDifficulty;
                break;
            }
        }
        

  

        //If enemy is dead send them off screen
        if (e1.getHealth() <= 0) {
            e1.setPosition(hell);
        }
        if (e2.getHealth() <= 0) {
            e2.setPosition(hell);
        }
        if (e3.getHealth() <= 0) {
            e3.setPosition(hell);
        }
        if (e4.getHealth() <= 0) {
            e4.setPosition(hell);
        }
        if (e5.getHealth() <= 0) {
            e5.setPosition(hell);
        }
        if (e6.getHealth() <= 0) {
            e6.setPosition(hell);
        }
        if (e7.getHealth() <= 0) {
            e7.setPosition(hell);
        }
        if (e8.getHealth() <= 0) {
            e8.setPosition(hell);
        }
        if (e9.getHealth() <= 0) {
            e9.setPosition(hell);
        }
        if (e10.getHealth() <= 0) {
            e10.setPosition(hell);
        }
        if (e11.getHealth() <= 0) {
            e11.setPosition(hell);
        }
        if (e12.getHealth() <= 0) {
            e12.setPosition(hell);
        }


        
        if (e1.getHealth() <= 0 && e2.getHealth() <= 0 && e3.getHealth() <= 0 && e4.getHealth() <= 0 && e5.getHealth() <= 0 && e6.getHealth() <= 0 && e7.getHealth() <= 0 && e8.getHealth() <= 0 && e9.getHealth() <= 0 && e10.getHealth() <= 0 && e11.getHealth() <= 0 && e12.getHealth() <= 0) { //starts timer for next wrong when there are no enemies
            ++frameCount;
        }




        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (bulletCooldown > 20) {
                bulletCooldown = 0;
                b1.bullet.setPosition(pPos);
                b1.velocity = aimDirNorm * b1.speed;
                bullets.push_back(Bullet(b1));
            }
        }
        for (size_t i = 0; i < bullets.size(); i++)
        {
            bullets[i].bullet.move(bullets[i].velocity);
            if (bullets[i].bullet.getPosition().x < 0 || bullets[i].bullet.getPosition().x > window.getSize().x ||
                bullets[i].bullet.getPosition().y < 0 || bullets[i].bullet.getPosition().x > window.getSize().x)
            {
                bullets.erase(bullets.begin() + i);
            }
            else {
                if (bullets[i].bullet.getGlobalBounds().intersects(e1.getGlobalBounds())) {
                    e1.damage();
                    bullets.erase(bullets.begin() + i);
                }
                else if (bullets[i].bullet.getGlobalBounds().intersects(e2.getGlobalBounds())) {
                    e2.damage();
                    bullets.erase(bullets.begin() + i);
                }
                else if (bullets[i].bullet.getGlobalBounds().intersects(e3.getGlobalBounds())) {
                    e3.damage();
                    bullets.erase(bullets.begin() + i);
                }
                else if (bullets[i].bullet.getGlobalBounds().intersects(e4.getGlobalBounds())) {
                    e4.damage();
                    bullets.erase(bullets.begin() + i);
                }
                else if (bullets[i].bullet.getGlobalBounds().intersects(e5.getGlobalBounds())) {
                    e5.damage();
                    bullets.erase(bullets.begin() + i);
                }
                else if (bullets[i].bullet.getGlobalBounds().intersects(e6.getGlobalBounds())) {
                    e6.damage();
                    bullets.erase(bullets.begin() + i);
                }
                else if (bullets[i].bullet.getGlobalBounds().intersects(e7.getGlobalBounds())) {
                    e7.damage();
                    bullets.erase(bullets.begin() + i);
                }
                else if (bullets[i].bullet.getGlobalBounds().intersects(e8.getGlobalBounds())) {
                    e8.damage();
                    bullets.erase(bullets.begin() + i);
                }
                else if (bullets[i].bullet.getGlobalBounds().intersects(e9.getGlobalBounds())) {
                    e9.damage();
                    bullets.erase(bullets.begin() + i);
                }
                else if (bullets[i].bullet.getGlobalBounds().intersects(e10.getGlobalBounds())) {
                    e10.damage();
                    bullets.erase(bullets.begin() + i);
                }
                else if (bullets[i].bullet.getGlobalBounds().intersects(e11.getGlobalBounds())) {
                    e11.damage();
                    bullets.erase(bullets.begin() + i);
                }
                else if (bullets[i].bullet.getGlobalBounds().intersects(e12.getGlobalBounds())) {
                    e12.damage();
                    bullets.erase(bullets.begin() + i);
                }
            }
        }
        t.mouseLockOn(window);
        ++bulletCooldown;




        //RENDER GAME
        window.clear(); //OPEN
        window.draw(p1);
        window.draw(t);
        
        window.draw(e1);
        window.draw(e2);
        window.draw(e3);
        window.draw(e4);
        window.draw(e5);
        window.draw(e6);
        window.draw(e7);
        window.draw(e8);
        window.draw(e9);
        window.draw(e10);
        window.draw(e11);
        window.draw(e12);

        for (size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i].bullet);
        }

        window.display(); //CLOSE
        
    }

    return 0;
}

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
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Zombie Game 2D");
    window.setFramerateLimit(60);
    Vector2f playerVec(50.f, 50.f), enemyVec(25.f,25.f), enemyVec2(200,0);
    int i = 1;
    
    PlayerCharacter p1( playerVec, Vector2f(window.getPosition().x/2 , window.getPosition().y /2), Color::White);
    /*p1.setFillColor(sf::Color::White);*/
    Color c = Color::Yellow;
    SillyFella e1(enemyVec, enemyVec2, c, i, i);
    Vector2f pPos;
    Vector2f mPos;
    Vector2f aimDir;
    Vector2f aimDirNorm;
    Bullet b1;
    vector<Bullet> bullets;

  

    int frameCount = 0;
    int enemyAlive = 0;
    int roundDifficulty = 1;
    int tempHealthAdd = 0;
   
    TargetReticle t(10.f, mPos, sf::Color::Red);

    bullets.push_back(Bullet(b1));

    int bulletCooldown = 0;
        
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
       
        pPos = Vector2f(p1.getPosition().x + p1.getRadius(),
        p1.getPosition().y + p1.getRadius());
        mPos = Vector2f(Mouse::getPosition(window));
        aimDir = mPos - pPos;
        aimDirNorm = Vector2f(aimDir.x / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)), aimDir.y / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));
        p1.movementFunction();
        e1.enemyMovement(p1);


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
            
        }

        //switch (roundDifficulty) {
        //case 1:
        //    init enemy(Pos1); //use set position
        //    break;
        //case 2:
        //    init enemy(Pos1);
        //    init enemy(Pos1);
        //    break;
        //case 3:
        //    //init enemy(Pos1) x3
        //    break;
        //case 4:
        //    //init enemy(Pos1) x4
        //    break;
        //case 5:
        //    //init enemy(Pos1) x5
        //    break;
        //case 6:
        //    //init enemy(Pos1) x6
        //    break;
        //case 7:
        //    //init enemy(Pos1) x7
        //    break;
        //case 8:
        //    //init enemy(Pos1) x8
        //    break;
        //case 9:
        //    //init enemy(Pos1) x9
        //    break;
        //case 10:
        //    //init enemy(Pos1) x10
        //    break;
        //case 11:
        //    //init enemy(Pos1) x11
        //    break;
        //Default:
        //    //init enemy(poxX, posY, tempHealthAdd) x12
        //    ++tempHealthAdd;
        //    break;
        //}

        if (enemyAlive == 0) { //starts timer for next wrong when there are no enemies
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
        }
        t.mouseLockOn(window);
        ++bulletCooldown;

        window.clear();
        window.draw(p1);
        window.draw(t);
        window.draw(e1);
        for (size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i].bullet);
        }

        window.display();
        
    }

    return 0;
}
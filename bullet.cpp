#include "bullet.h"
using namespace std;
//void Bullet::shoot(Bullet b, Vector2f playerPos, Vector2f aim, vector<Bullet> c, RenderWindow &w)
//{
//	
//	if (Mouse::isButtonPressed(Mouse::Left))
//	{
//		
//		b.bullet.setPosition(playerPos);
//		b.velocity = aim * b.speed;
//		c.push_back(Bullet(b));
//	}
//	for (size_t i = 0; i < c.size(); i++)
//	{
//		c[i].bullet.move(c[i].velocity);
//		if (c[i].bullet.getPosition().x < 0 || c[i].bullet.getPosition().x > w.getSize().x ||
//			c[i].bullet.getPosition().y < 0 || c[i].bullet.getPosition().x > w.getSize().x)
//		{
//			c.erase(c.begin() + i);
//		}
//	}
//}
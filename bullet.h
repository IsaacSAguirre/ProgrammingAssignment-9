#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;
class Bullet
{
public:
	CircleShape bullet;
	Vector2f velocity;
	float speed;
	Bullet(float radius = 5.f) : velocity(1000.f, 1000.f), speed(15.f)
	{
		this->bullet.setRadius(radius);
		this->bullet.setFillColor(Color::Green);
	}
	
		
private:
	

};
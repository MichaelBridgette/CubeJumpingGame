#pragma once
#include<SFML\Graphics.hpp>
#include<iostream>
#include <GL/glew.h>
#include <GL/wglew.h>

class player {
public:
	player();
	void move();
	void draw(sf::RenderWindow &window);

	sf::Vector3f v1 = sf::Vector3f(-0.05f, -0.05f, 0.05f);
	sf::Vector3f v2 = sf::Vector3f(-0.05f, 0.05f, 0.05f);
	sf::Vector3f v3 = sf::Vector3f(0.05f, 0.05f, 0.05f);
	sf::Vector3f v4 = sf::Vector3f(0.05f, -0.05f, 0.05f);
	sf::Vector3f v5 = sf::Vector3f(-0.05f, -0.05f, -0.05f);
	sf::Vector3f v6 = sf::Vector3f(-0.05f, 0.05f, -0.05f);
	sf::Vector3f v7 = sf::Vector3f(0.05f, 0.05f, -0.05f);
	sf::Vector3f v8 = sf::Vector3f(0.05f, -0.05f, -0.05f);




private:
	sf::Vector2f m_position;
	sf::Vector3f m_velocity;
	bool isJump=false;


	sf::Vector3f m_right= sf::Vector3f(0.001,0,0);
	sf::Vector3f m_left = sf::Vector3f(-0.001, 0, 0);

};
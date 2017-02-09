#pragma once

#include<SFML\Graphics.hpp>


class Obstacle {
public:
	Obstacle();
	~Obstacle();
	void Update();

	sf::Vector3f v1 = sf::Vector3f(-3.05f, -3.05f, 3.05f);
	sf::Vector3f v2 = sf::Vector3f(-3.05f, 3.05f, 3.05f);
	sf::Vector3f v3 = sf::Vector3f(3.05f, 3.05f, 3.05f);
	sf::Vector3f v4 = sf::Vector3f(3.05f, -3.05f, 3.05f);
	sf::Vector3f v5 = sf::Vector3f(-3.05f, -3.05f, -3.05f);
	sf::Vector3f v6 = sf::Vector3f(-3.05f, 3.05f, -3.05f);
	sf::Vector3f v7 = sf::Vector3f(3.05f, 3.05f, -3.05f);
	sf::Vector3f v8 = sf::Vector3f(3.05f, -3.05f, -3.05f);


private:
	

};
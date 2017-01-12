#pragma once

#include<SFML\Graphics.hpp>
#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include"player.h"
class game {
public:
	game();
	~game();
	void run();

private:
	sf::RenderWindow window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();
	
	player m_player1;


	/*sf::Vector3f v1 = sf::Vector3f(-0.05f, -0.05f, 0.05f);
	sf::Vector3f v2 = sf::Vector3f(-0.05f, 0.05f, 0.05f);
	sf::Vector3f v3 = sf::Vector3f(0.05f, 0.05f, 0.05f);
	sf::Vector3f v4 = sf::Vector3f(0.05f, -0.05f, 0.05f);
	sf::Vector3f v5 = sf::Vector3f(-0.05f, -0.05f, -0.05f);
	sf::Vector3f v6 = sf::Vector3f(-0.05f, 0.05f, -0.05f);
	sf::Vector3f v7 = sf::Vector3f(0.05f, 0.05f, -0.05f);
	sf::Vector3f v8 = sf::Vector3f(0.05f, -0.05f, -0.05f);*/


};
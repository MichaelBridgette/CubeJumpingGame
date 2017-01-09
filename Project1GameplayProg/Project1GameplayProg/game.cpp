#include "Game.h"

static bool flip;

game::game() : window(sf::VideoMode(800, 600), "SWAGDREW IS DEAD LOL")
{
}

game::~game() {}

void game::run()
{

	initialize();

	sf::Event event;

	while (isRunning) {

		

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}


void game::initialize()
{
	isRunning = true;

	
}

void game::update()
{
	

}
	

void game::render()
{
	
	window.display();

}

void game::unload()
{
}

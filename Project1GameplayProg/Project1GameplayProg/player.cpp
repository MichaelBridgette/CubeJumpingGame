#include"player.h"



player::player()
{
	m_position = sf::Vector2f(20, 250);
	m_velocity = sf::Vector3f(0, 0,0);
	
}
void player::draw(sf::RenderWindow &window)
{
	
}
void player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		
		//m_position.x += 0.1;

		v1 += m_right;
		v2 += m_right;
		v3 += m_right;
		v4 += m_right;
		v5 += m_right;
		v6 += m_right;
		v7 += m_right;
		v8 += m_right;

	}
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		//m_position.x-=0.1;
		v1 += m_left;
		v2 += m_left;
		v3 += m_left;
		v4 += m_left;
		v5 += m_left;
		v6 += m_left;
		v7 += m_left;
		v8 += m_left;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&isJump==false)
	{
		m_velocity.y = 0.001;
	}
	

	if (m_velocity.y != 0)
	{
		v1 += m_velocity;
		v2 += m_velocity;
		v3 += m_velocity;
		v4 += m_velocity;
		v5 += m_velocity;
		v6 += m_velocity;
		v7 += m_velocity;
		v8 += m_velocity;
	}

	if (v1.y > 0.25)
	{
		m_velocity.y -=0.002;
		isJump = true;
		
	}
	if (v4.y < -0.05)
	{
		m_velocity.y = 0;
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && v4.y <-0.05)
		{
			isJump = false;
		}
	}
}
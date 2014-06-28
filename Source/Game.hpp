#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

class Game
{
public:

	Game();

	void run();

private:

	sf::RenderWindow m_window;
	sf::Event         m_event;
};

#endif // GAME_HPP
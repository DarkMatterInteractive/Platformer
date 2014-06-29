#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <array>
#include "Util.hpp"
#include "SceneNode.hpp"
#include "ResourceManager.hpp"

class Game
{
public:

	Game();

	void run();
	void update( sf::Time dt );

	void loadResources();

	void handleEvents();

private:

	sf::RenderWindow  m_window;
	sf::Event         m_event;

	sf::Clock         m_clock;
	sf::Time          m_unprocessedTime;

	ResourceManager< Texture::ID, sf::Texture > m_textures;
};

#endif // GAME_HPP
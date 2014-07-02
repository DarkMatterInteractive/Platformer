#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <array>
#include "Util.hpp"
#include "SceneNode.hpp"
#include "ResourceManager.hpp"
#include "StateStack.hpp"

class Game
{
public:

	Game();

	void run();
	void update( sf::Time dt );

	void handleEvents();
	
	void loadResources();
	void registerStates();

private:

	sf::RenderWindow  m_window;
	sf::Event         m_event;

	sf::Clock         m_clock;
	sf::Time          m_unprocessedTime;

	TextureManager    m_textures;
	FontManager       m_fonts;
	SoundManager      m_sounds;

	StateStack        m_states;
};

#endif // GAME_HPP
#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <memory>
#include <map>
#include <iostream>
#include <assert.h>

namespace Texture
{
	enum ID
	{
		MainMenuScreen,
		PlayScreen,
		OptionsScreen,
		CreditsScreen
	};
};

namespace Font
{
	enum ID
	{

	};
};

namespace Sound
{
	enum ID
	{

	};
};

template< typename ID, class Resource >
class ResourceManager
{
public:

	ResourceManager();
    
	           void loadResource( ID id, const std::string& file );

	      Resource& getResource( ID id );
	const Resource& getResource( ID ) const;

private:

	std::map< ID, std::unique_ptr< Resource > > m_resources;
};

typedef ResourceManager< Texture::ID, sf::Texture >   TextureManager;
typedef ResourceManager< Font::ID, sf::Font >         FontManager;
typedef ResourceManager< Sound::ID, sf::SoundBuffer > SoundManager;

#include "ResourceManager.inl"

#endif // RESOURCE_MANAGER_HPP
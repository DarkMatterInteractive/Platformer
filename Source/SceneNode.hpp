#ifndef SCENE_NODE_HPP
#define SCENE_NODE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <assert.h>

class SceneNode : public sf::Drawable, public sf::Transformable
{
public:

	typedef std::unique_ptr< SceneNode > NodePtr;

	SceneNode() {}
	SceneNode( const sf::Texture& texture );

	        void               update( sf::Time dt );
	virtual void               updateCurrent( sf::Time dt );
	        void               updateChildren( sf::Time dt );

			void               attachChild( NodePtr child );
	        SceneNode::NodePtr detachChild( const SceneNode& node );

protected:

	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;
	virtual void drawCurrent( sf::RenderTarget& target, sf::RenderStates states ) const;
	virtual void drawChildren( sf::RenderTarget& target, sf::RenderStates states ) const;

	sf::Sprite             m_sprite;

	SceneNode*             m_parent;

	std::vector< NodePtr > m_children;
};

#endif // SCENE_NODE_HPP
#include "SceneNode.hpp"

SceneNode::SceneNode( const sf::Texture& texture )
	: m_parent( nullptr )
{
	m_sprite.setTexture( texture );

	sf::FloatRect bounds = m_sprite.getLocalBounds();

	m_sprite.setOrigin( bounds.width / 2, bounds.height / 2 );
}

void SceneNode::update( sf::Time dt )
{
	updateCurrent( dt );
	updateChildren( dt );
}

void SceneNode::updateCurrent( sf::Time dt )
{
	// Leave Blank
	// Inheriting classes override this
}

void SceneNode::updateChildren( sf::Time dt )
{
	for ( NodePtr& p : m_children )
	{
		p -> update( dt );
	}
}

void SceneNode::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	states.transform *= getTransform();

	drawCurrent( target, states );
	drawChildren( target, states );
}

void SceneNode::drawCurrent( sf::RenderTarget& target, sf::RenderStates states ) const
{
	// Leave blank
	// Inheriting classes override this

	target.draw( m_sprite, states );
}

void SceneNode::drawChildren( sf::RenderTarget& target, sf::RenderStates states ) const
{
	for ( const NodePtr& p : m_children )
	{
		p -> draw( target, states );
	}
}

void SceneNode::attachChild( NodePtr child )
{
	child -> m_parent = this;

	m_children.push_back( std::move( child ) );
}

SceneNode::NodePtr SceneNode::detachChild( const SceneNode& node )
{
	auto found = std::find_if( m_children.begin(), m_children.end(), [ & ] ( NodePtr& p ) -> bool { return p.get() == &node; } );

	assert( found != m_children.end() );

	NodePtr result = std::move( *found );

	result -> m_parent = nullptr;

	m_children.erase( found );

	return result;
}
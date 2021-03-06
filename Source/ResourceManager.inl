
template< typename ID, class Resource >
ResourceManager< ID, Resource >::ResourceManager()
{

}

template< typename ID, class Resource >
void ResourceManager< ID, Resource >::loadResource( ID id, const std::string& file )
{
	std::unique_ptr< Resource > resource( new Resource() );

	if ( !resource -> loadFromFile( file ) )
	{
		std::cout << "Failed to load resource: " << file << std::endl;
	}

	auto inserted = m_resources.insert( std::make_pair( id, std::move( resource ) ) );

	assert( inserted.second );
}

template < typename ID, class Resource >
std::unique_ptr< Resource > ResourceManager< ID, Resource >::removeResource( ID id )
{
	auto found = m_resources.find( id );

	assert( found != m_resources.end() );

	std::unique_ptr< Resource > resource = std::move( found -> second );

	m_resources.erase( found );

	return resource;
}

template< typename ID, class Resource >
Resource& ResourceManager< ID, Resource >::getResource( ID id )
{
	auto iter = m_resources.find( id );

	return *iter -> second;
}

template< typename ID, class Resource >
const Resource& ResourceManager< ID, Resource >::getResource( ID id ) const
{
	auto iter = m_resources.find( id );

	return *iter -> second;
}
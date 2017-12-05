#include "Entity.h"


Entity::Entity()
{
    body.setSize(sf::Vector2f(50.0f, 50.0f));
    body.setOrigin(body.getSize() / 2.0f);
}

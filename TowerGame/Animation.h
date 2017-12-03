#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>


class Animation
{
public:
    Animation(sf::Texture* texture, sf::Vector2i imageCount, 
	      float switchTime);
    Animation();
    ~Animation();
    void Create(sf::Texture* texture, sf::Vector2i tImageCount, float tSwitchTime);
    void Update(int row, float deltaTime);
    sf::IntRect xyRect;

private:
    
    float totalTime;
    float switchTime;
    sf::Vector2i imageCount;
    sf::Vector2i currentImage;
    bool created = false;
};
#endif

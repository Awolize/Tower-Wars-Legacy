#include "Animation.h"


Animation::Animation(sf::Texture* texture, sf::Vector2i imageCount,
		     float switchTime) :
    imageCount{ imageCount }, switchTime{ switchTime }, totalTime{ 0.0f },
    currentImage{ 0, 0 }
{
    xyRect.width = texture->getSize().x / imageCount.x;
    xyRect.height = texture->getSize().y / imageCount.y;
    created = true;
}

Animation::Animation()
{
}

void Animation::Create(sf::Texture* texture, sf::Vector2i tImageCount, float tSwitchTime)
{
    imageCount = tImageCount;
    switchTime = tSwitchTime; 
    totalTime = 0.0f;
    currentImage = sf::Vector2i(0, 0);
    created = true;
    xyRect.width = texture->getSize().x / imageCount.x;
    xyRect.height = texture->getSize().y / imageCount.y;
}

Animation::~Animation()
{
}

void Animation::Update(int row, float deltaTime)
{
    if (created)
    {
	currentImage.y = row;
	totalTime = totalTime + deltaTime;

	if (totalTime >= switchTime)
	{
	    totalTime = totalTime - switchTime;
	    currentImage.x++;
	    if (currentImage.x >= imageCount.x)
		currentImage.x = 0;
	}

	xyRect.top = currentImage.y * xyRect.height;
	xyRect.left = currentImage.x * xyRect.width;
    }
}

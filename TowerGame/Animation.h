#include <SFML/Graphics.hpp>
#pragma once

class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2i imageCount, float switchTime);
	~Animation();

	void Update(int row, float deltaTime);
	sf::IntRect xyRect;

private:
	float totalTime;
	float switchTime;
	sf::Vector2i imageCount;
	sf::Vector2i currentImage;
};

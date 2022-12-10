#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
private:
	sf::Vector2u imageCount;//count total number of image in the texture
	sf::Vector2u currentImage;//current position of the image in the texture
	float totalTime;
	float switchTime;
	bool paused;
	bool allframes;


public:
	bool isCompleted;
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, bool repeat);
	Animation();
	void update(int row, float deltaTime);
	void updateAllFrames(float deltaTime);
	sf::IntRect uvRect;
	void pause();
	void resume();
	void setWindow(sf::RenderWindow* window);
	void setSwitchTime(float x);

};


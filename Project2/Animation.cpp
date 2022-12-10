#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, bool repeat)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	this->isCompleted = false;
	this->totalTime = 0.0f;
	this->paused = false;
	this->currentImage.x = 0;
	this->currentImage.y = 0;
	if (repeat == true) {
		this->uvRect.width = texture->getSize().x / float(imageCount.x);
		this->uvRect.height = 1900.f;
	}
	else {
	this->uvRect.width = texture->getSize().x / float(imageCount.x);
	this->uvRect.height = texture->getSize().y / float(imageCount.y);
	}

}
Animation::Animation()
{
}
void Animation::updateAllFrames(float deltaTime)
{
	if (paused == false) {
		totalTime += deltaTime;
		if (totalTime >= switchTime) {
			totalTime = 0;
			currentImage.x++;
			if (currentImage.x >= imageCount.x) {
				currentImage.x = 0;
				currentImage.y++;
				if (currentImage.y >= imageCount.y) {
					isCompleted = true;
					currentImage.y = imageCount.x;
					currentImage.x = imageCount.y;
					this->pause();
				}
			}
		}
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.top = currentImage.y * uvRect.height;
	}

}
void Animation::update(int row, float deltaTime)
{
	if (paused == false) {
		currentImage.y = row;
		totalTime += deltaTime;
		if (totalTime >= switchTime) {
			totalTime = 0;
			currentImage.x++;
			if (currentImage.x >= imageCount.x) {
				currentImage.x = 0;
			}
		}
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.top = currentImage.y * uvRect.height;
	}
	
}

void Animation::pause()
{
	this->paused = true;
}

void Animation::resume()
{
	this->paused = false;
}


void Animation::setSwitchTime(float x)
{
	switchTime = x;
}

#include "Background.h"

void Background::initBackground(sf::RenderTarget& target)
{
	this->firstStage.setTexture(this->firstStageBackground);
	this->firstStage.setPosition(0.0f, 0.0f);
	this->firstStage.setScale(target.getSize().x/1024.f, target.getSize().y / 576.f);


	this->secondStage.setTexture(this->secondStageBackground);
	this->secondStage.setPosition(0.f, 0.f);
	this->secondStage.setScale(target.getSize().x / 426.f, target.getSize().y / 240.f);

	this->sprite.setTexture(this->texture);
	this->sprite.setScale(2.f, 2.f);
	//this->wallLeft.setTexture(this->wallTexture);
	//this->wallRight.setTexture(this->wallTexture);
	borderLeft.setTexture(this->borderTexture);
	borderRight.setTexture(this->borderTexture2);
	//wallLeft.setPosition(0.f, 0.f);
	//wallLeft.setTextureRect(sf::IntRect(0, 0, target.getSize().x /10, target.getSize().y));
	//wallRight.setTextureRect(sf::IntRect(0, 0, target.getSize().x / 10, target.getSize().y));
	//wallRight.setPosition(target.getSize().x - target.getSize().x / static_cast<float>(10), 0.f);
	//borderLeft.setTextureRect(sf::IntRect(0, 0, 50.f, target.getSize().y));
	borderLeft.setPosition(0.f, 0.f);
	borderLeft.setScale(3.f, 3.f);
	//borderRight.setTextureRect(sf::IntRect(175.f, 0, 50.f, target.getSize().y));
	borderRight.setScale(3.f, 3.f);
	borderRight.setPosition(target.getSize().x - ((borderTexture2.getSize().x/ 96.f)*borderRight.getScale().x), 0.f);
}

void Background::initTexture(sf::RenderTarget& target)
{
	if (!this->texture.loadFromFile("Resources/Images/background1.png"))
		std::cout << "Problem while loading sprite";
	if (!this->firstStageBackground.loadFromFile("Resources/Images/image1.png"))
		std::cout << "Problem while loading background";
	if (!this->finalStageTexture.loadFromFile("Resources/Images/space.png"))
		std::cout << "Problem while loading background";
	//if (!this->wallTexture.loadFromFile("Resources/Images/wall.png"))
		//std::cout << "Problem while loading sprite";
	//wallTexture.setRepeated(true);
	if (!this->borderTexture.loadFromFile("Resources/Images/BorderL.png"))
		std::cout << "Problem while loading border animation";
	borderTexture.setRepeated(true);
	if (!this->borderTexture2.loadFromFile("Resources/Images/borderR.png"))
		std::cout << "Problem while loading border2";
	borderTexture2.setRepeated(true);

	if (!this->secondStageBackground.loadFromFile("Resources/Images/earth.png"))
		std::cout << "Problem while loading image!";

	this->secondStageAnimation = new Animation(&secondStageBackground, sf::Vector2u(9,9), 0.05f, false);
	this->secondStageAnimation->pause();
	this->firstStageAnimation = new Animation(&firstStageBackground, sf::Vector2u(11, 8), 0.05f, false);
	this->borderAnimation = new Animation(&borderTexture, sf::Vector2u(96, 1), 0.02f, true);
	this->borderLeft.setTextureRect(this->borderAnimation->uvRect);
	this->borderAnimation2 = new Animation(&borderTexture2, sf::Vector2u(96, 1), 0.02f, true);
	this->borderRight.setTextureRect(this->borderAnimation2->uvRect);

	this->finalStageBackground.setTexture(finalStageTexture);
	this->finalStageBackground.setScale(target.getSize().x/ 426.f, target.getSize().y/ 240.f);
	this->finalStageBackground.setPosition(0.f,- static_cast<int>(target.getSize().y));
	finalBackAnimation = Animation(&finalStageTexture, sf::Vector2u(5, 1), 0.5, false);
	flashOpacity = 0;
	fadeComplete = false;
	fadeMoonComplete = false;
	fillOpacity = true;
	this->flash.setFillColor(sf::Color(255,255,255,flashOpacity));
	this->flash.setPosition(0.f, 0.f);
	this->flash.setSize(sf::Vector2f(target.getSize().x, target.getSize().y));
}

Background::Background(sf::RenderTarget& target)
{
	this->initTexture(target);
	this->initBackground(target);
}


Background::~Background()
{
}

void Background::updateFlash(sf::RenderTarget& window)
{
	if (flashOpacity < 255 && fillOpacity) {
	flashOpacity = flashOpacity + 5;
	this->flash.setFillColor(sf::Color(255, 255, 255, flashOpacity));
	}
	else {
		fillOpacity = false;
	}
	if (flashOpacity > 0 && !fillOpacity) {
		flashOpacity = flashOpacity - 5;
		this->flash.setFillColor(sf::Color(255, 255, 255, flashOpacity));
	}
	else if(!fillOpacity) {
		fadeComplete = true;
		std::cout << "Finished!"; 
	}
}

void Background::renderFlash(sf::RenderTarget& window)
{

	window.draw(this->finalStageBackground);
	window.draw(this->flash);
}

void Background::update()
{
	this->deltatime = clock.restart().asSeconds();
	//first stage animation
	if (!fadeComplete) {
		if (!this->firstStageAnimation->isCompleted) {
			this->firstStageAnimation->updateAllFrames(deltatime);
			this->firstStage.setTextureRect(this->firstStageAnimation->uvRect);
		}
		else
		{
			this->borderAnimation->update(0, deltatime);
			this->borderLeft.setTextureRect(this->borderAnimation->uvRect);
			this->borderAnimation2->update(0, deltatime);
			this->borderRight.setTextureRect(this->borderAnimation2->uvRect);
		}
	}
	else {
		//moon stage!!
		if (!this->secondStageAnimation->isCompleted) {
			this->secondStageAnimation->updateAllFrames(deltatime);
			this->secondStage.setTextureRect(this->secondStageAnimation->uvRect);
		}
		else if (this->finalStageBackground.getPosition().y < 0) {
			this->finalStageBackground.move(0.f, 10.f);
			
		}
		else {
			this->finalBackAnimation.update(0, deltatime);
			this->finalStageBackground.setTextureRect(this->finalBackAnimation.uvRect);
		}
		
	}

}

void Background::spawnMoon(sf::RenderTarget& window)
{
	std::cout << "summoned moon\n\n";
	this->moonTexture.loadFromFile("Resources/Images/moon.png");
	this->moon.setTexture(moonTexture);
	this->moonAnimation = new Animation(&moonTexture, sf::Vector2u(11, 11), 0.1, false);
	this->moon.setTextureRect(this->moonAnimation->uvRect);
	this->moon.setPosition(-400.f, -400.f);
	this->moon.setOrigin(200.f, 200.f);
	fillOpacity = true;
	flashOpacity = 0;

	//final surface moon initilization
	this->moonSurfaceTexture.loadFromFile("Resources/Images/moonlanding.png");
	this->moonSurfaceAnimation = new Animation(&moonSurfaceTexture, sf::Vector2u(12, 1), 0.1, false);
	this->moonSurface.setTexture(moonSurfaceTexture);
	this->moonSurface.setTextureRect(this->moonSurfaceAnimation->uvRect);
	this->moonSurface.setScale(window.getSize().x / 426.f, window.getSize().y / 240.f);
	
}

void Background::updateMoon(sf::RenderTarget& window)
{
	//std::cout << "updating moon";
	this->moonAnimation->updateAllFrames(deltatime);
	this->moonSurfaceAnimation->update(0, deltatime);
	this->moonSurface.setTextureRect(this->moonSurfaceAnimation->uvRect);
	this->moon.setTextureRect(this->moonAnimation->uvRect);
	//move moon towards center
	if (moon.getPosition().x < window.getSize().x / 2.f) 
		moon.move(5.f,0.f);
	if (moon.getPosition().x > window.getSize().x / 2.f)
		moon.move(-5.f, 0.f);
	if (moon.getPosition().y < window.getSize().y / 2.f)
		moon.move(0.f, 5.f);
	if (moon.getPosition().y > window.getSize().y / 2.f)
		moon.move(0.f, -5.f);
	if (moon.getScale().x < 5) {
		moon.setScale(moon.getScale().x + 0.009f, moon.getScale().y + 0.009f);
	}
	else if(!fadeMoonComplete) {
		if (flashOpacity < 255 && fillOpacity) {
			flashOpacity = flashOpacity + 5;
			this->flash.setFillColor(sf::Color(255, 255, 255, flashOpacity));
		}
		else {
			fillOpacity = false;
		}
		if (flashOpacity > 0 && !fillOpacity) {
			flashOpacity = flashOpacity - 5;
			this->flash.setFillColor(sf::Color(255, 255, 255, flashOpacity));
		}
		else if (!fillOpacity) {
			fadeMoonComplete = true;
			std::cout << "Finished!";
		}
	}



}

void Background::renderMoon(sf::RenderTarget& window)
{
	window.draw(this->flash);
	if(!fadeMoonComplete)
	window.draw(this->moon);
	
	if (!fillOpacity)
		window.draw(this->moonSurface);
	window.draw(this->flash);

}

void Background::render(sf::RenderTarget& target, Enemies* enemy)
{
	//render sprite code
	if (!this->firstStageAnimation->isCompleted) {
		target.draw(this->firstStage);
	}
	else if(!fadeComplete) {
		target.draw(this->sprite);
		if (enemy != NULL) {
			enemy->render(target);
		}
		target.draw(this->wallLeft);
		target.draw(this->wallRight);
		target.draw(this->borderLeft);
		target.draw(this->borderRight);	
	}
	else {
		if (!this->secondStageAnimation->isCompleted) {
			target.draw(this->secondStage);
		}
		else  {


			if (this->finalStageBackground.getPosition().y < 0) {
				target.draw(this->secondStage);
			}

			//render final stage!
			target.draw(this->finalStageBackground);
			if (enemy != NULL) {
				enemy->render(target);
			}
		}
		
	}

	
}

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include"Enemies.h"
#include "Animation.h"
class Background
{
	sf::Texture texture;
	sf::Texture wallTexture;
	sf::Sprite wallRight;
	sf::Sprite wallLeft;
	sf::Sprite sprite;
	sf::Texture borderTexture;
	sf::Texture borderTexture2;
	sf::Texture finalStageTexture;

	//final stage!
	sf::Sprite finalStageBackground;
	sf::Texture firstStageBackground;



	Animation finalBackAnimation;

	sf::Texture secondStageBackground;
	sf::Sprite secondStage;


	sf::Sprite firstStage;
	sf::Clock clock;
	float deltatime;

	//flash
	sf::RectangleShape flash;
	int flashOpacity;
	bool fillOpacity;


	//moon
	sf::Texture moonTexture;
	sf::Sprite moon;
	Animation* moonAnimation;

	//final scene
	sf::Texture moonSurfaceTexture;
	sf::Sprite moonSurface;
	Animation* moonSurfaceAnimation;
public:
	bool fadeComplete;
	bool fadeMoonComplete;
	sf::Sprite borderLeft;
	sf::Sprite borderRight;
	Animation* borderAnimation;
	Animation* borderAnimation2;
	Animation* firstStageAnimation;
	Animation* secondStageAnimation;

private:
	void initBackground(sf::RenderTarget& target);
	void initTexture(sf::RenderTarget& target);
	

public:
	Background(sf::RenderTarget& target);
	
	virtual ~Background();

	//flash function()
	void updateFlash(sf::RenderTarget &window);
	void renderFlash(sf::RenderTarget& window);
	//update bakcground
	void update();
	//moon functions
	void spawnMoon(sf::RenderTarget& window);
	void updateMoon(sf::RenderTarget& window);
	void renderMoon(sf::RenderTarget& window);
	//render background
	void render(sf::RenderTarget& target, Enemies* enemy);
	friend class Player;

};


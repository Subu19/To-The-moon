#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include "Background.h"
#include"Enemies.h"
class Player
{

	sf::Texture playerTexture;
	sf::Clock clock;
	float deltatime;
	sf::Vector2f speed;
	float maxVelocity;
	sf::Vector2f velocity;
	bool onHold;
	bool spaceHolded;
	int holdedkey;


	Animation* playerAnimation;
	Background* background;
private:

	void initVeriables();
	void initPlayer(sf::RenderTarget& target);
	void handlePress(int);
	void handleShoot();
	void updateShoot();
	void renderShoot(sf::RenderTarget& target);
	void initBullet();

public:
	int animateRow;
	bool started;
	bool enableShooting;
	bool disableFlight;
	bool stillPlayer;
	sf::Sprite player;
	sf::RectangleShape bullet;
	//bullet array
	std::vector<sf::RectangleShape> bullets;
	float shootTime;
	Player(sf::RenderTarget& target, Background& backPtr);
	void update(Enemies& obs, bool initiated, bool update);
	void render(sf::RenderTarget& target);
	int isFlying();
	int checkCollisionObs(Enemies obs);
	int checkCollisionObs(std::vector<sf::Sprite> obs);
	void changePlayer();
	sf::Vector2f getSpeed();

};


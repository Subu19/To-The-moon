#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
class Enemies
{
	

	sf::Sprite obs;
	sf::Texture stone;
	sf::Texture hill;
	sf::Texture obs3;
	sf::Texture obs4;
	sf::Texture hill5;
	sf::Texture obs5;
	sf::Texture obs6;
	sf::Texture obs7;
	sf::Texture obs8;
	sf::Texture obs9;


	sf::Texture ass1;
	sf::Texture ass2;
	sf::Texture ass3;
	sf::Texture ass4;

	sf::IntRect rect;

	sf::Texture ene1;
	sf::Texture ene2;
	sf::Texture ene3;
	sf::Texture ene4;
	sf::Texture ene5;
	sf::Sprite enemy1;


	//boss
	sf::Texture bossTexture;
	Animation* bossAnimation;
	sf::Texture flame1;
	sf::Texture flame2;
	sf::Texture flame3;
	sf::Sprite flame;
	sf::Texture bossBarTexture;
	sf::Sprite bossBar;
	sf::RectangleShape bossHealth;

	float bossWidth;

	Animation enemyAnimation;

	float deltatime;
	sf::Clock clock;

	sf::RenderWindow* window;
private:
	void initVeriable();
	void initEmeny();
	void spawnObs(int);
	void spawnEnemy(int);
	void spawnFlames(int);
	
public:
	int maxObstracle;
	float maxDistance;
	bool spawnFinalBoss;
	bool killedBoss;
	sf::Sprite boss;
	int bossHp;
	std::vector<sf::Sprite> flameArray;
	std::vector<Animation> flameAnimation;
	std::vector<sf::Sprite> obsArray;
	std::vector<sf::Sprite> enemyArray;
	std::vector<Animation> animationArray;
	bool isInitiated;
	void spawnBoss();
	void updateBoss();
	void update(int stage, bool flying);
	void updateEnemies(bool, int stage);
	void updateAnimation();
	void render(sf::RenderTarget& target);
	Enemies(sf::RenderWindow* window);
};
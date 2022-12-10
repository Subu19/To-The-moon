#include "Player.h"
#include<iostream>
#include"Background.h"
#include "Collision.cpp"
void Player::initVeriables()
{
	deltatime = 0.f;
	speed.x = 0.f;
	speed.y = 0.f;
	holdedkey = 100;
	spaceHolded = false;
	velocity.x = 0.f;
	velocity.y = 0.f;
	started = false;
	animateRow = 0;
	enableShooting = false;
	this->disableFlight = false;
	shootTime = 0;
	this->stillPlayer = false;
}
void Player::initPlayer(sf::RenderTarget& target)
{
	if (!this->playerTexture.loadFromFile("Resources/Images/player.png")) {
		std::cout << "error while loading player texture!";
	}
	//Collision::CreateTextureAndBitmask(this->playerTexture, "Resources/Images/testPlayer.png");
	this->player.setTexture(playerTexture);
	this->player.setPosition(float(target.getSize().x /2), float(target.getSize().y - 200));
	this->player.setScale(2.f, 2.f);
	this->playerAnimation = new Animation(&playerTexture, sf::Vector2u(18, 4), 0.1f, false);
}
void Player::changePlayer()
{
	if (!this->playerTexture.loadFromFile("Resources/Images/player2.png")) {
		std::cout << "error while loading player texture!";
	}
	this->playerAnimation = new Animation(&playerTexture, sf::Vector2u(4, 4), 0.1f, false);
}

Player::Player(sf::RenderTarget& target, Background& backPtr)
{	
	this->background = &backPtr;
	this->initVeriables();
	this->initPlayer(target);
	this->initBullet();

}

void Player::handlePress(int x) {
	if (x == 57) {
		
		//on space
		spaceHolded = true;
		if (this->speed.y < 6) {
			velocity.y = velocity.y + 0.005f;
			speed.y = speed.y + velocity.y;
		}
		//if (player.getPosition().y > 900.f) {
		//player.setPosition(player.getPosition().x, player.getPosition().y - speed.y);
		//}
		if (!this->background->firstStageAnimation->isCompleted && player.getPosition().y > 900.f) {
			player.setPosition(player.getPosition().x, player.getPosition().y - speed.y);
		}
		else if (player.getPosition().y > 900.f) {
			player.setPosition(player.getPosition().x, player.getPosition().y - speed.y);
		}
	}
	if (x == 0) {
		if (this->background->borderLeft.getGlobalBounds().intersects(this->player.getGlobalBounds())) {
			this->velocity.x = 0.f;
		}
		else {
			if (speed.x < 12) {
				velocity.x += 0.005f;
				speed.x = speed.x + velocity.x;
			}
			animateRow = 2;
			player.setPosition(player.getPosition().x - speed.x, player.getPosition().y);
		}
	}
	if (x == 3) {
		if (this->background->borderRight.getGlobalBounds().intersects(this->player.getGlobalBounds())) {
			this->velocity.x = 0.f;
		}
		else {
			if (speed.x < 12) {
				velocity.x += 0.005f;
				speed.x = speed.x + velocity.x;
			}
		animateRow = 3;
		player.setPosition(player.getPosition().x + speed.x, player.getPosition().y);
		}
	}
	
	
	
}



void Player::updateShoot()
{
	if (bullets.empty())
		return;
	for (int i = 0; i < this->bullets.size(); i++) {
		this->bullets[i].move(0.f,-8.f);
		if (this->bullets[i].getPosition().y < 0) {
			bullets.erase(this->bullets.begin() + i);
		}

	}
}

void Player::renderShoot(sf::RenderTarget& target)
{
	if (bullets.empty())
		return;
	for (auto& a : this->bullets) {
		target.draw(a);
	}
}

void Player::initBullet()
{
	this->bullet.setFillColor(sf::Color::Yellow);
	this->bullet.setSize(sf::Vector2f(10.f, 20.f));
}

int Player::checkCollisionObs(Enemies obs)
{
	bool collided =false;
		if(!obs.obsArray.empty())
		for (auto& a : obs.obsArray) {
			
			if (Collision::CircleTest(this->player, a)) {
				collided = true;
			}
		}
		return collided;
}
int Player::checkCollisionObs(std::vector<sf::Sprite> obs)
{
	bool collided =false;
		if(!obs.empty())
		for (auto& a : obs) {
			
			if (Collision::CircleTest(this->player, a)) {
				collided = true;
			}
		}
		return collided;
}



void Player::update(Enemies& obs, bool initiated, bool update)
{
	this->deltatime = clock.restart().asSeconds();
	this->playerAnimation->update(animateRow, deltatime);
	this->player.setTextureRect(this->playerAnimation->uvRect);
	if (!update)
		return;
	//movements
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		started = true;
		if (initiated) {
			if (!checkCollisionObs(obs)) {
			handlePress(57);	
			}
		}
		else {
			handlePress(57);
		}
	}
	else if(started ==true) {
		if (spaceHolded == true) {
			speed.y = 0.f;
			velocity.y = 0.f;
		}
		if (speed.y <= 6) {
			velocity.y += 0.005f;
			speed.y = speed.y + velocity.y;
		}
		spaceHolded = false;
		if(!stillPlayer)
		         player.setPosition(this->player.getPosition().x, this->player.getPosition().y + speed.y);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (initiated) {
			if (!checkCollisionObs(obs)) {
				onHold = true;
				handlePress(0);
				holdedkey = 0;
			}
		}
		else {
			onHold = true;
			handlePress(0);
			holdedkey = 0;
		}
	}else if (holdedkey == 0) {
		onHold = false;
		velocity.x -= 0.005;
		speed.x -= velocity.x;
		animateRow = 0;
		if (velocity.x < 0 || speed.x < 0) {
			velocity.x = 0.f;
			speed.x = 0.f;
			holdedkey = 100;
		}
		player.setPosition(player.getPosition().x - speed.x, player.getPosition().y);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (initiated) {
			if (!checkCollisionObs(obs)) {
				onHold = true;
				handlePress(3);
				holdedkey = 3;
			}
		}
		else {
			onHold = true;
			handlePress(3);
			holdedkey = 3;
		}
	}
	else if (holdedkey == 3) {
		onHold = false;
		velocity.x -= 0.005;
		speed.x -= velocity.x;
		animateRow = 1;
		if (velocity.x < 0 || speed.x < 0) {
			velocity.x = 0.f;
			speed.x = 0.f;
			holdedkey = 100;
		}
		player.setPosition(player.getPosition().x + speed.x, player.getPosition().y);
	}


	//shooting
	if (enableShooting && started) {
		shootTime += deltatime;
		updateShoot();
	}
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->player);
	if(this->enableShooting)
	this->renderShoot(target);
}

int Player::isFlying()
{
	if (this->spaceHolded && started == true && disableFlight == false) {
		if (this->player.getPosition().y > 900.f) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}



sf::Vector2f Player::getSpeed()
{
	return speed;
}

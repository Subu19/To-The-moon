#include "Enemies.h"
#include <iostream>;
void Enemies::initVeriable()
{
	this->maxObstracle = 3;
	this->maxDistance = 4.f;
	this->spawnFinalBoss = false;
	this->bossHp = 20;
	this->killedBoss = false;
}

void Enemies::initEmeny()
{
	ene1.loadFromFile("Resources/Images/dragon.png");
	ene2.loadFromFile("Resources/Images/beetle.png");
	ene3.loadFromFile("Resources/Images/bat.png");
	ene4.loadFromFile("Resources/Images/ufo1.png");
	ene5.loadFromFile("Resources/Images/ufo2.png");

	this->bossTexture.loadFromFile("Resources/Images/boss.png");

	this->hill.loadFromFile("Resources/Images/obs1.png");
	this->stone.loadFromFile("Resources/Images/obs2.png");
	this->obs3.loadFromFile("Resources/Images/obs3.png");
	this->obs4.loadFromFile("Resources/Images/obs5.png");
	this->obs5.loadFromFile("Resources/Images/obs4.png");
	this->obs6.loadFromFile("Resources/Images/obs6.png");
	this->obs7.loadFromFile("Resources/Images/obs7.png");
	this->obs8.loadFromFile("Resources/Images/obs8.png");
	this->obs9.loadFromFile("Resources/Images/obs9.png");

	this->ass1.loadFromFile("Resources/Images/ass1.png");
	this->ass2.loadFromFile("Resources/Images/ass2.png");
	this->ass3.loadFromFile("Resources/Images/ass3.png");


}

void Enemies::spawnObs(int n)
{
	switch (n)
	{
		case 1:
			
			
			rect.height = hill.getSize().y;
			rect.width = hill.getSize().x;
			this->obs.setTextureRect(rect);
			this->obs.setTexture(this->hill);
			this->obs.setPosition(150.f, 0.f - this->hill.getSize().y * 5);
			this->obs.setScale(5.f, 5.f);
			this->obsArray.push_back(this->obs);
			
			break;
		case 2:
			rect.height = stone.getSize().y;
			rect.width = stone.getSize().x;
			this->obs.setTextureRect(rect);
			this->obs.setTexture(this->stone);
			this->obs.setPosition(2560.f - this->stone.getSize().x * 5, 0.f - this->stone.getSize().y * 5);
			this->obs.setScale(5.f, 5.f);
			this->obsArray.push_back(this->obs);
			break;
		case 3:
			rect.height = obs3.getSize().y;
			rect.width = obs3.getSize().x;
			this->obs.setTextureRect(rect);
			this->obs.setTexture(this->obs3);
			this->obs.setPosition(150.f, 0.f - this->obs3.getSize().y * 5);
			this->obs.setScale(3.f, 3.f);
			this->obsArray.push_back(this->obs);
			break;
		case 4:
			rect.height = obs4.getSize().y;
			rect.width = obs4.getSize().x;
			this->obs.setTextureRect(rect);
			this->obs.setTexture(this->obs4);
			this->obs.setPosition((this->window->getSize().x/2.f) - ((this->obs4.getSize().x*3.f)/2.f) , -(this->obs4.getSize().y*3.f));
			this->obs.setScale(3.f, 3.f);
			this->obsArray.push_back(this->obs);
			break;
		case 5:
			rect.height = obs5.getSize().y;
			rect.width = obs5.getSize().x;
			this->obs.setTextureRect(rect);
			this->obs.setTexture(this->obs5);
			this->obs.setPosition(150.f, 0.f - this->obs5.getSize().y * 5);
			this->obs.setScale(3.f, 3.f);
			this->obsArray.push_back(this->obs);
			break;
		case 6:
			rect.height = obs6.getSize().y;
			rect.width = obs6.getSize().x;
			this->obs.setTextureRect(rect);
			this->obs.setTexture(this->obs6);
			this->obs.setPosition(this->window->getSize().x - (this->obs6.getSize().x*5), 0.f - this->obs6.getSize().y * 5);
			this->obs.setScale(5.f, 5.f);
			this->obsArray.push_back(this->obs);
			break;
		case 7:
			rect.height = obs7.getSize().y;
			rect.width = obs7.getSize().x;
			this->obs.setTextureRect(rect);
			this->obs.setTexture(this->obs7);
			this->obs.setPosition(150.f, 0.f - this->obs7.getSize().y * 5);
			this->obs.setScale(5.f, 5.f);
			this->obsArray.push_back(this->obs);
			break;
		case 8:
			rect.height = obs8.getSize().y;
			rect.width = obs8.getSize().x;
			this->obs.setTextureRect(rect);
			this->obs.setTexture(this->obs8);
			this->obs.setPosition(this->window->getSize().x - (this->obs8.getSize().x*3), 0.f - this->obs8.getSize().y * 5);
			this->obs.setScale(3.f, 3.f);
			this->obsArray.push_back(this->obs);
			break;
		case 9:
			rect.height = obs9.getSize().y;
			rect.width = obs9.getSize().x;
			this->obs.setTextureRect(rect);
			this->obs.setTexture(this->obs9);
			this->obs.setPosition(this->window->getSize().x - (this->obs9.getSize().x*3), 0.f - this->obs9.getSize().y * 5);
			this->obs.setScale(3.f, 3.f);
			this->obsArray.push_back(this->obs);
			break;
		case 10:
			rect.height = ass1.getSize().y;
			rect.width = ass2.getSize().x;
			this->obs.setTextureRect(rect);
			this->obs.setTexture(this->ass1);
			this->obs.setOrigin(this->ass1.getSize().x / 2.f, this->ass1.getSize().y / 2.f);
			this->obs.setPosition(rand() % static_cast<int>(this->window->getSize().x - 500) + 150.f,0.f -(this->ass1.getSize().y));
			this->obs.setScale(1.f, 1.f);
			this->obsArray.push_back(this->obs);
			break;
		case 11:
			rect.height = ass2.getSize().y;
			rect.width = ass2.getSize().x;
			this->obs.setTextureRect(rect);
			this->obs.setTexture(this->ass2);
			this->obs.setOrigin(this->ass2.getSize().x / 2.f, this->ass1.getSize().y / 2.f);
			this->obs.setPosition(rand() % static_cast<int>(this->window->getSize().x - 500) + 150.f,0.f -(this->ass2.getSize().y));
			this->obs.setScale(1.f, 1.f);
			this->obsArray.push_back(this->obs);
			break;
		case 12:
			rect.height = ass3.getSize().y;
			rect.width = ass3.getSize().x;
			this->obs.setTextureRect(rect);
			this->obs.setTexture(this->ass3);
			this->obs.setOrigin(this->ass3.getSize().x / 2.f, this->ass3.getSize().y / 2.f);
			this->obs.setPosition(rand() % static_cast<int>(this->window->getSize().x - 500) + 150.f,0.f -(this->ass3.getSize().y * 3));
			this->obs.setScale(1.f, 1.f);
			this->obsArray.push_back(this->obs);
			break;
		default:
			break;
	}
}

void Enemies::spawnEnemy(int n)
{

	switch (n)
	{
	case 1:
		enemyAnimation = Animation(&ene1, sf::Vector2u(8, 1), 0.1f, false);
		rect.height = ene1.getSize().y;
		rect.width = ene1.getSize().x;
		this->enemy1.setTextureRect(rect);
		this->enemy1.setTexture(this->ene1);
		this->enemy1.setPosition(rand() % static_cast<int>(this->window->getSize().x - 500) + 150.f, 0.f - this->ene1.getSize().y * 3);
		this->enemy1.setScale(3.f, 3.f);
		this->enemyArray.push_back(this->enemy1);
		this->animationArray.push_back(enemyAnimation);
		break;
	case 2:
		enemyAnimation = Animation(&ene2, sf::Vector2u(4, 1), 0.1f, false);
		rect.height = ene2.getSize().y;
		rect.width = ene2.getSize().x;
		this->enemy1.setTextureRect(rect);
		this->enemy1.setTexture(this->ene2);
		this->enemy1.setPosition(rand() % static_cast<int>(this->window->getSize().x - 500) + 150.f, 0.f - this->ene2.getSize().y * 5);
		this->enemy1.setScale(5.f, 5.f);
		this->enemyArray.push_back(this->enemy1);
		this->animationArray.push_back(enemyAnimation);
		break;
	case 3:
		enemyAnimation = Animation(&ene3, sf::Vector2u(4, 1), 0.1f, false);
		rect.height = ene3.getSize().y;
		rect.width = ene3.getSize().x;
		this->enemy1.setTextureRect(rect);
		this->enemy1.setTexture(this->ene3);
		this->enemy1.setPosition(rand() % static_cast<int>(this->window->getSize().x - 500) + 150.f, 0.f - this->ene3.getSize().y * 5);
		this->enemy1.setScale(5.f, 5.f);
		this->enemyArray.push_back(this->enemy1);
		this->animationArray.push_back(enemyAnimation);
		break;
	case 4:
		enemyAnimation = Animation(&ene4, sf::Vector2u(2, 1), 0.1f, false);
		rect.height = ene4.getSize().y;
		rect.width = ene4.getSize().x;
		this->enemy1.setTextureRect(rect);
		this->enemy1.setTexture(this->ene4);
		this->enemy1.setPosition(rand() % static_cast<int>(this->window->getSize().x - 500) + 150.f, 0.f - this->ene4.getSize().y);
		this->enemy1.setScale(1.f, 1.f);
		this->enemyArray.push_back(this->enemy1);
		this->animationArray.push_back(enemyAnimation);
		break;
	case 5:
		enemyAnimation = Animation(&ene5, sf::Vector2u(9, 1), 0.1f, false);
		rect.height = ene5.getSize().y;
		rect.width = ene5.getSize().x;
		this->enemy1.setTextureRect(rect);
		this->enemy1.setTexture(this->ene5);
		this->enemy1.setPosition(rand() % static_cast<int>(this->window->getSize().x - 500) + 150.f, 0.f - this->ene5.getSize().y);
		this->enemy1.setScale(1.f, 1.f);
		this->enemyArray.push_back(this->enemy1);
		this->animationArray.push_back(enemyAnimation);
		break;
	default:
		break;
	}
}

void Enemies::spawnFlames(int n)
{
	switch (n)
	{
	case 1:
		enemyAnimation = Animation(&flame1, sf::Vector2u(4, 1), 0.1f, false);
		rect.height = flame1.getSize().y;
		rect.width = flame1.getSize().x;
		this->flame.setTextureRect(rect);
		this->flame.setTexture(this->flame1);
		this->flame.setPosition(this->boss.getPosition());
		this->flame.setScale(4.f, 4.f);
		this->flameArray.push_back(this->flame);
		this->flameAnimation.push_back(enemyAnimation);
		break;
	case 2:
		enemyAnimation = Animation(&flame2, sf::Vector2u(4, 1), 0.1f, false);
		rect.height = flame2.getSize().y;
		rect.width = flame2.getSize().x;
		this->flame.setTextureRect(rect);
		this->flame.setTexture(this->flame2);
		this->flame.setPosition(this->boss.getPosition());
		this->flame.setScale(4.f, 4.f);
		this->flameArray.push_back(this->flame);
		this->flameAnimation.push_back(enemyAnimation);
		break;
	case 3:
		enemyAnimation = Animation(&flame3, sf::Vector2u(4, 1), 0.1f, false);
		rect.height = flame3.getSize().y;
		rect.width = flame3.getSize().x;
		this->flame.setTextureRect(rect);
		this->flame.setTexture(this->flame3);
		this->flame.setPosition(this->boss.getPosition());
		this->flame.setScale(4.f, 4.f);
		this->flameArray.push_back(this->flame);
		this->flameAnimation.push_back(enemyAnimation);
		break;
	default:
		break;
	}
}

void Enemies::spawnBoss()
{
	this->flame1.loadFromFile("Resources/Images/flame1.png");
	this->flame2.loadFromFile("Resources/Images/flame2.png");
	this->flame3.loadFromFile("Resources/Images/flame3.png");
	this->boss.setTexture(this->bossTexture);
	this->bossAnimation = new Animation(&bossTexture, sf::Vector2u(8, 1), 0.01, false);
	this->boss.setScale((this->window->getSize().y / 4.f) / 103.f, (this->window->getSize().y / 4.f) / 103.f);
	this->boss.setPosition(0.f, 0.f);
	this->boss.setOrigin((164.f)/2.f, 0.f);
	this->boss.setTextureRect(this->bossAnimation->uvRect);
	this->boss.setPosition((this->window->getSize().x/2.f), -(this->bossTexture.getSize().y * this->boss.getScale().y));


	//set boss bar
	this->bossBarTexture.loadFromFile("Resources/Images/bar.png");
	this->bossBar.setTexture(this->bossBarTexture);
	this->bossBar.setOrigin(71.f, 10.f);
	this->bossBar.setScale((this->window->getSize().x / 3.f) / 142.f, (this->window->getSize().x / 3.f) / 142.f);
	this->bossBar.setPosition(this->window->getSize().x/2.f, this->bossBar.getScale().y * 10.f);
	this->bossHealth.setSize(sf::Vector2f(142.f, 10.f));
	this->bossHealth.setScale((this->window->getSize().x / 3.f) / 152.f, (this->window->getSize().x / 3.f) / 152.f);
	this->bossHealth.setPosition(this->bossBar.getGlobalBounds().left +30.f, this->bossBar.getScale().y * 7.f);
	this->bossHealth.setFillColor(sf::Color::Red);
	this->bossWidth = this->bossHealth.getSize().x;


}

void Enemies::updateBoss()
{
	
	this->bossAnimation->update(0, deltatime);
	this->boss.setTextureRect(this->bossAnimation->uvRect);
	//make it go down until its visible
	if (this->boss.getPosition().y < 0) {
		this->boss.move(0.f, 2.f);
	}
	else {
	//	//make boss do stuffs
		if (!flameArray.empty()) {

			//move flames
			for (int i = 0; i < flameArray.size(); i++)
			{
				flameAnimation[i].update(0, deltatime);
				flameArray[i].setTextureRect(flameAnimation[i].uvRect);
				flameArray[i].move(0.f, 4.f);
				if (this->flameArray[i].getPosition().y > 1900.f) {
					this->flameArray.erase(this->flameArray.begin() + i);
					this->flameAnimation.erase(this->flameAnimation.begin() + i);
				}
			}

		//spawn flames if necessary
			if (flameArray.size() < 5 && flameArray[flameArray.size() - 1].getGlobalBounds().top > this->window->getSize().y / 7.f) {
					spawnFlames(rand() % 3 + 1);
			}


		}
		else {
			//spawn if none flames
			spawnFlames(rand() % 3 + 1);
		}
		
	}

	//update bossbar health
	
	this->bossHealth.setSize(sf::Vector2f((bossHp/20.f)*bossWidth, this->bossHealth.getSize().y));

}

void Enemies::update(int stage, bool flying)
{
	updateAnimation();
	//spawn obstracles
	if (killedBoss) {
	
		return;
	}
	if (spawnFinalBoss) {
		if (!obsArray.empty()) {
			for (int i = 0; i < obsArray.size(); i++)
			{
				
				obsArray[i].move(0.f, 10.1f);
				if (stage == 2) {
					obsArray[i].rotate(1.f);
				}
				if (this->obsArray[i].getPosition().y > 1900.f) {
					std::cout << "Erasing" <<i<<"\n";
					this->obsArray.erase(this->obsArray.begin() + i);
					std::cout << "erased" << i << "\n";
				}
			}
		}
		else {
			//do something with final boss update
			updateBoss();
		}
			
	}else if (!obsArray.empty()) {
		for (int i = 0; i < obsArray.size(); i++)
		{
			
			if (!flying && stage == 2) {
				obsArray[i].move(0.f, 3.1f);
			}
			else if(stage == 2) {
				obsArray[i].move(0.f, 10.1f);
			}
			else {
				obsArray[i].move(0.f, 6.1f);
			}
			if (stage == 2) {
				obsArray[i].rotate(1.f);
			}
			if (this->obsArray[i].getPosition().y > 1900.f) {
				this->obsArray.erase(this->obsArray.begin() + i);
			}
		}
		if (obsArray.size() < maxObstracle && obsArray[obsArray.size() - 1].getGlobalBounds().top > this->window->getSize().y/maxDistance) {
			if (stage == 1) {
				spawnObs(rand() % 9 + 1);
			}
			else if (stage == 2) {
				spawnObs(rand() % 12 + 10);
			}
		}
	}
	else {

		if (stage == 1) {
			spawnObs(rand() % 9 + 1);
		}
		else if (stage == 2) {
			spawnObs(rand() % 12 + 10);
		}
	}
}


void Enemies::updateEnemies(bool flying, int stage)
{
	if (killedBoss)
		return;
	if (spawnFinalBoss) {
		
		if (!enemyArray.empty()) {
			for (int i = 0; i < enemyArray.size(); i++)
			{
				animationArray[i].update(0, deltatime);
				enemyArray[i].setTextureRect(animationArray[i].uvRect);
				if (stage == 1) {
					enemyArray[i].move(3.f, 0.f);
					if (flying) {
						enemyArray[i].move(0.f, 6.1f);
					}

				}
				else if (stage == 2) {
					if (flying)
						enemyArray[i].move(0.f, 3.1f);
					else
						enemyArray[i].move(0.f, 2.f);
				}

				//}
				if (this->enemyArray[i].getPosition().x > this->window->getSize().x || this->enemyArray[i].getPosition().y > this->window->getSize().y) {
					this->enemyArray.erase(this->enemyArray.begin() + i);
					this->animationArray.erase(this->animationArray.begin() + i);
				}
			}
		}
		else {
			//spawn boss's elements

		}

	}
	else {
		//spawn enemy
		
		if (!enemyArray.empty()) {
			for (int i = 0; i < enemyArray.size(); i++)
			{
				animationArray[i].update(0, deltatime);
				enemyArray[i].setTextureRect(animationArray[i].uvRect);
				if (stage == 1) {
					enemyArray[i].move(3.f, 0.f);
					if (flying) {
						enemyArray[i].move(0.f, 6.1f);
					}

				}
				else if (stage == 2) {


					if (flying)
						enemyArray[i].move(0.f, 3.1f);
					else
						enemyArray[i].move(0.f, 2.f);
				}

				//}
				if (this->enemyArray[i].getPosition().x > this->window->getSize().x || this->enemyArray[i].getPosition().y > this->window->getSize().y) {
					this->enemyArray.erase(this->enemyArray.begin() + i);
					this->animationArray.erase(this->animationArray.begin() + i);
				}
			}
			if (enemyArray.size() < 3 && enemyArray[enemyArray.size() - 1].getGlobalBounds().top > this->window->getSize().y / 4.f) {
				if (stage == 2)
					spawnEnemy(rand() % 5 + 4);
				else if (stage == 1)
					spawnEnemy(rand() % 3 + 1);

			}
		}
		else {
			if (stage == 2)
				spawnEnemy(rand() % 5 + 4);
			else if (stage == 1)
				spawnEnemy(rand() % 3 + 1);
		}
	}
	
}

void Enemies::updateAnimation()
{
	this->deltatime = clock.restart().asSeconds();
	//this->eneA1->update(0, deltatime);
	//this->enemy1.setTextureRect(this->eneA1->uvRect);

}

void Enemies::render(sf::RenderTarget& target)
{
	
	if(!obsArray.empty())
	for (auto& e : this->obsArray) {
		target.draw(e);
	}
	if (!enemyArray.empty())
	for (auto& e : this->enemyArray) {
		target.draw(e);
	}
	if (spawnFinalBoss && !killedBoss ) {
		//render flames
		if(!flameArray.empty())
		for (auto& e : this->flameArray) {
			target.draw(e);
		}
		//render boss
		target.draw(this->boss);
		target.draw(this->bossHealth);
		target.draw(this->bossBar);
	}

}

Enemies::Enemies(sf::RenderWindow* window)
{
	this->window = window;
	initVeriable();
	initEmeny();
	this->isInitiated = true;
}
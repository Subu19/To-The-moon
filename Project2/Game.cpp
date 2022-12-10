#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include "Game.h"
//#include "Collision.cpp"
using namespace std;
void Game::initVeriable() {
    this->window = nullptr;
    this->enemySpawnTimerMax = 10.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 15;
    this->mouseHeld = false;
    this->_coins = 0;
    this->_score = 0;
    this->playingMusic = false;
    this->endGame = false;
    this->newGame = false;
    this->pause = false;
    this->setAnimation = false;
    this->firstStageCompleted = false;
    this->portalEffect = false;
    if (!music.openFromFile("Resources/Audio/music.ogg"))
        std::cout << "Cant load music!";
    if (!deathBuffer.loadFromFile("Resources/Audio/death.ogg"))
        std::cout << "couldnt load sound";
    this->deathSound.setBuffer(this->deathBuffer);
}
void Game::initFont() {
    this->font.loadFromFile("Fonts/Organic-Relief.ttf");
}
void Game::initText() {
    this->scoreText.setFont(this->font);
    this->scoreText.setFillColor(sf::Color::White);
    this->scoreText.setCharacterSize(24);
    this->scoreText.setString("NONE");
    this->scoreText.setPosition(10.f, 10.f);

    this->coinText.setFont(this->font);
    this->coinText.setFillColor(sf::Color::White);
    this->coinText.setCharacterSize(24);
    this->coinText.setString("NONE");
    this->coinText.setPosition(10.f, 70.f);


}
void Game::initWindow() {
    this->videoMode.height = this->videoMode.getDesktopMode().height - 150.f;
    this->videoMode.width = this->videoMode.getDesktopMode().width;
    this->window = new sf::RenderWindow(this->videoMode, "To The Moon", sf::Style::Fullscreen);

    //init loading screen
    this->window->setFramerateLimit(60);
    this->window->clear(sf::Color::Blue);
    if (!loadingT.loadFromFile("Resources/Images/default.png"))
        std::cout << "failed to load default image";
    this->loading.setTexture(this->loadingT);
    this->loading.setPosition(0.f, 0.f);
    this->loading.setScale(this->window->getSize().x / 1920.f, this->window->getSize().y / 1080.f);
    this->window->draw(loading);
    if (!menuMusic.openFromFile("Resources/Audio/menuMusic.ogg"))
        std::cout << "Faild to load menu music";
    menuMusic.play();
    this->window->display();

    //init menu
    this->menuT.loadFromFile("Resources/Images/menu.png");
    this->menu.setPosition(0.f, 0.f);
    this->menu.setTexture(this->menuT);
    this->menu.setScale(this->window->getSize().x / 1920.f, this->window->getSize().y / 1080.f);

    //init pause menu
    this->pauseT.loadFromFile("Resources/Images/pause.png");
    this->pauseMenu.setTexture(this->pauseT);
    this->pauseMenu.setScale((this->window->getSize().y/2.f)/100.f, (this->window->getSize().y / 2.f) / 100.f);
    this->pauseMenu.setPosition((this->window->getSize().x / 2.f) - ((this->pauseT.getSize().x *(this->pauseMenu.getScale().x)) / 2.f), (this->window->getSize().y / 2.f) - ((this->pauseT.getSize().x * (this->pauseMenu.getScale().y)) / 2.f));

    this->deathT.loadFromFile("Resources/Images/death.png");
    this->deathMenu.setTexture(this->deathT);
    this->deathMenu.setScale((this->window->getSize().y / 2.f) / 100.f, (this->window->getSize().y / 2.f) / 100.f);
    this->deathMenu.setPosition((this->window->getSize().x / 2.f) - ((this->deathT.getSize().x * (this->deathMenu.getScale().x)) / 2.f), (this->window->getSize().y / 2.f) - ((this->deathT.getSize().x * (this->deathMenu.getScale().y)) / 2.f));


    //init portal veriables and textures
    this->portalWallTexture.loadFromFile("Resources/Images/portalwall.png");
    this->portalWall.setTexture(this->portalWallTexture);
    this->portalWall.setScale(this->window->getSize().x/ 150.f, (this->window->getSize().y/3.f) / 32.f);
    this->portalWall.setPosition(0.f, - portalWall.getScale().y * 32.f);
    this->portalTexture.loadFromFile("Resources/Images/portal.png");
    this->portal.setTexture(this->portalTexture);
    this->portal.setScale(2.f, 2.f);
    this->portal.setPosition((this->window->getSize().x / 2.f) - ((this->portalTexture.getSize().x /6.f)* this->portal.getScale().x) / 2.f, -(this->portalTexture.getSize().y* 2.f));
    
}
void Game::initEnemy() {
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setFillColor(sf::Color::Green);

    this->bossaura.openFromFile("Resources/Audio/ufo_aura.wav");
    this->bossDeathBuffer.loadFromFile("Resources/Audio/bossDeath.wav");
    this->bossDeathSound.setBuffer(this->bossDeathBuffer);
}
void Game::initPlayer()
{
    this->background = new Background(*this->window);
    this->player = new Player(*this->window, *this->background);
    this->heartTexture.loadFromFile("Resources/Images/heart.png");
    this->heart.setTexture(this->heartTexture);
    this->heart.setScale((this->window->getSize().y / 20.f) / 83.f, (this->window->getSize().y / 20.f) / 83.f);

    //init music
    this->gunBuffer.loadFromFile("Resources/Audio/gun.wav");
    this->gunSound.setBuffer(this->gunBuffer);
}
void Game::initCoin()
{
    if (!coinBuffer.loadFromFile("Resources/Audio/coin.wav"))
        std::cout << "couldnt load sound";
    this->coinSound.setBuffer(coinBuffer);

    coinTexture.loadFromFile("Resources/Images/coin.png");
    this->coinAnimation = new Animation(&coinTexture, sf::Vector2u(10, 1), 0.1f, false);
   
}
float Game::getNewPosition() {
    float x;
    bool safe = false;
    while (!safe) {
        x = rand() % static_cast<int>(this->window->getSize().x - 500) + 150.f;
        if (obs) {
        for (auto& a : this->obs->obsArray)
        {
            if (a.getGlobalBounds().contains( x ,0.f)) {
                safe = false;
            }
            else {
                safe = true;
            }
        }
        }
        else {
            safe = true;
        }
    }
    
    return x;
}
void Game::spawnCoins()
{
    coin.setTextureRect(this->coinAnimation->uvRect);
    coin.setTexture(coinTexture);
    coin.setPosition(this->getNewPosition(),0.f - (this->coinAnimation->uvRect.height));
    coin.setScale(2.f,2.f);
    coins.push_back(coin);

}
Game::Game() {
    this->initVeriable();
    this->initFont();
    this->initText();
    this->initWindow();
    this->initPlayer();
    this->initEnemy();
    this->initCoin();

}
Game::~Game() {
    delete this->window;

}

const bool Game::running() const {
    return this->window->isOpen();
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::MouseButtonPressed:
            if (ev.key.code == sf::Mouse::Left) {
                //bullet shoot
                if (this->player->enableShooting && this->player->started) {
                    if (this->player->shootTime >= 0.5f) {
                        //resetcooldown for shooting
                        this->player->shootTime = 0;
                        this->gunSound.play();
                            this->player->bullet.setPosition(this->player->player.getPosition());
                            this->player->bullets.push_back(this->player->bullet);
                    }
                }
            }
        case sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::F1)
                this->window->close();
            else if (ev.key.code == sf::Keyboard::Escape && !endGame)
                if (this->pause) {
                    this->music.play();
                    this->pause = false;
                }
                else {
                    this->pause = true;
                    this->music.pause();
                }
            if (ev.key.code == sf::Keyboard::R && endGame) {
                newGame = true;
            }
            break;
            
        
        }    
    }
}

void Game::updateMousePos() {
    this->mousePos = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePos);
}

void Game::updateBackground()
{
    if (this->player->isFlying() && !this->background->fadeComplete) {
        this->background->borderAnimation->setSwitchTime(0.01f);
        this->background->borderAnimation->resume();
        this->background->borderAnimation2->setSwitchTime(0.01f);
        this->background->borderAnimation2->resume();
        if (!this->background->firstStageAnimation->isCompleted) {
            this->background->firstStageAnimation->resume();
        }
       
    }
    else if(!this->background->fadeComplete) {
        this->background->borderAnimation->pause();
        this->background->borderAnimation2->pause();
        if (!this->background->firstStageAnimation->isCompleted) {
        this->background->firstStageAnimation->pause();
        }
    }


    if (this->player->started && this->background->fadeComplete) {
        if (this->player->isFlying()) {
            if (!this->background->secondStageAnimation->isCompleted) {
                this->background->secondStageAnimation->resume();
            }
        }
        else {
            if (!this->background->secondStageAnimation->isCompleted) {
                this->background->secondStageAnimation->pause();
            }
        }
      
           

    }
    this->background->update();
}

void Game::updateCoins()
{
    this->deltatime = clock.restart().asSeconds();
    this->coinAnimation->update(0, deltatime);
    if (portalEffect && player->started == false)
        return;
    if (!coins.empty()) {
        for (int i = 0; i < coins.size(); i++) {
                coins[i].setTextureRect(this->coinAnimation->uvRect);
            if (player->isFlying()) {
                coins[i].move(0.f, 6.1f);
                if (this->coins[i].getPosition().y > 1900.f) {
                    this->coins.erase(this->coins.begin() + i);
                }
                if (this->player->player.getGlobalBounds().intersects( this->coins[i].getGlobalBounds())) {
                    this->coins.erase(this->coins.begin() + i);
                    _coins++;
                    this->coinSound.play();
                }
               /* if (Collision::PixelPerfectTest(this->player->player, coins[i]))
                {
                    this->coins.erase(this->coins.begin() + i);
                    _coins++;
                    this->coinSound.play();
                }*/
            }

        }
        if (coins.size() < 5 && coins[coins.size() - 1].getGlobalBounds().top > 400) {
            spawnCoins();
        }
    }
    else {
        spawnCoins();
    }
}

void Game::renderCoins()
{
    if (!coins.empty()) {
        for (auto& a : coins) {
            this->window->draw(a);
        }
    }
    
}

void Game::update(bool* const& restart) {
    this->pollEvents();
    if (_score == 1000) {
        firstStageCompleted = true;
        portalEffect = true;
        _score++;
        delete obs;
        obs = NULL;
        coins.clear();
    }
    if (_score == 1500) {
        this->obs->spawnFinalBoss = true;
        this->obs->spawnBoss();
        this->bossaura.play();
        this->bossaura.setLoop(true);
        this->player->disableFlight = true;
        _score++;
        std::cout << "Spawnned Boss!"<<endl;
        coins.clear();
    }
    if (this->endGame == false) {
        if (this->pause == false) {
            this->updateMousePos();
            this->updateEnemies();
            this->updateText();
            this->updateHearts();
            if (!portalEffect) {
                this->updateBackground();
                //update moon if endgame
                if (obs)
                    if (obs->killedBoss)
                        this->background->updateMoon(*this->window);
                if(player->started)
                this->updateCoins();
                
            }

            //set portal effect
            if (firstStageCompleted == true && portalEffect == true) {
                //move portal and wall down until 0 x-axis
                if (portalWall.getPosition().y < 0) {
                    portalWall.move(0.f, 6.1f);
                    this->updateBackground();
                }
                else {
                    portalWall.setPosition(0.f, 0.f);
                }
                if (portal.getPosition().y < 0) {
                    portal.move(0.f, 6.1f);

                }
                else {
                    portalWall.setPosition(0.f, 0.f);
                }
                //pull player!
                if (player->player.getPosition().x < (this->window->getSize().x - 5.f) / 2.f) {
                    player->player.move(4.f, 0.f);
                }
                else if(player->player.getPosition().x > (this->window->getSize().x + 5.f) / 2.f) {
                    player->player.move(-4.f, 0.f);
                }
                if (player->player.getPosition().y < this->portal.getGlobalBounds().top + this->portalTexture.getSize().y- 4.f) {
                    player->player.move(0.f, 2.f);
                }
                else if(player->player.getPosition().y > this->portal.getGlobalBounds().top + this->portalTexture.getSize().y + 4.f) {
                    player->player.move(0.f, -2.f);
                }
                else {
                    if(player->player.getScale().x > 0)
                    player->player.setScale(this->player->player.getScale().x - 0.1, this->player->player.getScale().y - 0.1);
                        //teleporting player!
                    else {
                        //after teleporting!
                        this->background->updateFlash(*this->window);
                        if (this->background->fadeComplete) {
                            this->portalEffect = false;
                            this->player->started = false;
                            this->player->enableShooting = true;
                            this->player->player.setScale(2.f, 2.f);
                            this->player->changePlayer();
                            this->player->player.setPosition(float(this->window->getSize().x/2), float(this->window->getSize().y -200.f));
                        }
                    }
                }
                this->player->update(*this->obs, false, false);
            }else if (obs) {
                
                this->player->update(*this->obs, true,true);
            }
            else {
                this->player->update(*this->obs, false, true);
            }
           
            if (this->player->isFlying() && !portalEffect)
                _score++;
            if (this->player->started && !this->playingMusic) {
                    this->playingMusic = true;
                    this->music.play();
                    this->menuMusic.pause();
                    this->music.setLoop(true);
            }
        }
    }
    else {
        if (_coins >= 5) {
            _coins = _coins - 5;
            this->obs->enemyArray.clear();
            this->obs->obsArray.clear();
            this->obs->flameArray.clear();
            this->obs->animationArray.clear();
            this->obs->flameAnimation.clear();
            this->endGame = false;
            this->music.play();
        }

        if (newGame) {
            *restart = true;
            this->window->close();
        }
    }
}
void Game::updateText() {
    std::stringstream cT, sT;
    sT << "SCORE: " << this->_score;
    this->scoreText.setString(sT.str());
    cT << "COINS: " << this->_coins;
    this->coinText.setString(cT.str());

    // this->uiText.setString();
}

void Game::updateHearts()
{
    int lives = _coins / 5;
    hearts.clear();
    for (int i = 0; i <= lives; i++) {    
        if (i > 0) {
            //multiple hearts dynamic position
            heart.setPosition(hearts[i - 1].getGlobalBounds().left+ hearts[i - 1].getGlobalBounds().width, 200.f);
        }
        else {
            //initial heart
            heart.setPosition(5.f, 200.f);
        }
        hearts.push_back(heart);
    }

}

void Game::renderText() {
    this->window->draw(this->coinText);
    this->window->draw(this->scoreText);
}

void Game::spawnEnemy() {
    //spawn new enemy
    this->enemy.setPosition(static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)), 0.f);
    this->enemy.setFillColor(sf::Color::White);
    this->enemy.setSize(sf::Vector2f(5.f,3.f));
    this->enemies.push_back(this->enemy);

}
void Game::updateEnemies() {
    if (this->enemies.size() < this->maxEnemies) {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        }
        else
            this->enemySpawnTimer += 1.f;

    }
    //move enemy
    for (int i = 0; i < this->enemies.size(); i++)
    {
        /* code */
        if (player->isFlying())
            this->enemies[i].move(0.f, 5.f);
        else
            this->enemies[i].move(0.f, 2.f);
        //check if the enemy passed the border
        if (this->enemies[i].getPosition().y >= this->window->getSize().y) {
            this->enemies.erase(this->enemies.begin() + i);
        }
    }
    //click event

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (mouseHeld == false) {
            mouseHeld = true;
            for (int i = 0; i < this->enemies.size(); i++)
            {
                /* code */
                if (this->enemies[i].getGlobalBounds().contains(this->mousePosView)) {
                    this->enemies.erase(this->enemies.begin() + i);
                }
            }
        }
    }
    
    else {
        this->mouseHeld = false;
    }

    if (this->background->firstStageAnimation->isCompleted && firstStageCompleted == false) {
        if (!this->obs)
            obs = new Enemies(this->window);
        else if(this->player->isFlying()) {
            obs->update(1, this->player->isFlying());
            obs->updateEnemies(true, 1);
            for (auto& a : obs->obsArray)
            {
                if (a.getGlobalBounds().intersects(this->player->player.getGlobalBounds())) {
                    a.move(0.f, -2.1f);
                    this->endGame = true;
                    this->music.pause();
                    this->deathSound.play();
                }
            }
            for (auto& a : obs->enemyArray)
            {
                if (a.getGlobalBounds().intersects(this->player->player.getGlobalBounds())) {
                    a.move(0.f, -2.1f);
                    this->endGame = true;
                    this->music.pause();
                    this->deathSound.play();
                }
            }
        }
        else {
            obs->updateEnemies(this->player->isFlying(),1);
        }
    }
    else if(firstStageCompleted == true && portalEffect == false && this->background->secondStageAnimation->isCompleted) {
        //spawn second stage enemy!!!

        //for obstracles
        if (!this->obs) {
            cout << "test2";
            obs = new Enemies(this->window);
            this->obs->maxObstracle = 10;
            this->obs->maxDistance = 100.f;
        }
        else {
            //for boss enemy
            if (this->obs->spawnFinalBoss) {
                if (this->obs->boss.getPosition().x < this->player->player.getPosition().x)
                    this->obs->boss.move(3.f, 0.f);
                if (this->obs->boss.getPosition().x > this->player->player.getPosition().x)
                    this->obs->boss.move(-3.f, 0.f);
                if(!this->obs->flameArray.empty())
                    for (int i = 0; i < this->obs->flameArray.size(); i++) {
                        if (this->player->checkCollisionObs(this->obs->flameArray)) {
                            this->endGame = true;
                            this->music.pause();
                            this->deathSound.play();
                        }
                    }
                if(!player->bullets.empty())
                    for (int i = 0; i < this->player->bullets.size(); i++) {
                        if(this->obs->boss.getGlobalBounds().contains(this->player->bullets[i].getPosition())){
                            player->bullets.erase(player->bullets.begin() + i);
                            this->obs->bossHp--;
                            if (this->obs->bossHp <= 0) {
                                this->obs->killedBoss = true;
                                this->obs->flameArray.clear();
                                this->obs->flameAnimation.clear();
                                this->music.pause();
                                this->menuMusic.play();
                                this->bossaura.stop();
                                this->bossDeathSound.play();
                                this->player->enableShooting = false;
                                this->player->stillPlayer = true;
                                this->background->spawnMoon(*this->window);
                            }
                        }
                    }
            }
                obs->update(2, this->player->isFlying());
                obs->updateEnemies(this->player->isFlying(), 2);
                //move enemy towards player
                if (!this->obs->enemyArray.empty())
                    for (auto& a : this->obs->enemyArray) {
                        if (a.getPosition().x < this->player->player.getPosition().x)
                            a.move(2.f, 0.f);
                        if (a.getPosition().x > this->player->player.getPosition().x)
                            a.move(-2.f, 0.f);
                    }
                //check collision for obstracles
                if (!this->obs->obsArray.empty())
                    if (this->player->checkCollisionObs(*this->obs)) {
                        endGame = 1;
                        this->music.pause();
                        this->deathSound.play();
                    }
                //check collision for enemy
                if (!this->obs->enemyArray.empty())
                    for (int i = 0; i < this->obs->enemyArray.size(); i++)
                    {
                        if (obs->enemyArray[i].getGlobalBounds().intersects(this->player->player.getGlobalBounds())) {
                            obs->enemyArray[i].move(0.f, -2.1f);
                            this->endGame = true;
                            this->music.pause();
                            this->deathSound.play();
                        }
                        if (!player->bullets.empty())
                            for (int j = 0; j < this->player->bullets.size(); j++) {
                                if (obs->enemyArray[i].getGlobalBounds().contains(player->bullets[j].getPosition())) {
                                    obs->enemyArray.erase(obs->enemyArray.begin() + i);
                                    obs->animationArray.erase(obs->animationArray.begin() + i);
                                    player->bullets.erase(player->bullets.begin() + j);
                                }
                            }
                    } 
        }

    }
    else if(firstStageCompleted == true && portalEffect == true) {
        
        if (setAnimation == false) {
            portalAnimation = Animation(&portalTexture, sf::Vector2u(6, 1), 0.1f, false);
            setAnimation = true;
        }
        this->portalAnimation.update(0, deltatime);
        this->portal.setTextureRect(this->portalAnimation.uvRect);
        if(this->player->isFlying())
        this->portal.move(0.f, 0.f);
      

    }


}
void Game::renderEnemies() {
    for (auto& e : this->enemies)
    {
        /* code */
        this->window->draw(e);
    }
   
}

void Game::renderHearts()
{
    for (auto& a : hearts) {
        this->window->draw(a);
    }
}


void Game::render() {
    this->window->clear(sf::Color::Black);
    //draw here
    
    this->background->render(*this->window, this->obs);
    this->renderEnemies();
    this->renderCoins();
    this->renderHearts();
  
    if (!this->player->started)
        this->window->draw(this->menu);
    //spawn portal when needed
    if (firstStageCompleted == true && portalEffect == true) {
        this->window->draw(this->portalWall);
        this->window->draw(this->portal);
        this->background->renderFlash(*this->window);
    }
    if (obs)
        if (this->obs->killedBoss)
            this->background->renderMoon(*this->window);
    if(!this->background->fadeMoonComplete)
    this->player->render(*this->window);
    if (pause)
        this->window->draw(this->pauseMenu);
    if (endGame == true)
        this->window->draw(this->deathMenu);
   
    this->renderText();
    this->window->display();
}



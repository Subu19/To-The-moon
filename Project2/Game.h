#pragma once
#include <vector>
#include <SFML/Audio.hpp>
#include<ctime>
#include "Player.h"
#include"Background.h"
#include "Animation.h"
#include "Enemies.h"
class Game {
private:

    //pass window as pointer
    sf::RenderWindow* window;
    //pass videoMode
    sf::VideoMode videoMode;
    //get events
    sf::Event ev;
    Background* background;
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;
    sf::Vector2i mousePos;
    sf::Vector2f mousePosView;
    sf::Font font;
    sf::Text coinText;
    sf::Text scoreText;

    sf::Texture coinTexture;
    sf::Sprite coin;
    Animation* coinAnimation;
    //player
    Player* player;
    sf::Texture heartTexture;
    sf::Sprite heart;
    std::vector<sf::Sprite> hearts;
    int currentLives;
    //enemy
    Enemies* obs;
    sf::Clock clock;
    std::vector<sf::Sprite> coins;

    //portal
    sf::Texture portalTexture;
    sf::Sprite portal;
    sf::Texture portalWallTexture;
    sf::Sprite portalWall;
    //game logic


    //music and sounds
    sf::SoundBuffer coinBuffer;
    sf::Sound coinSound;
    sf::SoundBuffer deathBuffer;
    sf::Sound deathSound;
    sf::Music music;
    sf::Music menuMusic;
    sf::SoundBuffer gunBuffer;
    sf::Sound gunSound;
    bool playingMusic;
    sf::Music bossaura;
    sf::SoundBuffer bossDeathBuffer;
    sf::Sound bossDeathSound;
    

    //default image
    sf::Sprite loading;
    sf::Texture loadingT;
    sf::Sprite menu;
    sf::Texture menuT;

    //pause and death
    sf::Sprite pauseMenu;
    sf::Texture pauseT;
    sf::Sprite deathMenu;
    sf::Texture deathT;

    unsigned points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    bool mouseHeld;
    int _score;
    int _coins;
    bool endGame;
    bool pause;
    float deltatime;
    bool newGame;
    //declare initialize veriables
    void initVeriable();
    //declare init window
    void initWindow();


    //stages
    bool firstStageCompleted;
    bool portalEffect;
    Animation portalAnimation;
    bool setAnimation;

    //game objects
    void initEnemy();
    void initPlayer();
    void initCoin();
    void initFont();
    void initText();


    //coins
    float getNewPosition();
    void spawnCoins();
public:
    //construction
    Game();
    //deconstruct
    virtual ~Game();
    //check if the window is running
    const bool running() const;
    void spawnEnemy();
    void updateEnemies();
    void updateText();
    void updateHearts();
    void updateMousePos();
    void updateBackground();
    void updateCoins();
    void renderCoins();
    void renderEnemies();
    void renderHearts();
    void renderText();
    void pollEvents();
    void update(bool* const& restart);
    void render();
};
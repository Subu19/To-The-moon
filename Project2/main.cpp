#include <SFML/Graphics.hpp>
#include "Game.h"
int main()
{
    bool restart = false;

    srand(static_cast<unsigned>(time(NULL)));
    do{
        restart = false;
        Game game;
            while (game.running()) {

                game.update(&restart);
                game.render();

            };
    } while (restart);
   
    system("pause");
    return 0;
}
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "snake.h"
#include "eventsystem.h"

#define DIMEN 600
const float cellsize = DIMEN/24;

class Game
{
    public:
        Game();
        virtual ~Game();
        void run();

    private:
        sf::RenderWindow window;
        EventSystem eventSystem;

        Snake snake;
        sf::RectangleShape food;

        void processEvents();
        void generateFood();
};

#endif // GAME_H

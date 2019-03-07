#ifndef GAME_H
#define GAME_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include "snake.h"
#include "eventsystem.h"

#define DIMEN 600
#define GRID 24

const float cellsize = DIMEN/GRID;

class Game
{
    public:
        Game();
        virtual ~Game();
        void run();
        void closeGame();

    private:
        sf::RenderWindow window;

        Snake snake;
        sf::RectangleShape food;
        SnakeEvent snakeKey;

        void processEvents();
        void generateFood();
};

#endif // GAME_H

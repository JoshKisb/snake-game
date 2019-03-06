#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Game::Game():
    window(sf::VideoMode(DIMEN, DIMEN), "Snake Game"),
    food({cellsize, cellsize})
{
    window.setFramerateLimit(8);
    window.setKeyRepeatEnabled(false);
    std::srand(std::time(nullptr));

    food.setFillColor(sf::Color::Green);
}

Game::~Game()
{
    //dtor
}

void Game::run()
{
    float deltaTime;
    sf::Clock clock;
    generateFood();

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        // Process events
        processEvents();

        window.clear(sf::Color(58, 88, 98));


        if (snake.eat(food)) {
            generateFood();
        }

        snake.update(deltaTime);
        snake.draw(window);
        window.draw(food);
        // Update the window
        window.display();
    }
}

void Game::generateFood()
{
    float posX = (std::rand() % 24) * cellsize;
    float posY = (std::rand() % 24) * cellsize;

    food.setPosition(posX, posY);
}



void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        EventSystem::fire(SnakeEvent::UP);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        EventSystem::fire(SnakeEvent::DOWN);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        EventSystem::fire(SnakeEvent::LEFT);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        EventSystem::fire(SnakeEvent::RIGHT);
}

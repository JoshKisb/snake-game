#include "game.h"
#include <cstdlib>
#include <ctime>

Game::Game():
    window(sf::VideoMode(DIMEN, DIMEN), "Snake Game", sf::Style::Close),
    food({cellsize, cellsize}),
    snakeKey(SnakeEvent::NONE)
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

        snake.update(deltaTime);

        if (snake.eat(food)) {
            generateFood();
        }

        snake.draw(window);
        window.draw(food);
        // Update the window
        window.display();
    }
}

void Game::closeGame(){
    window.close();
}

void Game::generateFood()
{
    sf::Vector2f pos;
    do {
        pos = {(std::rand() % GRID) * cellsize, (std::rand() % GRID) * cellsize};
    } while(snake.checkCollision(pos) || pos == snake.getPosition());

    food.setPosition(pos);
}


void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        switch(event.type){
            case sf::Event::Closed:
                window.close();break;
            case sf::Event::KeyPressed:{
                switch(event.key.code){
                    case sf::Keyboard::Up: snakeKey = SnakeEvent::UP; break;
                    case sf::Keyboard::Down: snakeKey = SnakeEvent::DOWN; break;
                    case sf::Keyboard::Left: snakeKey = SnakeEvent::LEFT; break;
                    case sf::Keyboard::Right: snakeKey = SnakeEvent::RIGHT; break;
                    case sf::Keyboard::Escape: closeGame(); break;
                    default: break;
                }
            }
            default: break;
        }
    }
    EventSystem::fire(snakeKey);
    snakeKey = SnakeEvent::NONE;
}

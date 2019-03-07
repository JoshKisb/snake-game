#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>

class Snake
{
    public:
        Snake();
        virtual ~Snake();
        void draw(sf::RenderWindow& window);
        void update(float deltaTime);
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        bool eat(sf::RectangleShape& food);
        bool checkCollision(sf::Vector2f);
        sf::Vector2f getPosition();

    private:
        std::vector<sf::RectangleShape> m_tail;
        sf::RectangleShape m_head;
        sf::Vector2f m_velocity;
        unsigned int m_total = 0;

        sf::Vector2f nextPosition();
};

#endif // SNAKE_H

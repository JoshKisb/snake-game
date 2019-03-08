#include "snake.h"
#include "eventsystem.h"
#include "game.h"


Snake::Snake() : m_head({cellsize, cellsize})
{
    m_head.setPosition(0, 0);
    m_head.setFillColor(sf::Color::Red);

    EventSystem::addListerner(SnakeEvent::UP, std::bind(&Snake::moveUp, this));
    EventSystem::addListerner(SnakeEvent::DOWN, std::bind(&Snake::moveDown, this));
    EventSystem::addListerner(SnakeEvent::LEFT, std::bind(&Snake::moveLeft, this));
    EventSystem::addListerner(SnakeEvent::RIGHT, std::bind(&Snake::moveRight, this));

    m_velocity.x = cellsize;
    m_velocity.y = 0;
}

Snake::~Snake()
{
    //dtor
}
void Snake::draw(sf::RenderWindow& window)
{
    window.draw(m_head);
    for (sf::RectangleShape& cell: m_tail) {
        window.draw(cell);
    }
}

sf::Vector2f Snake::nextPosition()
{
    sf::Vector2f headPos = m_head.getPosition();

    headPos += m_velocity;

    if (headPos.x >= DIMEN) {
        headPos.x = 0;
    }
    else if (headPos.x < 0) {
        headPos.x = DIMEN - cellsize;
    }
    else if (headPos.y >= DIMEN) {
        headPos.y = 0;
    }
    else if (headPos.y < 0) {
        headPos.y = DIMEN - cellsize;
    }

    return headPos;
}


bool Snake::eat(sf::RectangleShape& food)
{
    sf::Vector2f headPos = m_head.getPosition();
    sf::Vector2f foodPos = food.getPosition(); 

    if (headPos == foodPos) {
        m_total++;
        return true;
    }

    return false;
}

bool Snake::checkCollision(sf::Vector2f pos)
{
    for (sf::RectangleShape& cell: m_tail) {
        if (pos == cell.getPosition())
            return true;
    }
    return false;
}

sf::Vector2f Snake::getPosition()
{
    return m_head.getPosition();
}


void Snake::update(float deltaTime)
{
    sf::Vector2f headPos = m_head.getPosition();

    if (m_total > m_tail.size()) {
        sf::RectangleShape cell({cellsize, cellsize});
        cell.setOutlineThickness(1);
        cell.setOutlineColor(sf::Color(250, 150, 100));
        cell.setPosition(headPos);
        m_tail.push_back(cell);
    } else {
        if (m_total > 0) {
            for (unsigned int i = 0; i + 1 < m_total; i++) {
                m_tail.at(i).setPosition(m_tail.at(i + 1).getPosition());
            }
            m_tail.back().setPosition(headPos);
        }
    }

    m_head.setPosition(nextPosition());

    if (checkCollision(m_head.getPosition())) {
        m_tail.clear();
        m_total = 0;
    }
}

void Snake::moveUp()
{
    if (m_velocity.y != cellsize) {
        m_velocity.y = -cellsize;
        m_velocity.x = 0;
    }
}

void Snake::moveDown()
{
    if (m_velocity.y != -cellsize) {
        m_velocity.y = cellsize;
        m_velocity.x = 0;
    }
}

void Snake::moveLeft()
{
    if (m_velocity.x != cellsize) {
        m_velocity.y = 0;
        m_velocity.x = -cellsize;
    }
}

void Snake::moveRight()
{
    if (m_velocity.x != -cellsize) {
        m_velocity.y = 0;
        m_velocity.x = cellsize;
    }
}


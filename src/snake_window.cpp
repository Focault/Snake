#include <SFML/Graphics.hpp>
#include <list>
#include <utility>

#include "snake_window.hpp"
#include "snake_snake.hpp"
#include "snake_treat.hpp"
#include "snake_board.hpp"

namespace snake {

void Window::draw(const Snake& a_snake, const Treat& a_treat) {
    drawFrame();
    drawSnake(a_snake);
    drawTreat(a_treat);
    m_window.display();
}

void Window::drawSnake(const Snake& a_snake) {
    sf::Vector2f position;
    for (const auto& coordinates : a_snake.location()) {
        position.x = m_cubeSize.x * static_cast<float>(coordinates.first) + m_Xbuffer;
        position.y = m_cubeSize.y * static_cast<float>(coordinates.second) + m_Ybuffer;
        m_snakeBone.setPosition(position);
        m_window.draw(m_snakeBone);
    }
}

void Window::drawTreat(const Treat& a_treat) {
    std::pair<int, int> coordinates = a_treat.where();
    sf::Vector2f position;
    position.x = m_cubeSize.x * static_cast<float>(coordinates.first) + m_Xbuffer;
    position.y = m_cubeSize.y * static_cast<float>(coordinates.second) + m_Ybuffer;
    m_treat.setPosition(position);
    m_window.draw(m_treat);
}

} // snake
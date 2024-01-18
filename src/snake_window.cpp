#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include <utility>

#include "snake_window.hpp"
#include "snake_snake.hpp"
#include "snake_treat.hpp"
#include "snake_board.hpp"

namespace snake {

void Window::draw(const Snake& a_snake, const Treat& a_treat) {
    std::vector<sf::RectangleShape> snakeVector;
    m_window.clear(sf::Color(176, 238, 23, 1));
    const std::list<std::pair<int, int> >& snakeLocation = a_snake.location();
    for (const auto& coordinates : snakeLocation) {
        snakeVector.emplace_back(m_cubeSize);
        sf::RectangleShape& cube = snakeVector.back();
        cube.setFillColor(sf::Color::Black);
        sf::Vector2f position;
        position.x = m_cubeSize.x * static_cast<float>(coordinates.first);
        position.y = m_cubeSize.y * static_cast<float>(coordinates.second);
        cube.setPosition(position);
        m_window.draw(cube);
    }
    sf::RectangleShape treat(m_cubeSize);
    treat.setFillColor(sf::Color::Red);
    std::pair<int, int> coordinates = a_treat.where();
    sf::Vector2f position;
    position.x = m_cubeSize.x * static_cast<float>(coordinates.first);
    position.y = m_cubeSize.y * static_cast<float>(coordinates.second);
    treat.setPosition(position);
    m_window.draw(treat);
    m_window.display();
}

} // snake
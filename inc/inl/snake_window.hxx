#ifndef SNAKE_WINDOW_HXX
#define SNAKE_WINDOW_HXX

#include <SFML/Graphics.hpp>

#include "snake_board.hpp"

namespace snake {

inline Window::Window()
: m_window(sf::VideoMode::getDesktopMode(), "Snake", sf::Style::Fullscreen)
, m_cubeSize()
, m_snakeBone()
, m_treat()
{
    sf::Vector2u windowSize = m_window.getSize();
    m_cubeSize.x = static_cast<float>(windowSize.x) / c_xNumOfCubes;
    m_cubeSize.y = static_cast<float>(windowSize.y) / c_yNumOfCubes;
    sf::Vector2f drawingUnitSize = m_cubeSize;
    drawingUnitSize.x *= 0.9;
    drawingUnitSize.y *= 0.9;
    m_snakeBone.setFillColor(sf::Color::Black);
    m_snakeBone.setSize(drawingUnitSize);
    m_treat.setFillColor(sf::Color::Red);
    m_treat.setSize(drawingUnitSize);
}

inline bool Window::isOpen() const {
    return m_window.isOpen();
}

inline void Window::close() {
    m_window.close();
}

inline bool Window::pollEvent(sf::Event& a_event) {
    return m_window.pollEvent(a_event);
}

inline void Window::drawFrame() {
    m_window.clear(sf::Color(176, 238, 23, 1));
}

} // snake

#endif /* SNAKE_WINDOW_HXX */
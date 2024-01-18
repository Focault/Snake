#ifndef SNAKE_WINDOW_HXX
#define SNAKE_WINDOW_HXX

#include <SFML/Graphics.hpp>

#include "snake_board.hpp"

namespace snake {

inline Window::Window()
: m_window(sf::VideoMode::getDesktopMode(), "Snake", sf::Style::Fullscreen)
, m_cubeSize()
{
    sf::Vector2u windowSize = m_window.getSize();
    m_cubeSize.x = static_cast<float>(windowSize.x) / c_xNumOfCubes;
    m_cubeSize.y = static_cast<float>(windowSize.y) / c_yNumOfCubes;
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

} // snake

#endif /* SNAKE_WINDOW_HXX */
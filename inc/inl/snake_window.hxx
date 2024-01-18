#ifndef SNAKE_WINDOW_HXX
#define SNAKE_WINDOW_HXX

#include <SFML/Graphics.hpp>

#include "snake_board.hpp"

namespace snake {

inline Window::Window()
: m_window(sf::VideoMode::getDesktopMode(), "Snake", sf::Style::Fullscreen)
, m_cubeSize()
, m_frame()
, m_snakeBone()
, m_treat()
, m_Xbuffer()
, m_Ybuffer()
{
    setFrame();
    setElements();
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

inline void Window::setFrame() {
    constexpr float frameScale = 0.95;
    constexpr float bufferScale = 0.025;
    constexpr float outlineScale = 0.001;
    sf::Vector2u windowSize = m_window.getSize();
    sf::Vector2f frameSize(windowSize.x * frameScale, windowSize.y * frameScale);
    m_frame.setSize(frameSize);
    m_frame.setFillColor(sf::Color::Transparent);
    m_frame.setOutlineColor(sf::Color::Black);
    m_frame.setOutlineThickness(windowSize.x * outlineScale);
    m_Xbuffer = windowSize.x * bufferScale;
    m_Ybuffer = windowSize.y * bufferScale;
    m_frame.setPosition(m_Xbuffer, m_Ybuffer);
}

inline void Window::setElements() {
    constexpr float drawingCubeScale = 0.9;
    constexpr float originScale = -0.05;
    m_cubeSize.x = static_cast<float>(m_frame.getSize().x) / c_xNumOfCubes;
    m_cubeSize.y = static_cast<float>(m_frame.getSize().y) / c_yNumOfCubes;
    sf::Vector2f drawingUnitSize(m_cubeSize.x * drawingCubeScale, m_cubeSize.y * drawingCubeScale);
    m_snakeBone.setFillColor(sf::Color::Black);
    m_snakeBone.setSize(drawingUnitSize);
    m_snakeBone.setOrigin(drawingUnitSize.x * originScale, drawingUnitSize.y * originScale);
    m_treat.setFillColor(sf::Color::Red);
    m_treat.setSize(drawingUnitSize);
    m_treat.setOrigin(drawingUnitSize.x * originScale, drawingUnitSize.y * originScale);
}

inline void Window::drawFrame() {
    m_window.clear(sf::Color(176, 238, 23, 1));
    m_window.draw(m_frame);
}

} // snake

#endif /* SNAKE_WINDOW_HXX */
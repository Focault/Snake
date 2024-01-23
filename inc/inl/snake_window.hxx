#ifndef SNAKE_WINDOW_HXX
#define SNAKE_WINDOW_HXX

#include <SFML/Graphics.hpp>
#include <exception>
#include <string>

#include "snake_board.hpp"

namespace snake {

inline Window::Window()
: m_window(sf::VideoMode::getDesktopMode(), "Snake", sf::Style::Fullscreen)
, m_cubeSize()
, m_windowSize()
, m_frame()
, m_snakeBone()
, m_treat()
, m_font()
, m_scoreText()
, m_title()
, m_Xbuffer()
, m_Ybuffer()
{
    setFrame();
    setElements();
    setScore();
    setTitle();
    setOption();
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

inline void Window::drawScore(const Score& a_score) {
    m_scoreText.setString(std::to_string(a_score.score()));
    m_scoreText.setPosition(m_cubeSize.x, m_cubeSize.y / 2);
    m_window.draw(m_scoreText);
}

inline void Window::drawFrame() {
    m_window.clear(sf::Color(c_boardColour));
    m_window.draw(m_frame);
}

inline void Window::drawTitle(const std::string& a_title) {
    drawTitle(a_title.c_str());
}

inline void Window::drawTitle(const char* a_title) {
    m_title.setString(a_title);
    centerOrigin(m_title);
    m_window.draw(m_title);
}

inline void Window::centerOrigin(sf::Text& a_text) {
    sf::FloatRect textBounds = a_text.getLocalBounds();
    a_text.setOrigin(textBounds.left + textBounds.width / 2.0f, 
                      textBounds.top + textBounds.height / 2.0f);
}

} // snake

#endif /* SNAKE_WINDOW_HXX */
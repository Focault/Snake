#include "snake_game.hpp"
#include "snake_snake.hpp"
#include "snake_treat.hpp"

namespace snake {

void Game::run() noexcept {
    while (m_window.isOpen()) {
        handleEvents();
        if (m_focus && m_time.isFrame(m_fps)) {
            m_functunality[m_mode]->makeMove();
        }
    }
}

void Game::handleEvents() {
    while (m_window.pollEvent(m_event)) {
        switch (m_event.type) {

            case sf::Event::Closed:
                m_window.close();
                break;

            case sf::Event::KeyPressed:
                m_functunality[m_mode]->keyPressed(m_event.key.code);
                break;

            case sf::Event::LostFocus:
                m_focus = false;
                break;

            case sf::Event::GainedFocus:
                m_focus = true;
                break;

            default:
                break;
        }
    }
}

} // snake
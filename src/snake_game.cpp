#include "snake_game.hpp"
#include "snake_snake.hpp"
#include "snake_treat.hpp"

namespace snake {

void Game::run() noexcept {
    // m_window.menu();
    m_treat.replace(m_snake);
    while (m_window.isOpen()) {
        handleEvents();
        if (m_focus && m_time.isFrame(m_fps)) {
            m_snake.advance();
            if (m_snake.isEating(m_treat.where())) {
                ++m_fps;
                if (m_snake.hasWon()) {
                    // m_window.playAgain("You Won!");
                    resetGame();
                    continue;
                }
                m_treat.replace(m_snake);
            } else if (m_snake.isDead()) {
                // m_window.playAgain("Game Over!");
                resetGame();
                continue;
            }
            m_window.draw(m_snake, m_treat);
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
                keyPressed();
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

void Game::keyPressed() noexcept {
    switch (m_event.key.code) {
        case sf::Keyboard::Up:
            m_snake.changeDirection(c_up);
            break;
        case sf::Keyboard::Down:
            m_snake.changeDirection(c_down);
            break;
        case sf::Keyboard::Left:
            m_snake.changeDirection(c_left);
            break;
        case sf::Keyboard::Right:
            m_snake.changeDirection(c_right);
            break;
        case sf::Keyboard::Escape:
            m_window.close();
            break;
        default:
            break;
    }
}

} // snake
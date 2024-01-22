#include "snake_game_logic.hpp"

#include <SFML/Window/Event.hpp>

#include "snake_logic.hpp"
#include "snake_window.hpp"
#include "snake_score.hpp"
#include "snake_snake.hpp"
#include "snake_treat.hpp"
#include "snake_board.hpp"

namespace snake {

void GameLogic::makeMove() {
    m_snake.advance();
    if (m_snake.isEating(m_treat.where())) {
        m_fps += c_advanceFPSby;
        m_score.addScore();
        if (m_snake.hasWon()) {
            resetGame();
            return;
        }
        m_treat.replace(m_snake);
    } else if (m_snake.isDead()) {
        resetGame();
        return;
    }
    m_window.draw(m_snake, m_treat, m_score);
}

void GameLogic::keyPressed(sf::Keyboard::Key a_keyPressed) {
    switch (a_keyPressed) {
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

void GameLogic::resetGame() noexcept {
    m_snake.reset();
    m_treat.replace(m_snake);
    m_fps = c_startFPS;
    m_mode = PLAY_AGAIN;
}

} // snake
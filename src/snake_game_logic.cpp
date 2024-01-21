#include "snake_game_logic.hpp"

#include <SFML/Window/Event.hpp>

#include "snake_logic.hpp"
#include "snake_window.hpp"
#include "snake_score.hpp"
#include "snake_snake.hpp"
#include "snake_treat.hpp"
#include "snake_board.hpp"

namespace snake {

void GameLogic::makeMove(Window& a_window, float& a_fps, LogicMode& a_mode, Score& a_score) {
    m_snake.advance();
    if (m_snake.isEating(m_treat.where())) {
        a_fps += c_advanceFPSby;
        a_score.addScore();
        if (m_snake.hasWon()) {
            resetGame(a_fps, a_mode);
            return;
        }
        m_treat.replace(m_snake);
    } else if (m_snake.isDead()) {
        a_score.resetScore();
        resetGame(a_fps, a_mode);
        return;
    }
    a_window.draw(m_snake, m_treat);
}

void GameLogic::keyPressed(sf::Keyboard::Key a_keyPressed, Window& a_window) {
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
        a_window.close();
        break;
    default:
        break;
    }
}

void GameLogic::resetGame(float& a_fps, LogicMode& a_mode) noexcept {
    m_snake.reset();
    m_treat.replace(m_snake);
    a_fps = c_startFPS;
    a_mode = PLAY_AGAIN;
}

} // snake
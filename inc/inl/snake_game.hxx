#ifndef SNAKE_GAME_HXX
#define SNAKE_GAME_HXX

namespace snake {

inline Game::Game()
: m_window()
, m_event()
, m_time()
, m_snake()
, m_treat()
, m_fps(c_startFPS)
, m_focus(true)
{}

inline void Game::resetGame() noexcept {
    m_snake.reset();
    m_treat.replace(m_snake);
    m_fps = c_startFPS;
}

} // snake

#endif /* SNAKE_GAME_HXX */
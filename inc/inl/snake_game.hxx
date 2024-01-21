#ifndef SNAKE_GAME_HXX
#define SNAKE_GAME_HXX

#include "snake_logic.hpp"
#include "snake_board.hpp"

namespace snake {

inline Game::Game(functunality& a_functunality)
: m_window()
, m_event()
, m_time()
, m_mode(MENU)
, m_functunality(a_functunality)
, m_score()
, m_fps(c_startFPS)
, m_focus(true)
{}

} // snake

#endif /* SNAKE_GAME_HXX */
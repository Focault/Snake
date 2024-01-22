#ifndef SNAKE_GAME_HXX
#define SNAKE_GAME_HXX

#include "snake_logic.hpp"
#include "snake_board.hpp"
#include "snake_functionality_factory.hpp"

namespace snake {

inline Game::Game()
: m_window()
, m_event()
, m_time()
, m_mode(MENU)
, m_score()
, m_fps(c_startFPS)
, m_focus(true)
, m_functunality()
{
    FunctionalityFactory().loadFunctionality(m_functunality, m_window, m_fps, m_mode, m_score);
}

} // snake

#endif /* SNAKE_GAME_HXX */
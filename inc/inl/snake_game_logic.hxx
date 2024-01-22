#ifndef SNAKE_GAME_LOGIC_HXX
#define SNAKE_GAME_LOGIC_HXX

namespace snake {

inline GameLogic::GameLogic(Window& a_window, float& a_fps, LogicMode& a_mode, Score& a_score)
: m_snake()
, m_treat()
, m_window(a_window)
, m_fps(a_fps)
, m_mode(a_mode)
, m_score(a_score)
{
    m_treat.replace(m_snake);
}

} // snake

#endif /* SNAKE_GAME_LOGIC_HXX */
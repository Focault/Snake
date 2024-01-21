#ifndef SNAKE_GAME_LOGIC_HXX
#define SNAKE_GAME_LOGIC_HXX

namespace snake {

inline GameLogic::GameLogic()
: m_snake()
, m_treat()
{
    m_treat.replace(m_snake);
}

} // snake

#endif /* SNAKE_GAME_LOGIC_HXX */
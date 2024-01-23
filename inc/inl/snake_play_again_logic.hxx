#ifndef SNAKE_PLAY_AGAIN_LOGIC_HXX
#define SNAKE_PLAY_AGAIN_LOGIC_HXX

#include "snake_window.hpp"

namespace snake {

enum PlayAgainOptions {
    PLAY_AGAIN_BUTTON = 0,
    QUIT_TO_MENU_BUTTON
};

inline PlayAgainLogic::PlayAgainLogic(Window& a_window, LogicMode& a_mode, Score& a_score)
: MenuLogic(a_window, a_mode, a_score)
{
    boot();
}

inline void PlayAgainLogic::boot() {
    m_buttons.emplace_back("Play Again?");
    m_buttons.emplace_back("Quit to Menu");
}

inline void PlayAgainLogic::draw() {
    m_window.playAgain(m_buttons, m_selection, m_score);
}

inline void PlayAgainLogic::selected() {
    switch (m_selection) {
    case PLAY_AGAIN_BUTTON:
        m_score.resetScore();
        m_mode = GAME;
        break;
    
    case QUIT_TO_MENU_BUTTON:
        m_score.resetScore();
        m_mode = MENU;
        break;

    default:
        break;
    }
}

} // snake

#endif /* SNAKE_PLAY_AGAIN_LOGIC_HXX */
#ifndef SNAKE_MAIN_MENU_LOGIC_HXX
#define SNAKE_MAIN_MENU_LOGIC_HXX

#include <vector>

#include "snake_window.hpp"

namespace snake {

enum MainMenuOptions {
    PLAY_BUTTON = 0,
    QUIT_BUTTON
};

inline MainMenuLogic::MainMenuLogic(Window& a_window, LogicMode& a_mode, Score& a_score)
: MenuLogic(a_window, a_mode, a_score) 
{
    boot();
}

inline void MainMenuLogic::boot() {
    m_buttons.emplace_back("Play!");
    m_buttons.emplace_back("Quit Game");
}

inline void MainMenuLogic::draw() {
    m_window.menu(m_buttons, m_selection);
}

inline void MainMenuLogic::selected() {
    switch (m_selection) {
    case PLAY_BUTTON:
        m_mode = GAME;
        break;
    
    case QUIT_BUTTON:
        m_window.close();

    default:
        break;
    }
}

} // snake

#endif /* SNAKE_MAIN_MENU_LOGIC_HXX */
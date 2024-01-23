#ifndef SNAKE_MENU_LOGIC_HXX
#define SNAKE_MENU_LOGIC_HXX

#include <SFML/Window/Event.hpp>

#include "snake_window.hpp"
#include "snake_logic.hpp"
#include "snake_score.hpp"

namespace snake {

inline MenuLogic::MenuLogic(Window& a_window, LogicMode& a_mode, Score& a_score)
: m_window(a_window)
, m_mode(a_mode)
, m_score(a_score)
, m_selection(0)
, m_buttons()
, m_changed(true)
{}

inline void MenuLogic::makeMove() {
    if (m_changed) {
        draw();
        m_changed = false;
    }
}

inline void MenuLogic::keyPressed(sf::Keyboard::Key a_keyPressed) {
    switch (a_keyPressed) {
    case sf::Keyboard::Up:
        m_selection = (m_selection + m_buttons.size() - 1) % m_buttons.size(); 
        m_changed = true;
        break;
    
    case sf::Keyboard::Down:
        m_selection = (m_selection + 1) % m_buttons.size(); 
        m_changed = true;
        break;

    case sf::Keyboard::Space:
    case sf::Keyboard::Enter:
        selected(); 
        m_selection = 0;
        m_changed = true;
        break;

    case sf::Keyboard::Escape:
        m_score.resetScore();
        m_window.close(); 
        break;

    default:
        break;
    }
}

} // snake

#endif /* SNAKE_MENU_LOGIC_HXX */
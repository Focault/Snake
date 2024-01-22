#ifndef SNAKE_MENU_LOGIC_HXX
#define SNAKE_MENU_LOGIC_HXX

#include <SFML/Window/Event.hpp>

namespace snake {

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

inline MenuLogic::MenuLogic(Window& a_window, LogicMode& a_mode, Score& a_score)
: m_window(a_window)
, m_mode(a_mode)
, m_score(a_score)
{}

inline void MenuLogic::makeMove() {
    m_mode = GAME;
    m_score.resetScore();
}

inline void MenuLogic::keyPressed(sf::Keyboard::Key a_keyPressed) {

}

#pragma GCC diagnostic pop

} // snake

#endif /* SNAKE_MENU_LOGIC_HXX */
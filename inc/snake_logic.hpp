#ifndef SNAKE_LOGIC_HPP
#define SNAKE_LOGIC_HPP

#include <SFML/Window/Event.hpp>

#include "snake_window.hpp"
#include "snake_score.hpp"

namespace snake {

enum LogicMode {
    GAME = 0,
    MENU,
    PLAY_AGAIN
};

class Logic {
public:
    virtual ~Logic() = default;

    virtual void makeMove(Window& a_window, float& a_fps, LogicMode& a_mode, Score& a_score) = 0;

    virtual void keyPressed(sf::Keyboard::Key a_keyPressed, Window& a_window) = 0;

protected:
    Logic() = default;
    Logic(const Logic& a_other) = default;
    Logic& operator=(const Logic& a_other) = default;
};

} // snake

#endif /* SNAKE_LOGIC_HPP */
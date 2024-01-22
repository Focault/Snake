#ifndef SNAKE_LOGIC_HPP
#define SNAKE_LOGIC_HPP

#include <SFML/Window/Event.hpp>

namespace snake {

enum LogicMode {
    GAME = 0,
    MENU,
    PLAY_AGAIN
};

class Logic {
public:
    virtual ~Logic() = default;

    virtual void makeMove() = 0;

    virtual void keyPressed(sf::Keyboard::Key a_keyPressed) = 0;

protected:
    Logic() = default;
    Logic(const Logic& a_other) = default;
    Logic& operator=(const Logic& a_other) = default;
};

} // snake

#endif /* SNAKE_LOGIC_HPP */
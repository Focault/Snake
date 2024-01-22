#ifndef SNAKE_MENU_LOGIC_HPP
#define SNAKE_MENU_LOGIC_HPP

#include <SFML/Window/Event.hpp>

#include "snake_logic.hpp"
#include "snake_window.hpp"
#include "snake_score.hpp"

namespace snake {

class MenuLogic : public Logic {
public:
    MenuLogic(Window& a_window, LogicMode& a_mode, Score& a_score);
    MenuLogic(const MenuLogic& a_other) = delete;
    MenuLogic& operator=(const MenuLogic& a_other) = delete;
    ~MenuLogic() = default;

    virtual void makeMove() override;

    virtual void keyPressed(sf::Keyboard::Key a_keyPressed) override;

protected:
    Window& m_window;
    LogicMode& m_mode;
    Score& m_score;
};

} // snake

#include "snake_menu_logic.hxx"

#endif /* SNAKE_MENU_LOGIC_HPP */
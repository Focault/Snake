#ifndef SNAKE_MENU_LOGIC_HPP
#define SNAKE_MENU_LOGIC_HPP

#include <SFML/Window/Event.hpp>

#include "snake_logic.hpp"
#include "snake_window.hpp"
#include "snake_score.hpp"

namespace snake {

class MenuLogic : public Logic {
public:
    MenuLogic() = default;
    MenuLogic(const MenuLogic& a_other) = delete;
    MenuLogic& operator=(const MenuLogic& a_other) = delete;
    ~MenuLogic() = default;

    virtual void makeMove(Window& a_window, float& a_fps, LogicMode& a_mode, Score& a_score) override;

    virtual void keyPressed(sf::Keyboard::Key a_keyPressed, Window& a_window) override;
};

} // snake

#include "snake_menu_logic.hxx"

#endif /* SNAKE_MENU_LOGIC_HPP */
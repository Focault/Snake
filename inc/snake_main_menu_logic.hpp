#ifndef SNAKE_MAIN_MENU_LOGIC_HPP
#define SNAKE_MAIN_MENU_LOGIC_HPP

#include "snake_menu_logic.hpp"
#include "snake_logic.hpp"
#include "snake_window.hpp"
#include "snake_score.hpp"

namespace snake {

class MainMenuLogic : public MenuLogic {
public:
    MainMenuLogic(Window& a_window, LogicMode& a_mode, Score& a_score);

    void boot();
    virtual void draw() override;
    virtual void selected() override;
};

} // snake

#include "snake_main_menu_logic.hxx"

#endif /* SNAKE_MAIN_MENU_LOGIC_HPP */
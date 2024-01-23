#ifndef SNAKE_PLAY_AGAIN_LOGIC_HPP
#define SNAKE_PLAY_AGAIN_LOGIC_HPP

#include "snake_menu_logic.hpp"
#include "snake_logic.hpp"
#include "snake_window.hpp"
#include "snake_score.hpp"

namespace snake {

class PlayAgainLogic : public MenuLogic {
public:
    PlayAgainLogic(Window& a_window, LogicMode& a_mode, Score& a_score);

    void boot();
    virtual void draw() override;
    virtual void selected() override;
};

} // snake

#include "snake_play_again_logic.hxx"

#endif /* SNAKE_PLAY_AGAIN_LOGIC_HPP */
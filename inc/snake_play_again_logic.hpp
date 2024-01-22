#ifndef SNAKE_PLAY_AGAIN_LOGIC_HPP
#define SNAKE_PLAY_AGAIN_LOGIC_HPP

#include "snake_menu_logic.hpp"

namespace snake {

class PlayAgainLogic : public MenuLogic {
public:
    using MenuLogic::MenuLogic;
};

} // snake

#include "snake_play_again_logic.hxx"

#endif /* SNAKE_PLAY_AGAIN_LOGIC_HPP */
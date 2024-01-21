#ifndef SNAKE_FUNCTIONALITY_FACTORY_HXX
#define SNAKE_FUNCTIONALITY_FACTORY_HXX

#include "snake_game.hpp"
#include "snake_logic.hpp"
#include "snake_game_logic.hpp"
#include "snake_play_again_logic.hpp"
#include "snake_menu_logic.hpp"

namespace snake {

inline void FunctionalityFactory::loadFunctionality(Game::functionality& a_functionality) const {
    a_functionality[GAME] = std::make_unique<GameLogic>();
    a_functionality[PLAY_AGAIN] = std::make_unique<PlayAgainLogic>();
    a_functionality[MENU] = std::make_unique<MenuLogic>();
}

} // snake

#endif /* SNAKE_FUNCTIONALITY_FACTORY_HXX */
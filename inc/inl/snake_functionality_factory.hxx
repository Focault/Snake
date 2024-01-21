#ifndef SNAKE_FUNCTIONALITY_FACTORY_HXX
#define SNAKE_FUNCTIONALITY_FACTORY_HXX

#include "snake_game.hpp"
#include "snake_logic.hpp"
#include "snake_game_logic.hpp"
#include "snake_play_again_logic.hpp"
#include "snake_menu_logic.hpp"

namespace snake {

inline Game::functionality FunctionalityFactory::makeFunctionality() const {
    Game::functionality functions;
    functions[GAME] = std::make_unique<GameLogic>();
    functions[PLAY_AGAIN] = std::make_unique<PlayAgainLogic>();
    functions[MENU] = std::make_unique<MenuLogic>();
    return functions;
}

} // snake

#endif /* SNAKE_FUNCTIONALITY_FACTORY_HXX */
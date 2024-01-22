#ifndef SNAKE_FUNCTIONALITY_FACTORY_HXX
#define SNAKE_FUNCTIONALITY_FACTORY_HXX

#include "snake_game.hpp"
#include "snake_logic.hpp"
#include "snake_game_logic.hpp"
#include "snake_play_again_logic.hpp"
#include "snake_main_menu_logic.hpp"
#include "snake_window.hpp"
#include "snake_score.hpp"

namespace snake {

inline void FunctionalityFactory::loadFunctionality(Game::functionality& a_functionality, Window& a_window, float& a_fps, LogicMode& a_mode, Score& a_score) const {
    a_functionality[GAME] = std::make_unique<GameLogic>(a_window, a_fps, a_mode, a_score);
    a_functionality[PLAY_AGAIN] = std::make_unique<PlayAgainLogic>(a_window, a_mode, a_score);
    a_functionality[MENU] = std::make_unique<MainMenuLogic>(a_window, a_mode, a_score);
}

} // snake

#endif /* SNAKE_FUNCTIONALITY_FACTORY_HXX */
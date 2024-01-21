#include <unordered_map>

#include "snake_game.hpp"
#include "snake_logic.hpp"
#include "snake_game_logic.hpp"
#include "snake_play_again_logic.hpp"
#include "snake_menu_logic.hpp"

int main()
{
    using namespace snake;
    Game::functunality functions;
    functions[GAME] = std::make_unique<GameLogic>();
    functions[PLAY_AGAIN] = std::make_unique<PlayAgainLogic>();
    functions[MENU] = std::make_unique<MenuLogic>();
    Game game(functions);
    game.run();
    return 0;
}

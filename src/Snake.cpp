#include <unordered_map>

#include "snake_game.hpp"
#include "snake_logic.hpp"
#include "snake_game_logic.hpp"
#include "snake_play_again_logic.hpp"
#include "snake_menu_logic.hpp"

int main()
{
    using namespace snake;
    std::unordered_map<LogicMode, Logic*> functunality;
    functunality[GAME] = new GameLogic();
    functunality[PLAY_AGAIN] = new PlayAgainLogic();
    functunality[MENU] = new MenuLogic();
    Game game(functunality);
    game.run();
    for (auto& function : functunality) {
        delete function.second;
    }
    return 0;
}

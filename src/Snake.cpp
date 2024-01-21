#include <unordered_map>

#include "snake_game.hpp"
#include "snake_functionality_factory.hpp"

int main()
{
    using namespace snake;
    FunctionalityFactory factory;
    Game::functionality functions = factory.makeFunctionality();
    Game game(functions);
    game.run();
    return 0;
}

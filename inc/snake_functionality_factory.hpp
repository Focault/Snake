#ifndef SNAKE_FUNCTIONALITY_FACTORY_HPP
#define SNAKE_FUNCTIONALITY_FACTORY_HPP

#include "snake_game.hpp"
#include "snake_window.hpp"
#include "snake_logic.hpp"
#include "snake_score.hpp"

namespace snake {

class FunctionalityFactory {
public:
    FunctionalityFactory() = default;
    FunctionalityFactory(const FunctionalityFactory& a_other) = default;
    FunctionalityFactory& operator=(const FunctionalityFactory& a_other) = default;
    ~FunctionalityFactory() = default;

    void loadFunctionality(Game::functionality& a_functionality, Window& a_window, float& a_fps, LogicMode& a_mode, Score& a_score) const;
};

} // snake

#include "snake_functionality_factory.hxx"

#endif /* SNAKE_FUNCTIONALITY_FACTORY_HPP */
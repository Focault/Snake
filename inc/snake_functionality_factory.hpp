#ifndef SNAKE_FUNCTIONALITY_FACTORY_HPP
#define SNAKE_FUNCTIONALITY_FACTORY_HPP

#include "snake_game.hpp"

namespace snake {

class FunctionalityFactory {
public:
    FunctionalityFactory() = default;
    FunctionalityFactory(const FunctionalityFactory& a_other) = default;
    FunctionalityFactory& operator=(const FunctionalityFactory& a_other) = default;
    ~FunctionalityFactory() = default;

    void loadFunctionality(Game::functionality& a_functionality) const;
};

} // snake

#include "snake_functionality_factory.hxx"

#endif /* SNAKE_FUNCTIONALITY_FACTORY_HPP */
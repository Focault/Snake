#ifndef SNAKE_TREAT_HXX
#define SNAKE_TREAT_HXX

#include "snake_board.hpp"
#include "snake_snake.hpp"

#include <list>
#include <utility>
#include <exception>
#include <cstdlib>

namespace snake {

inline Treat::Treat() 
: m_location(c_xNumOfCubes / 2, c_yNumOfCubes / 2)
{}

inline const std::pair<int, int>& Treat::where() const noexcept {
    return m_location;
}

inline void Treat::replace(const Snake &a_snake)
{
    if (a_snake.location().size() == c_xNumOfCubes * c_yNumOfCubes) {
        throw std::overflow_error("No place to locate treat.");
    }
    changeLocation();
    while (isCollision(a_snake)) {
        changeLocation();
    }
}

inline void Treat::changeLocation() noexcept {
    m_location.first = rand() % c_xNumOfCubes;
    m_location.second = rand() % c_yNumOfCubes;
}

inline bool Treat::isCollision(const Snake &a_snake) noexcept {
    const std::list<std::pair<int, int> >& snakeLocations = a_snake.location();
    for (const auto& location : snakeLocations) {
        if (location == m_location) {
            return true;
        }
    }
    return false;
}

} // snake

#endif /* SNAKE_TREAT_HXX */
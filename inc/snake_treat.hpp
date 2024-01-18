#ifndef SNAKE_TREAT_HPP
#define SNAKE_TREAT_HPP

#include <utility>

#include "snake_snake.hpp"

namespace snake {

class Treat {
public:
    Treat();
    Treat(const Treat& a_other) = default;
    Treat& operator=(const Treat& a_other) = default;
    ~Treat() = default;

    const std::pair<int, int>& where() const noexcept;

    void replace(const Snake& a_snake);

private:
    void changeLocation() noexcept;
    bool isCollision(const Snake& a_snake) noexcept;

private:
    std::pair<int, int> m_location;
};

} // snake

#include "snake_treat.hxx"

#endif /* SNAKE_TREAT_HPP */
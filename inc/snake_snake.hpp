#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP

#include <list>
#include <utility>

namespace snake {

constexpr std::pair<int, int> c_up = {0, -1};
constexpr std::pair<int, int> c_down = {0, 1};
constexpr std::pair<int, int> c_left = {-1, 0};
constexpr std::pair<int, int> c_right = {1, 0};
constexpr std::pair<int, int> c_stop = {0, 0};

class Snake {
public:
    Snake();
    Snake(const Snake& a_other) = default;
    Snake& operator=(const Snake& a_other) = default;
    ~Snake() = default;

    bool isEating(const std::pair<int, int>& a_treatLocation) noexcept;
    bool isDead() const noexcept;
    bool hasWon() const noexcept;

    const std::list<std::pair<int, int> >& location() const noexcept;

    void advance() noexcept;
    void reset() noexcept;

    void changeDirection(std::pair<int, int> a_direction);

private:
    void start() noexcept;

private:
    std::list<std::pair<int, int> > m_snake; 
    std::pair<int, int> m_direction;
};

} // snake

#include "snake_snake.hxx"

#endif /* SNAKE_SNAKE_HPP */
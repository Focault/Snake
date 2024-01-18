#ifndef SNAKE_SNAKE_HXX
#define SNAKE_SNAKE_HXX

#include <utility>
#include <exception>
#include <cstdlib>

#include "snake_treat.hpp"
#include "snake_board.hpp"

namespace snake {

inline Snake::Snake() 
: m_snake(1, {c_xNumOfCubes / 2, c_yNumOfCubes / 2})
, m_direction(c_stop)
{
    start();
}

inline bool Snake::isEating(const std::pair<int, int>& a_treatLocation) noexcept {
    if (m_snake.front() == a_treatLocation) {
        m_snake.emplace_back(m_snake.back());
        return true;
    }
    return false;
}

inline bool Snake::isDead() const noexcept {
    const std::pair<int, int>& head = m_snake.front();
    if (head.first < 0 || head.first >= c_xNumOfCubes || 
        head.second < 0 || head.second >= c_yNumOfCubes) {
            return true;
    }
    for (auto& iter = ++m_snake.begin(); iter != m_snake.end(); ++iter) {
        if (*iter == head) {
            return true;
        }
    }
    return false;
}

inline bool Snake::hasWon() const noexcept {
    return m_snake.size() == c_xNumOfCubes * c_yNumOfCubes;
}

inline const std::list<std::pair<int, int> >& Snake::location() const noexcept {
    return m_snake;
}

inline void Snake::advance() noexcept {
    m_snake.emplace_front(m_snake.front().first + m_direction.first, 
                          m_snake.front().second + m_direction.second);
    m_snake.pop_back();
}

inline void Snake::reset() noexcept {
    start();
}

inline void Snake::changeDirection(std::pair<int, int> a_direction) {
    if (a_direction.first < -1 || a_direction.first > 1 ||
        a_direction.second < -1 || a_direction.second > 1 ||
        (a_direction.first != 0 && a_direction.second != 0)) {
            throw std::range_error("Illigal snake direction submitted.");
    }
    m_direction = a_direction;
}

inline void Snake::start() noexcept {
    constexpr int buffer = 2;
    m_direction.first = 0;
    m_direction.second = 0;
    m_snake.clear();
    m_snake.emplace_back(buffer + rand() % (c_xNumOfCubes - buffer), 
                         buffer + rand() % (c_yNumOfCubes - buffer));
}

} // snake

#endif /* SNAKE_SNAKE_HXX */
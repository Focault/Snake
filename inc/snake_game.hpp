#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include <SFML/Window.hpp>

#include "snake_window.hpp"
#include "sf_time.hpp"
#include "snake_snake.hpp"
#include "snake_treat.hpp"

namespace snake {

constexpr int c_startFPS = 5;

class Game {
public:
    Game();
    Game(const Game& a_other) = delete;
    Game& operator=(const Game& a_other) = delete;
    ~Game() = default;

    void run() noexcept;

private:
    void handleEvents();

    void resetGame() noexcept;

    void keyPressed() noexcept;

private:
    Window m_window;
    sf::Event m_event;
    sfml::Time m_time;
    Snake m_snake;
    Treat m_treat;
    int m_fps;
    bool m_focus;
};

} // snake

#include "snake_game.hxx"

#endif /* SNAKE_GAME_HPP */
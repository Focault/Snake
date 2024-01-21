#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include <SFML/Window.hpp>
#include <unordered_map>
#include <memory>

#include "snake_window.hpp"
#include "sf_time.hpp"
#include "snake_logic.hpp"
#include "snake_score.hpp"

namespace snake {

class Game {
public:
    using functionality = std::unordered_map<LogicMode, std::unique_ptr<Logic> >;
public:
    explicit Game(functionality& a_functunality);
    Game(const Game& a_other) = delete;
    Game& operator=(const Game& a_other) = delete;
    ~Game() = default;

    void run() noexcept;

private:
    void handleEvents();

private:
    Window m_window;
    sf::Event m_event;
    sfml::Time m_time;
    LogicMode m_mode;
    functionality& m_functunality;
    Score m_score;
    float m_fps;
    bool m_focus;
};

} // snake

#include "snake_game.hxx"

#endif /* SNAKE_GAME_HPP */
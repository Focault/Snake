#ifndef SNAKE_GAME_LOGIC_HPP
#define SNAKE_GAME_LOGIC_HPP

#include <SFML/Window/Event.hpp>

#include "snake_logic.hpp"
#include "snake_window.hpp"
#include "snake_score.hpp"
#include "snake_snake.hpp"
#include "snake_treat.hpp"

namespace snake {

constexpr float c_advanceFPSby = 0.2;

class GameLogic : public Logic {
public:
    GameLogic();
    GameLogic(const GameLogic& a_other) = delete;
    GameLogic& operator=(const GameLogic& a_other) = delete;
    ~GameLogic() = default;

    virtual void makeMove(Window& a_window, float& a_fps, LogicMode& a_mode, Score& a_score) override;

    virtual void keyPressed(sf::Keyboard::Key a_keyPressed, Window& a_window) override;

private:
    void resetGame(float& a_fps, LogicMode& a_mode) noexcept;

private:
    Snake m_snake;
    Treat m_treat;
};

} // snake

#include "snake_game_logic.hxx"

#endif /* SNAKE_GAME_LOGIC_HPP */
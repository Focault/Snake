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
    GameLogic(Window& a_window, float& a_fps, LogicMode& a_mode, Score& a_score);
    GameLogic(const GameLogic& a_other) = delete;
    GameLogic& operator=(const GameLogic& a_other) = delete;
    ~GameLogic() = default;

    virtual void makeMove() override;

    virtual void keyPressed(sf::Keyboard::Key a_keyPressed) override;

private:
    void resetGame() noexcept;

private:
    Snake m_snake;
    Treat m_treat;
    Window& m_window;
    float& m_fps;
    LogicMode& m_mode;
    Score& m_score;
};

} // snake

#include "snake_game_logic.hxx"

#endif /* SNAKE_GAME_LOGIC_HPP */
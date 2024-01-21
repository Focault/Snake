#ifndef SNAKE_PLAY_AGAIN_LOGIC_HPP
#define SNAKE_PLAY_AGAIN_LOGIC_HPP

#include <SFML/Window/Event.hpp>

#include "snake_logic.hpp"
#include "snake_window.hpp"
#include "snake_score.hpp"

namespace snake {

class PlayAgainLogic : public Logic {
public:
    PlayAgainLogic() = default;
    PlayAgainLogic(const PlayAgainLogic& a_other) = delete;
    PlayAgainLogic& operator=(const PlayAgainLogic& a_other) = delete;
    ~PlayAgainLogic() = default;

    virtual void makeMove(Window& a_window, float& a_fps, LogicMode& a_mode, Score& a_score) override;

    virtual void keyPressed(sf::Keyboard::Key a_keyPressed, Window& a_window) override;
};

} // snake

#include "snake_play_again_logic.hxx"

#endif /* SNAKE_PLAY_AGAIN_LOGIC_HPP */
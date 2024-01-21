#ifndef SNAKE_PLAY_AGAIN_LOGIC_HXX
#define SNAKE_PLAY_AGAIN_LOGIC_HXX

namespace snake {

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

void PlayAgainLogic::makeMove(Window& a_window, float& a_fps, LogicMode& a_mode, Score& a_score) {
    a_mode = GAME;
}

void PlayAgainLogic::keyPressed(sf::Keyboard::Key a_keyPressed, Window& a_window) {
    
}

#pragma GCC diagnostic pop

} // snake

#endif /* SNAKE_PLAY_AGAIN_LOGIC_HXX */
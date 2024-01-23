#ifndef SNAKE_WINDOW_HPP
#define SNAKE_WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "snake_snake.hpp"
#include "snake_treat.hpp"
#include "snake_score.hpp"

namespace snake {

constexpr char c_mainTitle[] = "SNAKE";

class Window {
public:
    Window();
    Window(const Window& a_other) = delete;
    Window& operator=(const Window& a_other) = delete;
    ~Window() = default;

    bool isOpen() const;

    void close();

    bool pollEvent(sf::Event& a_event);

    void draw(const Snake& a_snake, const Treat& a_treat, const Score& a_score);

    void menu(const std::vector<std::string>& a_options, uint8_t a_selection);

    void playAgain(const std::vector<std::string>& a_options, uint8_t a_selection, const Score& a_score);    

private:
    void setFrame();
    void setElements();
    void setScore();
    void setTitle();
    void setOption();

    void drawFrame();
    void drawScore(const Score& a_score);
    void drawSnake(const Snake& a_snake);
    void drawTreat(const Treat& a_treat);
    void drawOptions(const std::vector<std::string>& a_options, uint8_t a_selection);
    void drawTitle(const std::string& a_title);
    void drawTitle(const char* a_title);

    void centerOrigin(sf::Text& a_text);

private:
    sf::RenderWindow m_window;
    sf::Vector2f m_cubeSize;
    sf::Vector2u m_windowSize;
    sf::RectangleShape m_frame;
    sf::RectangleShape m_snakeBone;
    sf::RectangleShape m_treat;
    sf::Font m_font;
    sf::Text m_scoreText;
    sf::Text m_title;
    sf::Text m_option;
    float m_Xbuffer;
    float m_Ybuffer;
};

} // snake

#include "snake_window.hxx"

#endif /* SNAKE_WINDOW_HPP */
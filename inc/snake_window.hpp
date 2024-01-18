#ifndef SNAKE_WINDOW_HPP
#define SNAKE_WINDOW_HPP

#include <SFML/Graphics.hpp>

#include "snake_snake.hpp"
#include "snake_treat.hpp"

namespace snake {

class Window {
public:
    Window();
    Window(const Window& a_other) = delete;
    Window& operator=(const Window& a_other) = delete;
    ~Window() = default;

    bool isOpen() const;

    void close();

    bool pollEvent(sf::Event& a_event);

    void draw(const Snake& a_snake, const Treat& a_treat);

    // void menu();

    // void playAgain(std::string a_msg);    

private:
    void drawFrame();
    void drawSnake(const Snake& a_snake);
    void drawTreat(const Treat& a_treat);

private:
    sf::RenderWindow m_window;
    sf::Vector2f m_cubeSize;
    sf::RectangleShape m_snakeBone;
    sf::RectangleShape m_treat;
};

} // snake

#include "snake_window.hxx"

#endif /* SNAKE_WINDOW_HPP */
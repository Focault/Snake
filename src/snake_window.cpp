#include <SFML/Graphics.hpp>
#include <list>
#include <utility>

#include "snake_window.hpp"
#include "snake_snake.hpp"
#include "snake_treat.hpp"
#include "snake_score.hpp"
#include "snake_board.hpp"

namespace snake {

void Window::draw(const Snake& a_snake, const Treat& a_treat, const Score& a_score) {
    drawFrame();
    drawSnake(a_snake);
    drawTreat(a_treat);
    drawScore(a_score);
    m_window.display();
}

void Window::menu(const std::vector<std::string>& a_options, uint8_t a_selection) {
    drawFrame();
    drawTitle(c_mainTitle);
    drawOptions(a_options, a_selection);
    m_window.display();
}

void Window::playAgain(const std::vector<std::string>& a_options, uint8_t a_selection, const Score& a_score) {
    drawFrame();
    std::string statistics("Your Score: ");
    statistics += std::to_string(a_score.score());
    statistics += "\nBest Score: ";
    statistics += std::to_string(a_score.bestScore());
    drawTitle(statistics);
    drawOptions(a_options, a_selection);
    m_window.display();
}

void Window::setFrame() {
    constexpr float frameScale = 0.95;
    constexpr float bufferScale = 0.025;
    constexpr float outlineScale = 0.001;
    m_windowSize = m_window.getSize();
    sf::Vector2f frameSize(m_windowSize.x * frameScale, m_windowSize.y * frameScale);
    m_frame.setSize(frameSize);
    m_frame.setFillColor(sf::Color::Transparent);
    m_frame.setOutlineColor(sf::Color::Black);
    m_frame.setOutlineThickness(m_windowSize.x * outlineScale);
    m_Xbuffer = m_windowSize.x * bufferScale;
    m_Ybuffer = m_windowSize.y * bufferScale;
    m_frame.setPosition(m_Xbuffer, m_Ybuffer);
}

void Window::setElements() {
    constexpr float drawingCubeScale = 0.9;
    constexpr float originScale = -0.05;
    m_cubeSize.x = static_cast<float>(m_frame.getSize().x) / c_xNumOfCubes;
    m_cubeSize.y = static_cast<float>(m_frame.getSize().y) / c_yNumOfCubes;
    sf::Vector2f drawingUnitSize(m_cubeSize.x * drawingCubeScale, m_cubeSize.y * drawingCubeScale);
    m_snakeBone.setFillColor(sf::Color::Black);
    m_snakeBone.setSize(drawingUnitSize);
    m_snakeBone.setOrigin(drawingUnitSize.x * originScale, drawingUnitSize.y * originScale);
    m_treat.setFillColor(sf::Color::Red);
    m_treat.setSize(drawingUnitSize);
    m_treat.setOrigin(drawingUnitSize.x * originScale, drawingUnitSize.y * originScale);
}

void Window::setScore() {
    constexpr float scoreScale = 1.7;
    if (!m_scoreFont.loadFromFile("../resources/Minecrafter.Reg.ttf")) {
        throw std::runtime_error("Loading Font Failed.");
    }
    m_scoreText.setFont(m_scoreFont);
    m_scoreText.setCharacterSize(m_cubeSize.x / scoreScale);
    m_scoreText.setFillColor(sf::Color::Black);
}

void Window::setTitle() {
    m_title.setFont(m_scoreFont);
    m_title.setCharacterSize(m_cubeSize.x * 2);
    m_title.setFillColor(sf::Color::Black);
    m_title.setPosition(m_windowSize.x / 2, m_windowSize.y / 4);
}

void Window::setOption() {
    if (!m_optionFont.loadFromFile("../resources/Minercraftory.ttf")) {
        throw std::runtime_error("Loading Font Failed.");
    }
    m_option.setFont(m_optionFont);
    m_option.setFillColor(sf::Color::Black);
}

void Window::drawSnake(const Snake& a_snake) {
    sf::Vector2f position;
    for (const auto& coordinates : a_snake.location()) {
        position.x = m_cubeSize.x * static_cast<float>(coordinates.first) + m_Xbuffer;
        position.y = m_cubeSize.y * static_cast<float>(coordinates.second) + m_Ybuffer;
        m_snakeBone.setPosition(position);
        m_window.draw(m_snakeBone);
    }
}

void Window::drawTreat(const Treat& a_treat) {
    std::pair<int, int> coordinates = a_treat.where();
    sf::Vector2f position;
    position.x = m_cubeSize.x * static_cast<float>(coordinates.first) + m_Xbuffer;
    position.y = m_cubeSize.y * static_cast<float>(coordinates.second) + m_Ybuffer;
    m_treat.setPosition(position);
    m_window.draw(m_treat);
}

void Window::drawOptions(const std::vector<std::string>& a_options, uint8_t a_selection) {
    for (size_t i = 0; i < a_options.size(); ++i) {
        m_option.setString(a_options[i]);
        m_option.setCharacterSize(i == a_selection ? m_cubeSize.x * 1.7 : 
                                                     m_cubeSize.x * 1.2);
        centerOrigin(m_option);
        m_option.setPosition(m_windowSize.x / 2.0f, m_windowSize.y / (1.7f - (i * 0.5)));
        m_window.draw(m_option);
    }
}

} // snake
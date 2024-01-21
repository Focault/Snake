#ifndef SNAKE_SCORE_HPP
#define SNAKE_SCORE_HPP

#include <stdint.h>
#include <fstream>

namespace snake {

constexpr char c_scoreFileLocation[] = "../resources/score.txt";

class Score {
public:
    Score();
    Score(const Score& a_other) = delete;
    Score& operator=(const Score& a_other) = delete;
    ~Score() = default;

    uint16_t score() const noexcept;

    void addScore(uint16_t a_score = 1) noexcept;

    void resetScore() noexcept;

    uint16_t bestScore() const noexcept;

private:
    void updateBestScore();

private:
    uint16_t m_score;
    uint16_t m_bestScore;
    std::ofstream m_fileOut;
};

} // snake

#include "snake_score.hxx"

#endif /* SNAKE_SCORE_HPP */
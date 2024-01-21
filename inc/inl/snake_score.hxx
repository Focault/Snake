#ifndef SNAKE_SCORE_HXX
#define SNAKE_SCORE_HXX

#include <fstream>

#include "fsl_files.hpp"

namespace snake {

inline Score::Score()
: m_score(0)
, m_bestScore(0)
, m_fileOut(c_scoreFileLocation, std::ios_base::out | std::ios_base::app)
{
    std::ifstream fileIn(c_scoreFileLocation);
    fileIn >> m_bestScore;
    if (fileIn.eof()) {
        m_bestScore = 0;
        updateBestScore();
    }
}

inline uint16_t Score::score() const noexcept {
    return m_score;
}

inline void Score::addScore(uint16_t a_score) noexcept {
    m_score += a_score;
}

inline void Score::resetScore() noexcept {
    if (m_score > m_bestScore) {
        m_bestScore = m_score;
        fsl::ClearFile(c_scoreFileLocation);
        updateBestScore();
    }
    m_score = 0;
}

inline uint16_t Score::bestScore() const noexcept {
    return m_bestScore;
}

inline void Score::updateBestScore() {
    m_fileOut.seekp(0, std::ios::beg);
    m_fileOut << m_bestScore << std::endl;
    m_fileOut.flush();
}

} // snake

#endif /* SNAKE_SCORE_HXX */
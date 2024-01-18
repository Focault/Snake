#ifndef SF_TIME_HXX
#define SF_TIME_HXX

#include <SFML/Graphics.hpp>
#include <unistd.h>

namespace sfml {

inline Time::Time()
: m_clock()
{}

inline bool Time::isFrame(float a_fps) noexcept {
    constexpr int32_t milisecondsInSecond = 1000;
    constexpr int32_t microsecondsInMilisecond = 1000;
    sf::Time elapsed = m_clock.getElapsedTime();
    int32_t milisecondsPerFrame = milisecondsInSecond / a_fps;
    if (elapsed.asMilliseconds() >= milisecondsPerFrame) {
        m_clock.restart();
        return true;
    }
    usleep((milisecondsPerFrame - elapsed.asMilliseconds()) * microsecondsInMilisecond);
    return false;
}

} // sfml

#endif /* SF_TIME_HXX */
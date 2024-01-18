#ifndef SF_TIME_HXX
#define SF_TIME_HXX

namespace sfml {

inline Time::Time()
: m_clock()
{}

inline bool Time::isFrame(float a_fps) noexcept {
    constexpr int32_t milisecondsInSeconds = 1000;
    sf::Time elapsed = m_clock.getElapsedTime();
    if (elapsed.asMilliseconds() >= (milisecondsInSeconds / a_fps)) {
        m_clock.restart();
        return true;
    }
    return false;
}

} // sfml

#endif /* SF_TIME_HXX */
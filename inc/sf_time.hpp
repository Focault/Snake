#ifndef SF_TIME_HPP
#define SF_TIME_HPP

namespace sfml {

class Time {
public:
    Time();
    Time(const Time& a_other) = delete;
    Time& operator=(const Time& a_other) = delete;
    ~Time() = default;

    bool isFrame(int a_fps) noexcept;

private:
    sf::Clock m_clock;
};

} // sfml

#include "sf_time.hxx"

#endif /* SF_TIME_HPP */
#pragma once

#include "Point.hpp"

namespace adas
{
    class Direction final {
        public:
            static const Direction& GetDirection(const char heading) noexcept;

        public:
            Direction(const unsigned index, const char heading) noexcept;

            const Point& Move() const noexcept;
            const Direction& LeftOne() const noexcept;
            const Direction& RightOne() const noexcept;

            const char GetHeading() const noexcept;
        private:
            unsigned index;
            char heading;
    };
}
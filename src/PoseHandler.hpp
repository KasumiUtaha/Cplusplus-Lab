#pragma once

#include "Executor.hpp"
#include "Direction.hpp"

namespace adas
{
    class PoseHandler final {
        public:
            PoseHandler(const Pose& pose) noexcept;
            PoseHandler(const PoseHandler&) = delete;
            PoseHandler& operator=(const PoseHandler&) = delete;

        public:
            void Forward() noexcept;
            void Backward() noexcept;
            void TurnLeft() noexcept;
            void TurnRight() noexcept;
            void Fast() noexcept;
            void Reverse() noexcept;
            bool isFast() const noexcept;
            bool isReverse() const noexcept;
            Pose Query() const noexcept;
        
        private:
            Point point;
            const Direction* facing;
            bool fast{false};
            bool reverse{false};
    };
}
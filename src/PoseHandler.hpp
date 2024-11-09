#pragma once

#include "Executor.hpp"

namespace adas
{
    class PoseHandler final {
        public:
            PoseHandler(const Pose& pose) noexcept;
            PoseHandler(const PoseHandler&) = delete;
            PoseHandler& operator=(const PoseHandler&) = delete;

        public:
            void Move(int step = 1) noexcept;
            void TurnLeft() noexcept;
            void TurnRight() noexcept;
            void Fast() noexcept;
            bool isFast() const noexcept;
            Pose Query() const noexcept;
        
        private:
            Pose pose;
            bool fast{false};
    };
}
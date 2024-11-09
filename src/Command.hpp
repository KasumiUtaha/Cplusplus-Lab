#pragma once

#include "ExecutorImpl.hpp"
#include "PoseHandler.hpp"

#include <functional>

namespace adas
{
    // class ICommand
    // {
    // public:
    //     virtual ~ICommand() = default;

    //     virtual void DoOperate(PoseHandler& PoseHandler) const noexcept = 0;
    // };

    class MoveCommand final //: public ICommand
    {
    public:
        // ~MoveCommand() = default;

        // void DoOperate(PoseHandler& PoseHandler) const noexcept override
        // {
        //     if(PoseHandler.isFast()) PoseHandler.Move();
        //     PoseHandler.Move();
        // }

        const std::function<void(PoseHandler& PoseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
            if(poseHandler.isFast()) {
                poseHandler.Move();
            }
            poseHandler.Move();
        };
    };

    class TurnLeftCommand final //: public ICommand
    {
    public:
        // ~TurnLeftCommand() = default;

        // void DoOperate(PoseHandler& PoseHandler) const noexcept override
        // {
        //     if(PoseHandler.isFast()) PoseHandler.Move();
        //     PoseHandler.TurnLeft();
        // }

        const std::function<void(PoseHandler& PoseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
            if(poseHandler.isFast()) {
                poseHandler.Move();
            }
            poseHandler.TurnLeft();
        };
    };

    class TurnRightCommand final //: public ICommand
    {
    public:
        // ~TurnRightCommand() = default;

        // void DoOperate(PoseHandler& PoseHandler) const noexcept override
        // {
        //     if(PoseHandler.isFast()) PoseHandler.Move();
        //     PoseHandler.TurnRight();
        // }

        const std::function<void(PoseHandler& PoseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
            if(poseHandler.isFast()) {
                poseHandler.Move();
            }
            poseHandler.TurnRight();
        };
    };

    class FastCommand final //: public ICommand 
    {
    public:
        // ~FastCommand() = default;

        // void DoOperate(PoseHandler& PoseHandler) const noexcept override
        // {
        //     PoseHandler.Fast();
        // }

        const std::function<void(PoseHandler& PoseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
            poseHandler.Fast();
        };
    };
} 

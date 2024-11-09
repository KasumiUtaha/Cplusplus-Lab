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

        void operator()(PoseHandler& poseHandler) const noexcept {
            if(poseHandler.isFast()) {
                poseHandler.Move();
            }
            poseHandler.Move();
        }
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

        void operator()(PoseHandler& poseHandler) const noexcept {
            if(poseHandler.isFast()) {
                poseHandler.Move();
            }
            poseHandler.TurnLeft();
        }
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

        void operator()(PoseHandler& poseHandler) const noexcept {
            if(poseHandler.isFast()) {
                poseHandler.Move();
            }
            poseHandler.TurnRight();
        }
    };

    class FastCommand final //: public ICommand 
    {
    public:
        // ~FastCommand() = default;

        // void DoOperate(PoseHandler& PoseHandler) const noexcept override
        // {
        //     PoseHandler.Fast();
        // }

        void operator()(PoseHandler& poseHandler) const noexcept {
            poseHandler.Fast();
        }
    };
} 

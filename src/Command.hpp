#pragma once

#include "ExecutorImpl.hpp"

namespace adas
{
     class ICommand
    {
    public:
        virtual ~ICommand() = default;

        virtual void DoOperate(ExecutorImpl& executor) const noexcept = 0;
    };

    class MoveCommand final : public ICommand
    {
    public:
        ~MoveCommand() = default;

        void DoOperate(ExecutorImpl& executor) const noexcept override
        {
            if(executor.isFast()) executor.Move();
            executor.Move();
        }
    };

    class TurnLeftCommand final : public ICommand
    {
    public:
        ~TurnLeftCommand() = default;

        void DoOperate(ExecutorImpl& executor) const noexcept override
        {
            if(executor.isFast()) executor.Move();
            executor.TurnLeft();
        }
    };

    class TurnRightCommand final : public ICommand
    {
    public:
        ~TurnRightCommand() = default;

        void DoOperate(ExecutorImpl& executor) const noexcept override
        {
            if(executor.isFast()) executor.Move();
            executor.TurnRight();
        }
    };

    class FastCommand final : public ICommand 
    {
    public:
        ~FastCommand() = default;

        void DoOperate(ExecutorImpl& executor) const noexcept override
        {
            executor.Fast();
        }
    };
} 

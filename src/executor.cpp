#include "ExecutorImpl.hpp"
#include <tuple>
#include <iostream>

namespace adas {

    bool operator == (const Pose &lhs, const Pose &rhs) {
        return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
    }

    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept :pose(pose) {}

    Pose ExecutorImpl::Query() const noexcept {
        return pose;
    }

    unique_ptr<Executor> Executor::NewExecutor(const Pose &pose) noexcept {
        return std::make_unique<ExecutorImpl>(pose);
    }

    void ExecutorImpl::Move(int step) {
        switch(pose.heading) {
            case 'N': pose.y+=step; break;
            case 'S': pose.y-=step; break;
            case 'W': pose.x-=step; break;
            case 'E': pose.x+=step; break;
        }
    }

    void ExecutorImpl::TurnLeft() {
        switch (pose.heading)
        {
            case 'N': pose.heading = 'W'; break;
            case 'S': pose.heading = 'E'; break;
            case 'W': pose.heading = 'S'; break;
            case 'E': pose.heading = 'N'; break;
        }
    }

    void ExecutorImpl::TurnRight() {
        switch (pose.heading)
        {
            case 'N': pose.heading = 'E'; break;
            case 'S': pose.heading = 'W'; break;
            case 'W': pose.heading = 'N'; break;
            case 'E': pose.heading = 'S'; break;
        }
    }

    void ExecutorImpl::Execute(char c) {
        unique_ptr<ICommand> cmder;
        switch(c) {
            case 'M': {
                cmder = std::make_unique<MoveCommand>();
                cmder -> DoOperate(*this);
                break;
            }
            case 'L': {
                cmder = std::make_unique<TurnLeftCommand>();
                cmder -> DoOperate(*this);
                break;
            }
            case 'R': {
                cmder = std::make_unique<TurnRightCommand>();
                cmder -> DoOperate(*this);
                break;
            }
            default: std::cerr<<"Undefined Command!\n";
        }
    }

    void ExecutorImpl::Execute(const std::string& command) noexcept {
        for(auto c : command) {
            Execute(c);
        }
    }
} 
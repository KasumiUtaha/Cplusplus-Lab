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
        switch(c) {
            case 'M': Move(); break;
            case 'L': TurnLeft(); break;
            case 'R': TurnRight(); break;
            default: std::cerr<<"Undefined Command!\n";
        }
    }

    void ExecutorImpl::Execute(const std::string& command) noexcept {
        for(auto c : command) {
            Execute(c);
        }
    }
} 
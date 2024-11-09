#include "ExecutorImpl.hpp"
#include <tuple>
#include <iostream>
#include "Command.hpp"

namespace adas {

    // bool operator == (const Pose &lhs, const Pose &rhs) {
    //     return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
    // }

    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept :poseHandler(pose) {}

    unique_ptr<Executor> Executor::NewExecutor(const Pose &pose) noexcept {
        return std::make_unique<ExecutorImpl>(pose);
    }

    Pose ExecutorImpl::Query() const noexcept {
        return poseHandler.Query();
    }

    void ExecutorImpl::Execute(char c) {
        unique_ptr<ICommand> cmder;
        switch(c) {
            case 'M': {
                cmder = std::make_unique<MoveCommand>();
                break;
            }
            case 'L': {
                cmder = std::make_unique<TurnLeftCommand>();
                break;
            }
            case 'R': {
                cmder = std::make_unique<TurnRightCommand>();
                break;
            }
            case 'F': {
                cmder = std::make_unique<FastCommand>();
                break;
            }
            default: std::cerr<<"Undefined Command!\n";
        }
        if(cmder) {
            cmder -> DoOperate(poseHandler);
        }
    }

    void ExecutorImpl::Execute(const std::string& command) noexcept {
        for(auto c : command) {
            Execute(c);
        }
    }
} 
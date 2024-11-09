#include "ExecutorImpl.hpp"
#include <tuple>
#include <iostream>
#include "Command.hpp"
#include <unordered_map>

using std::unordered_map;

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
       unordered_map<char, std::function<void(PoseHandler& PoseHandler)> > cmderMap;
    //    cmderMap.emplace('M', std::make_unique<MoveCommand>());
    //    cmderMap.emplace('L', std::make_unique<TurnLeftCommand>());
    //    cmderMap.emplace('R', std::make_unique<TurnRightCommand>());
    //    cmderMap.emplace('F', std::make_unique<FastCommand>());

    //     const auto it = cmderMap.find(c);
    //     if(it != cmderMap.end()) {
    //         it -> second -> DoOperate(poseHandler);
    //     }
        MoveCommand moveCommand;
        cmderMap.emplace('M', moveCommand.operate);
        TurnLeftCommand turnLeftCommand;
        cmderMap.emplace('L', turnLeftCommand.operate);
        TurnRightCommand turnRightCommand;
        cmderMap.emplace('R', turnRightCommand.operate);
        FastCommand fastCommand;
        cmderMap.emplace('F', fastCommand.operate);
        const auto it = cmderMap.find(c);
        if(it != cmderMap.end()) {
            it -> second(poseHandler);
        }
    }

    void ExecutorImpl::Execute(const std::string& command) noexcept {
        for(auto c : command) {
            Execute(c);
        }
    }
} 
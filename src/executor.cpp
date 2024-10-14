#include "ExecutorImpl.hpp"
#include <tuple>

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
} 
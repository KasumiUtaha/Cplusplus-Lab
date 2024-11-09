#pragma once
#include "Executor.hpp"
#include "PoseHandler.hpp"

namespace adas {

    class ExecutorImpl: public Executor {
    private:
        PoseHandler poseHandler;
    public:
        explicit ExecutorImpl(const Pose& pose) noexcept;
        ~ExecutorImpl() noexcept = default;

        ExecutorImpl(const ExecutorImpl &) = delete;
        ExecutorImpl& operator =(const ExecutorImpl &) = delete;

        Pose Query() const noexcept override;

        void Execute(char c);

        void Execute(const std::string& command) noexcept override;
    };

}
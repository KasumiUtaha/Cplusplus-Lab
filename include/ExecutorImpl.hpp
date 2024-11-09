#pragma once
#include "Executor.hpp"


namespace adas {

    class ExecutorImpl: public Executor {
    private:
        Pose pose;
        bool fast{false};

    public:
        explicit ExecutorImpl(const Pose& pose) noexcept;
        ~ExecutorImpl() noexcept = default;

        ExecutorImpl(const ExecutorImpl &) = delete;
        ExecutorImpl& operator =(const ExecutorImpl &) = delete;

        void Move(int step = 1);
        void TurnLeft();
        void TurnRight();
        void Fast() noexcept;
        bool isFast() const noexcept;

        Pose Query() const noexcept override;

        void Execute(char c);

        void Execute(const std::string& command) noexcept override;
    };

}
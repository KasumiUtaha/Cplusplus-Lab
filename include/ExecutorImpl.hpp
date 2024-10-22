#include "Executor.hpp"


namespace adas {

    class ExecutorImpl: public Executor {
    private:
        Pose pose;
        bool isFast;
    public:
        explicit ExecutorImpl(const Pose& pose) noexcept;
        ~ExecutorImpl() noexcept = default;

        ExecutorImpl(const ExecutorImpl &) = delete;
        ExecutorImpl& operator =(const ExecutorImpl &) = delete;

        Pose Query() const noexcept override;

        void Move(int step = 1);

        void TurnLeft();

        void TurnRight();

        void Execute(char c);

        void Execute(const std::string& command) noexcept override;
    };

}
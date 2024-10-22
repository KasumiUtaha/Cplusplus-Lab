#include "Executor.hpp"


namespace adas {

    class ExecutorImpl: public Executor {
    private:
        Pose pose;
        bool isFast;

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
                executor.Move();
            }
        };

        class TurnLeftCommand final : public ICommand
        {
        public:
            ~TurnLeftCommand() = default;

            void DoOperate(ExecutorImpl& executor) const noexcept override
            {
                executor.TurnLeft();
            }
        };

        class TurnRightCommand final : public ICommand
        {
        public:
            ~TurnRightCommand() = default;

            void DoOperate(ExecutorImpl& executor) const noexcept override
            {
                executor.TurnRight();
            }
        };

    public:
        explicit ExecutorImpl(const Pose& pose) noexcept;
        ~ExecutorImpl() noexcept = default;

        ExecutorImpl(const ExecutorImpl &) = delete;
        ExecutorImpl& operator =(const ExecutorImpl &) = delete;

        void Move(int step = 1);

        void TurnLeft();

        void TurnRight();

        Pose Query() const noexcept override;

        void Execute(char c);

        void Execute(const std::string& command) noexcept override;
    };

}
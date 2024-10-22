#include "Executor.hpp"


namespace adas {

    class ExecutorImpl: public Executor {
    private:
        Pose pose;
        bool fast{false};

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

        void Move(int step = 1);

        void TurnLeft();

        void TurnRight();

        void Fast() noexcept;

        bool isFast() const noexcept;


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
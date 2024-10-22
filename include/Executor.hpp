#pragma once
#include<string>
#include <memory>
using std::shared_ptr;
using std::unique_ptr;

namespace adas {
    struct Pose {
        int x;
        int y;
        char heading;

        friend bool operator == (const Pose &lhs, const Pose &rhs);
    };

    class Executor {
    public:
        static unique_ptr<Executor> NewExecutor(const Pose& pose = {0,0,'N'}) noexcept;

        Executor() = default;

        virtual ~Executor() = default;

        Executor(const Executor&) = delete;
        Executor& operator = (const Executor&) = delete;

        virtual void Execute(const std::string& command) noexcept = 0;

        virtual Pose Query() const noexcept = 0;
    };
}
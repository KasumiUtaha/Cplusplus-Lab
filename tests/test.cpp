#include <gtest/gtest.h>
#include "ExecutorImpl.hpp"
#include <iostream>

using namespace std;
using namespace adas;

TEST(Executor, should_return_init_pose_when_without_command)
{
    auto executor = Executor::NewExecutor({0,0,'E'});
    Pose pose = {0, 0, 'E'};
    EXPECT_EQ(pose, executor -> Query());
}

TEST(Executor, should_return_default_pose_when_without_init_and_command)
{
    auto executor = Executor::NewExecutor();
    Pose pose = {0, 0, 'N'};
    EXPECT_EQ(pose, executor -> Query());
}

TEST(Executor, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
{
    Pose pose{-10, 20, 'E'};
    auto executor = Executor::NewExecutor(pose);
    executor -> Execute(string("M"));
    auto t = executor -> Query();
    EXPECT_EQ(t.x, -9);
}

TEST(Executor, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
{
    Pose pose{-10, 20, 'W'};
    auto executor = Executor::NewExecutor(pose);
    executor -> Execute(string("M"));
    auto t = executor -> Query();
    EXPECT_EQ(t.x, -11);
}

TEST(Executor, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
{
    Pose pose{-10, 20, 'N'};
    auto executor = Executor::NewExecutor(pose);
    executor -> Execute(string("M"));
    auto t = executor -> Query();
    EXPECT_EQ(t.y, 21);
}

TEST(Executor, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
{
    Pose pose{-10, 20, 'S'};
    auto executor = Executor::NewExecutor(pose);
    executor -> Execute(string("M"));
    auto t = executor -> Query();
    EXPECT_EQ(t.y, 19);
}

TEST(Executor, should_return_facing_N_given_command_is_L_and_facing_is_E)
{
    Pose pose{-10, 20, 'E'};
    auto executor = Executor::NewExecutor(pose);
    executor -> Execute(string("L"));
    auto t = executor -> Query();
    EXPECT_EQ(t.heading, 'N');
}

TEST(Executor, should_return_facing_W_given_command_is_L_and_facing_is_N)
{
    Pose pose{-10, 20, 'N'};
    auto executor = Executor::NewExecutor(pose);
    executor -> Execute(string("L"));
    auto t = executor -> Query();
    EXPECT_EQ(t.heading, 'W');
}

TEST(Executor, should_return_facing_S_given_command_is_L_and_facing_is_W)
{
    Pose pose{-10, 20, 'W'};
    auto executor = Executor::NewExecutor(pose);
    executor -> Execute(string("L"));
    auto t = executor -> Query();
    EXPECT_EQ(t.heading, 'S');
}

TEST(Executor, should_return_facing_E_given_command_is_L_and_facing_is_S)
{
    Pose pose{-10, 20, 'S'};
    auto executor = Executor::NewExecutor(pose);
    executor -> Execute(string("L"));
    auto t = executor -> Query();
    EXPECT_EQ(t.heading, 'E');
}

TEST(Executor, should_return_facing_S_given_command_is_R_and_facing_is_E)
{
    Pose pose{-10, 20, 'E'};
    auto executor = Executor::NewExecutor(pose);
    executor -> Execute(string("R"));
    auto t = executor -> Query();
    EXPECT_EQ(t.heading, 'S');
}

TEST(Executor, should_return_facing_W_given_command_is_R_and_facing_is_S)
{
    Pose pose{-10, 20, 'S'};
    auto executor = Executor::NewExecutor(pose);
    executor -> Execute(string("R"));
    auto t = executor -> Query();
    EXPECT_EQ(t.heading, 'W');
}

TEST(Executor, should_return_facing_N_given_command_is_R_and_facing_is_W)
{
    Pose pose{-10, 20, 'W'};
    auto executor = Executor::NewExecutor(pose);
    executor -> Execute(string("R"));
    auto t = executor -> Query();
    EXPECT_EQ(t.heading, 'N');
}

TEST(Executor, should_return_facing_E_given_command_is_R_and_facing_is_N)
{
    Pose pose{-10, 20, 'N'};
    auto executor = Executor::NewExecutor(pose);
    executor -> Execute(string("R"));
    auto t = executor -> Query();
    EXPECT_EQ(t.heading, 'E');
}

int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        std::cout<<"Success!";
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}
#include <gtest/gtest.h>
#include "car.h"
#include "executor.h"
#include <iostream>
#include <tuple>
using namespace std;


TEST(Executor, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
{
    Executor executor(-10, 20, 'E');
    executor.Execute('M');
    auto t = executor.Query();
    EXPECT_EQ(get<0>(t), -9);
}

TEST(Executor, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
{
    Executor executor(-10, 20, 'W');
    executor.Execute('M');
    auto t = executor.Query();
    EXPECT_EQ(get<0>(t), -11);
}

TEST(Executor, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
{
    Executor executor(-10, 20, 'N');
    executor.Execute('M');
    auto t = executor.Query();
    EXPECT_EQ(get<1>(t), 21);
}

TEST(Executor, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
{
    Executor executor(-10, 20, 'S');
    executor.Execute('M');
    auto t = executor.Query();
    EXPECT_EQ(get<1>(t), 19);
}

TEST(Executor, should_return_facing_N_given_command_is_L_and_facing_is_E)
{
    Executor executor(-10, 20, 'E');
    executor.Execute('L');
    auto t = executor.Query();
    EXPECT_EQ(get<2>(t), 'N');
}

TEST(Executor, should_return_facing_W_given_command_is_L_and_facing_is_N)
{
    Executor executor(-10, 20, 'N');
    executor.Execute('L');
    auto t = executor.Query();
    EXPECT_EQ(get<2>(t), 'W');
}

TEST(Executor, should_return_facing_S_given_command_is_L_and_facing_is_W)
{
    Executor executor(-10, 20, 'W');
    executor.Execute('L');
    auto t = executor.Query();
    EXPECT_EQ(get<2>(t), 'S');
}

TEST(Executor, should_return_facing_E_given_command_is_L_and_facing_is_S)
{
    Executor executor(-10, 20, 'S');
    executor.Execute('L');
    auto t = executor.Query();
    EXPECT_EQ(get<2>(t), 'E');
}

TEST(Executor, should_return_facing_S_given_command_is_R_and_facing_is_E)
{
    Executor executor(-10, 20, 'E');
    executor.Execute('R');
    auto t = executor.Query();
    EXPECT_EQ(get<2>(t), 'S');
}

TEST(Executor, should_return_facing_W_given_command_is_R_and_facing_is_S)
{
    Executor executor(-10, 20, 'S');
    executor.Execute('R');
    auto t = executor.Query();
    EXPECT_EQ(get<2>(t), 'W');
}

TEST(Executor, should_return_facing_N_given_command_is_R_and_facing_is_W)
{
    Executor executor(-10, 20, 'W');
    executor.Execute('R');
    auto t = executor.Query();
    EXPECT_EQ(get<2>(t), 'N');
}

TEST(Executor, should_return_facing_E_given_command_is_R_and_facing_is_N)
{
    Executor executor(-10, 20, 'N');
    executor.Execute('R');
    auto t = executor.Query();
    EXPECT_EQ(get<2>(t), 'E');
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
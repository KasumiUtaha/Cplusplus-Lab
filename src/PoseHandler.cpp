#include "PoseHandler.hpp"

namespace adas
{
    PoseHandler::PoseHandler(const Pose& pose) noexcept : 
        point(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading)) {}

    void PoseHandler::Move(int step)  noexcept
    {
        point += facing -> Move();
    }

    void PoseHandler::TurnLeft() noexcept
    {
        facing = &(facing -> LeftOne());
    }

    void PoseHandler::TurnRight() noexcept
    {
        facing = &(facing -> RightOne());
    }

    void PoseHandler::Fast() noexcept
    {
        fast ^= 1;
    }

    bool PoseHandler::isFast() const noexcept
    {
        return fast;
    }

    Pose PoseHandler::Query() const noexcept 
    {
        return {point.GetX(), point.GetY(), facing -> GetHeading()};
    }

}
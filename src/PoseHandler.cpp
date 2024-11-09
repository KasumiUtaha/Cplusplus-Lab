#include "PoseHandler.hpp"

namespace adas
{
    PoseHandler::PoseHandler(const Pose& pose) noexcept : pose(pose) {}

    void PoseHandler::Move(int step)  noexcept
    {
        switch(pose.heading) {
            case 'N': pose.y+=step; break;
            case 'S': pose.y-=step; break;
            case 'W': pose.x-=step; break;
            case 'E': pose.x+=step; break;
        }
    }

    void PoseHandler::TurnLeft() noexcept
    {
        switch (pose.heading) {
            case 'N': pose.heading = 'W'; break;
            case 'S': pose.heading = 'E'; break;
            case 'W': pose.heading = 'S'; break;
            case 'E': pose.heading = 'N'; break;
        }
    }

    void PoseHandler::TurnRight() noexcept
    {
        switch (pose.heading) {
            case 'N': pose.heading = 'E'; break;
            case 'S': pose.heading = 'W'; break;
            case 'W': pose.heading = 'N'; break;
            case 'E': pose.heading = 'S'; break;
        }
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
        return pose;
    }

}
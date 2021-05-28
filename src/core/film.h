#pragma once
#include <Eigen/Core>
namespace amber
{

    class Film
    {
    public:
        Eigen::Vector2i resolution;
        std::unique_ptr<Eigen::Vector3f> pixels;
    };
}
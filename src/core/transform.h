#pragma once

#include <Eigen/Core>
namespace amber
{
    class Transform
    {
    public:
        
    private:
        Eigen::Matrix4f matrix, matrixInv;
    };

    Transform Translate(Eigen::Vector3f vector)
    {
        Transform t;
        
    }
}

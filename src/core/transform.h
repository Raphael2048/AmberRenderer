#pragma once

#include <Eigen/Core>
using namespace Eigen;
namespace amber
{
    class Transform
    {
    public:
        Transform()
        {
            matrix_ << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
            matrixInv_ << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
        }
        Transform(const Eigen::Matrix4f& m, const Eigen::Matrix4f& inv) : matrix_(m), matrixInv_(inv) {}
        auto operator <=> (const Transform& t) const = default;

        static Transform Translate(const Eigen::Vector3f& delta)
        {
            Eigen::Matrix4f m;
            m << 1, 0, 0, delta[0], 0, 1, 0, delta[1], 0, 0, 1, delta[2], 0, 0, 0, 1;

            Eigen::Matrix4f inv;
            inv << 1, 0, 0, -delta[0], 0, 1, 0, -delta[1], 0, 0, 1, -delta[2], 0, 0, 0, 1;

            Transform t(m, inv);
            return t;
        }

        static Transform Scale(const Eigen::Vector3f& scale)
        {
            Eigen::Matrix4f m;
            m << scale[0], 0, 0, 0, 0, scale[1], 0, 0, 0, 0, scale[2], 0, 0, 0, 0, 1;

            Eigen::Matrix4f inv;
            inv << 1 / scale[0], 0, 0, 0, 0, 1 / scale[1], 0, 0, 0, 0, 1 / scale[2], 0, 0, 0, 0, 1;

            Transform t(m, inv);
            return t;
        }

        static Transform LookAt(const Vector3f& pos, const Vector3f& look, const Vector3f& up)
        {
           Matrix4f cameraToWorld;

           // Initialize fourth column of viewing matrix
           cameraToWorld(0, 3) = pos.x();
           cameraToWorld(1, 3) = pos.y();
           cameraToWorld(2, 3) = pos.z();
           cameraToWorld(3, 3) = 1;

           Vector3f dir = (look - pos).normalized();

           if(up.normalized().cross(dir).norm() == 0)
           {
               return Transform();
           }

           Vector3f right = up.normalized().cross(dir).normalized();
           Vector3f newUp = dir.cross(right);

           cameraToWorld(0, 0) = right.x();
           cameraToWorld(1, 0) = right.y();
           cameraToWorld(2, 0) = right.z();
           cameraToWorld(3, 0) = 0;
           cameraToWorld(0, 1) = newUp.x();
           cameraToWorld(1, 1) = newUp.y();
           cameraToWorld(2, 1) = newUp.z();
           cameraToWorld(3, 1) = 0;
           cameraToWorld(0, 2) = dir.x();
           cameraToWorld(1, 2) = dir.y();
           cameraToWorld(2, 2) = dir.z();
           cameraToWorld(3, 2) = 0;

           return Transform(cameraToWorld, cameraToWorld.inverse());
        }
        Eigen::Matrix4f matrix_, matrixInv_;
    };


}

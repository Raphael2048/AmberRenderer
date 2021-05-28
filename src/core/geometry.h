#pragma once
#include "core/amber.h"

namespace amber
{
    using namespace Eigen;
    class Ray
    {
    public:
        Ray() : tMax(Infinity) {}
        Ray(const Vector3f &o, const Vector3f &d, float t = Infinity) : origin(o), direction(d), tMax(t) {}
        Vector3f origin, direction;
        float tMax;
    };

    template<typename T, int N>
    class BoundsN
    {
    public:
        Bounds3() {
            T minNum = std::numeric_limits<T>::lowest();
            T maxNum = std::numeric_limits<T>::max();
        }

        explicit Bounds3(const Matrix<T, 1, N> &p) : pMin(p), pMax(p) {}

        Matrix<T, 1, N> pMin, pMax;
    };

    typedef BoundsN<float, 3> Bounds3f;
    typedef BoundsN<int, 2> Bounds2i;
}
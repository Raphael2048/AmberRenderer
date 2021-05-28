#pragma once
#include "core/amber.h"
#include "core/geometry.h"
#include "core/transform.h"
namespace amber
{
    class Shape
    {
        public:
        Shape(const Transform * ObjectToWorld, const Transform *WorldToObject, bool reverseOrientation)
        : objectToWorld(ObjectToWorld), worldToObject(worldToObject), reverseOrientation(reverseOrientation)
        {}

        virtual Bounds3f ObjectBound() const = 0;
        // virtual Bounds3f WorldBound();

        const Transform* objectToWorld, *worldToObject;
        const bool reverseOrientation;
    };
}
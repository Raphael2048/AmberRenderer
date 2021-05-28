#pragma once
#include "core/geometry.h"
#include "core/shape.h"
namespace amber
{
    class Primitive
    {
    public:
        virtual Bounds3f WorldBound() const = 0;
    };

    class GeometricPrimitive : public Primitive
    {
    public:
        Bounds3f WorldBound() const override
        {
            return shape->ObjectBound();
        }
    private:
        std::shared_ptr<Shape> shape;
        // material;
    };

    class TransformedPrimitive : public Primitive
    {
    public:
        TransformedPrimitive(std::shared_ptr<Primitive> &primitive, const Transform& PrimitiveToWorld)
        {

        }

        Bounds3f WorldBound() const override
        {
            
        }

    private:
        std::shared_ptr<Primitive> primitive;
        const Transform primitiveToWorld;
    };
}
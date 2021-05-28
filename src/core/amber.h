#pragma once

#include <limits>
#include <Eigen/Core>
namespace amber
{
// Global Constants
#ifdef _MSC_VER
#define MaxFloat std::numeric_limits<float>::max()
#define Infinity std::numeric_limits<float>::infinity()
#else
static constexpr Float MaxFloat = std::numeric_limits<float>::max();
static constexpr Float Infinity = std::numeric_limits<float>::infinity();
#endif
}

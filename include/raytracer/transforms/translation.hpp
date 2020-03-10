#pragma once
#include <raytracer/transforms/matrix.hpp>
namespace raytracer::transformations
{
template <typename T>
detail::Matrix<T, 4, 4> translation(T x, T y, T z)
{
    return Matrix<T, 4, 4>{
        {1, 0, 0, x},
        {0, 1, 0, y},
        {0, 0, 1, z},
        {0, 0, 0, 1}};
}

} // namespace raytracer::transform
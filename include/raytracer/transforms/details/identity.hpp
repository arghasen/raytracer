#pragma once
#include <raytracer/transforms/details/matrix_impl.hpp>

namespace raytracer::transformations::detail
{
template<typename T>
Matrix<T, 2, 2> Identity2d = {
    {1, 0},
    {0, 1}};

template<typename T>
Matrix<T, 3, 3> Identity3d = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}};

template<typename T>
Matrix<T,4,4 >
    Identity4d = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

} // namespace raytracer::transformations::detail
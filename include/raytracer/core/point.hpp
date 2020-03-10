#pragma once
#include <raytracer/vec3d.hpp>
#include <raytracer/core/types.hpp>
#include <raytracer/transforms/matrix.hpp>
#include <raytracer/transforms/translation.hpp>
#include <iostream>

namespace raytracer::core
{

template <typename T>
class Point : public utils::Vec3d<T>
{
    Type type = raytracer::core::Type::POINT;
    transformations::Matrix<T, 4, 1> pointToMatrix;

public:
    Point(T x, T y, T z) : utils::Vec3d<T>(x, y, z),
            pointToMatrix{
            {this->utils::Vec3d<T>::x()},
            {this->utils::Vec3d<T>::y()},
            {this->utils::Vec3d<T>::z()},
            {1} // TODO : 1 is the magic number here, refactor
            }
    {
    }

    /**
     * @brief Convert a Matrix to a Point
     * 
     * @param mat a 4*1 matrix
     */
    Point(transformations::Matrix<T, 4, 1> mat) : Point(mat(0, 0), mat(1, 0), mat(2, 0))
    {
    }

    Point<T> translate(T x, T y, T z)
    {
        auto translation_Matrix = transformations::translation(x, y, z);
        return translation_Matrix * pointToMatrix;
    }
};
} // namespace raytracer::core
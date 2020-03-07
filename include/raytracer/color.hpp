#pragma once
#include <raytracer/ray.hpp>
#include <raytracer/shape_list.hpp>

namespace raytracer
{
namespace utils
{


namespace color
{
    template <typename T>
    using Color3d = Vec3d<T>;

    template <typename T>
    constexpr auto white = Color3d<T>{1.0, 1.0, 1.0};

    template <typename T>
    constexpr auto black = Color3d<T>{0.0, 0.0, 0.0};
    
    template <typename T>
    constexpr auto blue = Color3d<T>{0.5, 0.7, 1.0};

    template <typename T>
    constexpr auto red = Color3d<T>{1.0, 0.0, 0.0};
};

template <typename T>
constexpr Vec3d<T> getColor(const Ray3d<T> &r, const color::Color3d<T> & color1, const color::Color3d<T>& color2)
{
    Vec3d<T> unit_direction_vector = unit_vector(r.direction());
    auto t = (unit_direction_vector.y() + 1.0) * 0.5; // normalize between 0 and 1 instead of -1 and 1

    return color1 * (1.0 - t) + color2 * t;
}

template <typename T>
constexpr Vec3d<T> getColor(const Ray3d<T> &ray, ShapeList3d<T> &world)
{

}
} // namespace utils
} // namespace raytracer
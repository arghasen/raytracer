#pragma once
#include <raytracer/ray.hpp>
#include <raytracer/shape_list.hpp>

namespace raytracer
{

namespace color
{
/**
 * @brief A class representing color information.
 * 
 * @tparam T 
 */
template <typename T>
class Color3d : public utils::Vec3d<T>
{
public:
    /**
     * @brief Default color constructor, black
     * 
     */
    constexpr Color3d<T>() = default;

    /**
     * @brief Create Colors from their components
     * 
     */
    constexpr Color3d<T>(T x, T y, T z) : utils::Vec3d<T>(x, y, z)
    {
    }

    /**
     * @brief Get the red Component of the color.
     * 
     * @return T red component of the color.
     */
    T red()
    {
        return utils::Vec3d<T>::x();
    }

    /**
     * @brief Get the green Component of the color.
     * 
     * @return T green component of the color.
     */
    T green()
    {
        return utils::Vec3d<T>::y();
    }

    /**
     * @brief Get the blue Component of the color.
     * 
     * @return T blue component of the color.
     */
    T blue()
    {
        return utils::Vec3d<T>::z();
    }
};

template <typename T>
constexpr auto white = Color3d<T>{1.0, 1.0, 1.0};

template <typename T>
constexpr auto black = Color3d<T>{0.0, 0.0, 0.0};

template <typename T>
constexpr auto blue = Color3d<T>{0.5, 0.7, 1.0};

template <typename T>
constexpr auto red = Color3d<T>{1.0, 0.0, 0.0};


template <typename T>
constexpr utils::Vec3d<T> getColor(const utils::Ray3d<T> &r, const color::Color3d<T> &color1, const color::Color3d<T> &color2)
{
    utils::Vec3d<T> unit_direction_vector = unit_vector(r.direction());
    auto t = (unit_direction_vector.y() + 1.0) * 0.5; // normalize between 0 and 1 instead of -1 and 1

    return color1 * (1.0 - t) + color2 * t;
}

template <typename T>
constexpr utils::Vec3d<T> getColor(const utils::Ray3d<T> &ray, utils::ShapeList3d<T> &world)
{
}
} // namespace color
} // namespace raytracer
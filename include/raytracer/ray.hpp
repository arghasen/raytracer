#pragma once

#include <raytracer/vec3d.hpp>

namespace raytracer
{
namespace utils
{

/**
     * @brief A class representing a Ray.
     * 
     * A ray is point of origin and a vector representing the direction.
     * @tparam T 
     */
template <typename T>
class Ray3d
{
public:
    /**
     * @brief Construct a new Ray 3d object
     * 
     */
    Ray3d() = default;

    /**
     * @brief Construct a new Ray 3d object
     * 
     * @param origin Point of origin
     * @param direction Direction of the ray.
     */
    Ray3d(const Vec3d<T> &origin, const Vec3d<T> &direction);

    /**
     * @brief Get the origin of the ray.
     * 
    * @return Vec3d<T> A vector representing the origin of the ray.
    */
    Vec3d<T> origin() const;

    /**
     * @brief Direction of the ray.
     * 
     * @return Vec3d<T> A vector representing the direction of the ray.
     */
    Vec3d<T> direction() const;

    /**
     * @brief The point at the parameter value
     * 
     * @param t 
     * @return Vec3d<T> A point in 3d space representing ray at the parameter value.
     */
    Vec3d<T> pointAtParameter(T t) const;

private:
    Vec3d<T> m_origin;
    Vec3d<T> m_direction;
};


template <typename T>
Vec3d<T> Ray3d<T>::origin() const
{
    return m_origin;
}

template <typename T>
Vec3d<T> Ray3d<T>::direction() const
{
    return m_direction;
}

template <typename T>
Ray3d<T>::Ray3d(const Vec3d<T> &origin, const Vec3d<T> &direction) : m_origin(origin),
                                                                     m_direction(direction)
{
}

template <typename T>
Vec3d<T> Ray3d<T>::pointAtParameter(T t) const
{
    return m_origin +  m_direction * t;
}
} // namespace utils
} // namespace raytracer

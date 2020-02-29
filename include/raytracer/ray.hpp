#pragma once

#include <raytracer/vec3d.hpp>

namespace raytracer
{
namespace utils
{
template <typename T>
class Ray3d
{
public:
    Ray3d() = default;
    Ray3d(const Vec3d<T>& origin, const Vec3d<T> &direction);

    Vec3d<T> origin() const;
    Vec3d<T> direction() const;

private:
    Vec3d<T> m_origin;
    Vec3d<T> m_direction;
};

template<typename T>
Vec3d<T> Ray3d<T>::origin() const
{
    return m_origin;
}

template<typename T>
Vec3d<T> Ray3d<T>::direction() const
{
    return m_direction;
}

template<typename T>
Ray3d<T>::Ray3d(const Vec3d<T>& origin, const Vec3d<T> &direction) : 
    m_origin(origin),
    m_direction(direction)
{}

} // namespace utils    
} // namespace raytracer

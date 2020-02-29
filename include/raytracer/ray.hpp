#pragma once

#include <raytracer/vec3d.hpp>

namespace raytracer
{
namespace utils
{
template <typename T>
class Ray
{
public:
    Ray() = default;
    Ray(const Vec3d<T>& origin, const Vec3d<T> &direction);

    Vec3d<T> origin() const;
    Vec3d<T> direction() const;

private:
    Vec3d<T> m_origin;
    Vec3d<T> m_direction;
};

template<typename T>
Vec3d<T> Ray<T>::origin() const
{
    return m_origin;
}

template<typename T>
Vec3d<T> Ray<T>::direction() const
{
    return m_direction;
}

} // namespace utils    
} // namespace raytracer

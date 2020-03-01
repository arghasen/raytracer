#pragma once

#include <raytracer/ray.hpp>

namespace raytracer::shape
{
/**
 * @brief Abstract class for all types of shapes.
 * Defines a functionality for being hit by a ray which all shapes must implement.
 */
template <typename T>
class Shape
{
public:
    /**
     * @brief 
     * 
     * @param r A ray to hit against the shape.
     * @param t_min Minimum value of the intersection point.
     * @param t_max Maximum value of the intersection point.
     * @return true The ray hits the shape.
     * @return false The ray does not hit the shape.
     */
    virtual bool hit(const utils::Ray3d<T> &r, T t_min, T t_max) const = 0;
};

/**
 * @brief A sphere class
 * 
 * A sphere is a shape that contains a point center and a radius.
 * There are other ways of defining a sphere but this simple one suffices.
 * @tparam T 
 */
template <typename T>
class Sphere : public Shape<T>
{
private:
    utils::Vec3d<T> m_center;
    T m_radius;

public:
    /**
     * @brief Construct a new Sphere object
     * 
     */
    Sphere() = default;
    
    /**
     * @brief Get the centre of the sphere.
     * 
     * @return utils::Vec3d<T> The centre of the sphere.
     */
    utils::Vec3d<T> center() const;


    bool hit(const utils::Ray3d<T> &r, T t_min, T t_max) const override;
};

template<typename T>
utils::Vec3d<T> Sphere<T>::center() const
{
    return m_center;
}


} // namespace raytracer::shape

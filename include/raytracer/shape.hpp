#pragma once

#include <raytracer/ray.hpp>

namespace raytracer::shape
{

/**
 * @brief A record of values when a ray hits a shape.
 * 
 */
template<typename T>
struct ShapeHitRecord3d
{
    T t;
    T u;
    T v;
    utils::Vec3d<T> p;
    utils::Vec3d<T> normal;
};

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
     * @param rec Output parameter with the hit record.
     * @return true The ray hits the shape.
     * @return false The ray does not hit the shape.
     */
    virtual bool hit(const utils::Ray3d<T> &r, T t_min, T t_max, ShapeHitRecord3d<T>& rec) const = 0;
    virtual ~Shape() = default;
};

/**
 * @brief A sphere class
 * 
 * A sphere is a shape that contains a point center and a radius.
 * There are other ways of defining a sphere but this simple one suffices.
 * @tparam T 
 */
template <typename T>
class Sphere3d : public Shape<T>
{
private:
    utils::Vec3d<T> m_center;
    T m_radius;

    T getDiscriminant(const utils::Ray3d<T>& ray) const;

public:
    /**
     * @brief Construct a new Sphere object
     * 
     */
    Sphere3d() = default;

    /**
     * @brief Construct a new Sphere object
     * 
     * @param center A point representing the center of sphere.
     * @param radius The value of the radius of the sphere.
     */
    Sphere3d(const utils::Vec3d<T> &center, T radius);

    ~Sphere3d() override = default;

    /**
     * @brief Get the center of the sphere.
     * 
     * @return utils::Vec3d<T> The center of the sphere.
     */
    constexpr utils::Vec3d<T> center() const;

    /**
     * @brief Get the radius of the sphere.
     * 
     * @return T The radius of the sphere.
     */
    constexpr T radius() const;

    /**
     * @brief Get the normal of the sphere.
     * 
     * @return Vec3d<T> Normal of the sphere.
     */
    constexpr utils::Vec3d<T> normal()const;

    bool hit(const utils::Ray3d<T> &ray, T t_min, T t_max, ShapeHitRecord3d<T>& rec) const override;
};

template<typename T>
Sphere3d<T>::Sphere3d(const utils::Vec3d<T> &center, T radius):
    m_center(center),m_radius(radius)
{}

template <typename T>
constexpr utils::Vec3d<T> Sphere3d<T>::center() const
{
    return m_center;
}
template <typename T>
constexpr T Sphere3d<T>::radius() const
{
    return m_radius;
}

template <typename T>
T Sphere3d<T>::getDiscriminant(const utils::Ray3d<T>& ray) const
{
    auto originToCenter = ray.origin() - m_center; 
    T a = utils::dot(ray.direction(), ray.direction());
    T b = 2.0f * dot(originToCenter, ray.direction());
    T c = dot(originToCenter, originToCenter) - m_radius*m_radius;
    return b*b -4*a*c;
}

template <typename T>
bool Sphere3d<T>::hit(const utils::Ray3d<T> &ray, T t_min, T t_max, ShapeHitRecord3d<T>& rec) const
{
    T discriminant = getDiscriminant(ray);
    if (discriminant > 0)
    {
        return true;
    }
    return false;
}
} // namespace raytracer::shape

#pragma once
#include <raytracer/shape.hpp>
#include <vector>
#include <memory>

namespace raytracer::utils
{
/**
 * @brief A list of shapes.
 * 
 * @tparam T 
 */
template <typename T>
class ShapeList3d : public shape::Shape<T>
{
public:
    /**
     * @brief Construct a new Shape List object
     * 
     */
    ShapeList3d() = default;

    /**
     * @brief Construct a new Shape List object
     * 
     * @param shapes a vector of shapes
     */
    ShapeList3d(const std::vector<std::shared_ptr<shape::Shape<T>>>& shapes);

    bool hit(const utils::Ray3d<T> &ray, T t_min, T t_max, shape::ShapeHitRecord3d<T>& rec) const override;
private:
    std::vector<std::shared_ptr<shape::Shape<T>>> m_shapes;
};

template <typename T>
ShapeList3d<T>::ShapeList3d(const std::vector<std::shared_ptr<shape::Shape<T>>>& shapes):
    m_shapes(shapes)
{}

template <typename T>
bool ShapeList3d<T>::hit(const utils::Ray3d<T> &ray, T t_min, T t_max, shape::ShapeHitRecord3d<T>& rec) const
{
    bool hit = false;
    T closestSoFar = std::numeric_limits<T>::max();
    for(auto& shape : m_shapes)
    {
        if(shape->hit(ray, t_min, t_max, rec))
        {
            hit = true;
        }
    }
    return hit;
}
} // namespace raytracer::utils
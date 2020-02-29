#include <array>
#include <cmath>

namespace raytracer
{
namespace utils
{

/*! \brief A 3d vector class.
 *         Provides basic functionality for creating and manipulating 3d vectors.
 *
 */

template <typename T>
class Vec3d
{
private:
    std::array<T, 3> m_data{0, 0, 0};

public:
    /// Default Constructor creates 0 initalized 3d vector.
    Vec3d() = default;
    
    /**
     * @brief Construct a new Vec 3d object
     * 
     * @param x  the x coordinate
     * @param y  the y coordinate
     * @param z  the z coordinate
     */
    Vec3d(T x, T y, T z);

    /**
     * @brief return the x coordinate.
     * 
     * @return T 
     */
    inline T x() const { return m_data[0]; }

    /**
     * @brief return the y coordinate.
     * 
     * @return T 
     */
    inline T y() const { return m_data[1]; }

    /**
     * @brief return the z coordinate.
     * 
     * @return T 
     */
    inline T z() const { return m_data[2]; }

    /**
     * @brief length of the vector.
     * 
     * @return double 
     */
    inline double length() const;

    /**
     * @brief add two vectors.
     * 
     * @param u  a vector
     * @return Vec3d a new vector with the result of the addition of the 2 vectors.  
     */
    Vec3d operator+(const Vec3d &u) const;

    /**
     * @brief subtract two vectors.
     * 
     * @param u a vector.
     * @return Vec3d a new vector with the result of the subtraction of the 2 vectors.
     */
    Vec3d operator-(const Vec3d &u) const;

    /**
     * @brief multiplication of two vectors
     * 
     * @param u a vector.
     * @return Vec3d a new vector with the result of the multiplication of the 2 vectors.
     */
    Vec3d operator*(const Vec3d &u) const;

    /**
     * @brief division of two vectors
     * 
     * @param u a vector.
     * @return Vec3d a new vector with the result of the division of the 2 vectors.
     */
    Vec3d operator/(const Vec3d &u) const;

    /**
     * @brief scalar multiplication of a vector.
     * 
     * @param f a scalar value.
     * @return Vec3d a new vector with the result of the scalar multiplication of the vector.
     */
    template<typename U>
    Vec3d operator*(U f) const;

    /**
     * @brief scalar division of a vector.
     * 
     * @param f a scalar value.
     * @return Vec3d a new vector with the result of the scalar division of the vector.
     */
    template<typename U>
    Vec3d operator/(U f) const;
};

template <typename T>
Vec3d<T>::Vec3d(T x, T y, T z)
{
    m_data[0] = x;
    m_data[1] = y;
    m_data[2] = z;
}

template <typename T>
double Vec3d<T>::length() const
{
    return sqrt(this->x() * this->x() + this->y() * this->y() + this->z() * this->z());
}

template <typename T>
Vec3d<T> Vec3d<T>::operator+(const Vec3d &u) const
{
    Vec3d<T> res;
    res.m_data[0] = m_data[0] + u.x();
    res.m_data[1] = m_data[1] + u.y();
    res.m_data[2] = m_data[2] + u.z();
    return res;
}

template<typename T>
Vec3d<T> Vec3d<T>::operator-(const Vec3d &u) const
{
    Vec3d<T> res;
    res.m_data[0] = m_data[0] - u.x();
    res.m_data[1] = m_data[1] - u.y();
    res.m_data[2] = m_data[2] - u.z();
    return res;
}

template<typename T>
Vec3d<T> Vec3d<T>::operator*(const Vec3d &u) const
{
    Vec3d<T> res;
    res.m_data[0] = m_data[0] * u.x();
    res.m_data[1] = m_data[1] * u.y();
    res.m_data[2] = m_data[2] * u.z();
    return res;
}

template<typename T>
Vec3d<T> Vec3d<T>::operator/(const Vec3d &u) const
{
    Vec3d<T> res;
    res.m_data[0] = m_data[0] / u.x();
    res.m_data[1] = m_data[1] / u.y();
    res.m_data[2] = m_data[2] / u.z();
    return res;
}

template<typename T>
template<typename U>
Vec3d<T> Vec3d<T>::operator*(U f) const
{
    Vec3d<T> res;
    res.m_data[0] = m_data[0] * f;
    res.m_data[1] = m_data[1] * f;
    res.m_data[2] = m_data[2] * f;
    return res;
}

template<typename T>
template<typename U>
Vec3d<T> Vec3d<T>::operator/(U f) const
{
    Vec3d<T> res;
    res.m_data[0] = m_data[0] / f;
    res.m_data[1] = m_data[1] / f;
    res.m_data[2] = m_data[2] / f;
    return res;
}

} // namespace utils
} // namespace raytracer
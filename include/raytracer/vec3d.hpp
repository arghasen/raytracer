#pragma once

#include <array>
#include <cmath>
#include <ostream>
#include <limits>

namespace raytracer
{
namespace utils
{

template <typename T>
constexpr bool approxEquals(T lhs, T rhs, T epsilon = std::numeric_limits<T>::epsilon())
{
    return (std::abs(lhs - rhs) <= epsilon) ? true : false;
}

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
    constexpr Vec3d(T x, T y, T z);

    /**
     * @brief return the x coordinate.
     * 
     * @return T 
     */
    constexpr inline T x() const { return m_data[0]; }

    /**
     * @brief return the y coordinate.
     * 
     * @return T 
     */
    constexpr inline T y() const { return m_data[1]; }

    /**
     * @brief return the z coordinate.
     * 
     * @return T 
     */
    constexpr inline T z() const { return m_data[2]; }

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
    constexpr Vec3d operator+(const Vec3d &u) const;

    /**
     * @brief subtract two vectors.
     * 
     * @param u a vector.
     * @return Vec3d a new vector with the result of the subtraction of the 2 vectors.
     */
    constexpr Vec3d operator-(const Vec3d &u) const;

    /**
     * @brief multiplication of two vectors
     * 
     * @param u a vector.
     * @return Vec3d a new vector with the result of the multiplication of the 2 vectors.
     */
    constexpr Vec3d operator*(const Vec3d &u) const;

    /**
     * @brief division of two vectors
     * 
     * @param u a vector.
     * @return Vec3d a new vector with the result of the division of the 2 vectors.
     */
    constexpr Vec3d operator/(const Vec3d &u) const;

    /**
     * @brief scalar multiplication of a vector.
     * 
     * @param f a scalar value.
     * @return Vec3d a new vector with the result of the scalar multiplication of the vector.
     */
    template <typename U>
    constexpr Vec3d operator*(U f) const;

    /**
     * @brief scalar division of a vector.
     * 
     * @param f a scalar value.
     * @return Vec3d a new vector with the result of the scalar division of the vector.
     */
    template <typename U>
    constexpr Vec3d operator/(U f) const;

    /**
     * @brief equality of two vectors
     * 
     * @param u a vector to compare against
     * @return bool
     */
    constexpr bool operator==(const Vec3d &u) const;

    /**
     * @brief inequality of two vectors
     * 
     * @param u a vector to compare against
     * @return bool
     */
    constexpr bool operator!=(const Vec3d &u) const;
};

template <typename T>
constexpr Vec3d<T>::Vec3d(T x, T y, T z)
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
constexpr Vec3d<T> Vec3d<T>::operator+(const Vec3d &u) const
{
    Vec3d<T> res;
    res.m_data[0] = m_data[0] + u.x();
    res.m_data[1] = m_data[1] + u.y();
    res.m_data[2] = m_data[2] + u.z();
    return res;
}

template <typename T>
constexpr Vec3d<T> Vec3d<T>::operator-(const Vec3d &u) const
{
    Vec3d<T> res;
    res.m_data[0] = m_data[0] - u.x();
    res.m_data[1] = m_data[1] - u.y();
    res.m_data[2] = m_data[2] - u.z();
    return res;
}

template <typename T>
constexpr Vec3d<T> Vec3d<T>::operator*(const Vec3d &u) const
{
    Vec3d<T> res;
    res.m_data[0] = m_data[0] * u.x();
    res.m_data[1] = m_data[1] * u.y();
    res.m_data[2] = m_data[2] * u.z();
    return res;
}

template <typename T>
constexpr Vec3d<T> Vec3d<T>::operator/(const Vec3d &u) const
{
    Vec3d<T> res;
    res.m_data[0] = m_data[0] / u.x();
    res.m_data[1] = m_data[1] / u.y();
    res.m_data[2] = m_data[2] / u.z();
    return res;
}

template <typename T>
template <typename U>
constexpr Vec3d<T> Vec3d<T>::operator*(U f) const
{
    Vec3d<T> res;
    res.m_data[0] = m_data[0] * f;
    res.m_data[1] = m_data[1] * f;
    res.m_data[2] = m_data[2] * f;
    return res;
}

template <typename T>
template <typename U>
constexpr Vec3d<T> Vec3d<T>::operator/(U f) const
{
    Vec3d<T> res;
    res.m_data[0] = m_data[0] / f;
    res.m_data[1] = m_data[1] / f;
    res.m_data[2] = m_data[2] / f;
    return res;
}

template <typename T>
constexpr bool Vec3d<T>::operator==(const Vec3d<T> &u) const
{
    return approxEquals(this->x(), u.x())
           && approxEquals(this->y(), u.y())
           && approxEquals(this->z(), u.z());
}

template <typename T>
constexpr bool Vec3d<T>::operator!=(const Vec3d<T> &u) const
{
    return !(*this == u);
}

/**
 * @brief Unit vector of a vector.
 * 
 * @tparam T 
 * @param v 
 * @return Vec3d<T> 
 */
template <typename T>
Vec3d<T> unit_vector(const Vec3d<T> &v)
{
    return v / v.length();
}

/**
 * @brief Dot product of 2 vectors
 * 
 * @tparam T 
 * @param v First Vector.
 * @param u Second Vector.
 * @return T the dot product value.
 */
template <typename T>
T dot(const Vec3d<T> &v, const Vec3d<T> &u)
{
    return v.x() * u.x() + v.y() * u.y() + v.z() * u.z();
}

/**
 * @brief Cross product of two vectors.
 * 
 * @tparam T 
 * @param u First Vector.
 * @param v Second Vector.
 * @return Vec3d<T> A new vector which is the cross product of the two vectors.
 */
template <typename T>
Vec3d<T> cross(const Vec3d<T> &u, const Vec3d<T> &v)
{
    return Vec3d<T>{
        (u.y() * v.z() - u.z() * v.y()),
        (-(u.x() * v.z() - u.z() * v.x())),
        (u.x() * v.y() - u.y() * v.x())};
}
template <typename T>
inline std::ostream &operator<<(std::ostream &os, const Vec3d<T> &t)
{
    os << "(" << t.x() << ", " << t.y() << ", " << t.z() << ")";
    return os;
}
} // namespace utils
} // namespace raytracer
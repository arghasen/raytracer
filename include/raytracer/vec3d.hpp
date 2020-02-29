#include<array>
#include<cmath>

namespace raytracer
{
namespace utils
{
    template <typename T>
    class Vec3d
    {
    private:
        std::array<T,3>  m_data{0,0,0};
    
    public:
        Vec3d() = default;
        Vec3d(T x, T y, T z);
        inline T x() const { return m_data[0]; }
        inline T y() const { return m_data[1]; }
        inline T z() const { return m_data[2]; }
        inline double length() const;
        Vec3d operator+(const Vec3d& u);
        Vec3d operator-(const Vec3d& u);
        Vec3d operator*(const Vec3d& u);
        Vec3d operator/(const Vec3d& u);
        Vec3d operator.(const Vec3d& u);
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
        return sqrt(this->x()*this->x() + this->y()*this->y()
               + this->z()*this->z());
    }

    template <typename T>
    Vec3d<T> Vec3d<T>::operator+(const Vec3d& u)
    {
        Vec3d<T> res;
        res.m_data[0] = m_data[0]+u.x();
        res.m_data[1] = m_data[1]+u.y();
        res.m_data[2] = m_data[2]+u.z();
        return res;
    }
} // namespace utils
} // namespace raytracer
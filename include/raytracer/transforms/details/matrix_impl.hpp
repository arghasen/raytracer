#include <array>

namespace raytracer::transformations::detail
{
template <typename T>
class Matrix4d
{
private:
    std::array<std::array<T, 4>, 4> m_data;

public:
    Matrix4d() = default;

    Matrix4d(std::initializer_list<std::initializer_list<T>> values)
    {
        int i =0; 
        for (const auto internalValue : values)
        {
            int j =0;
            for (const auto val : internalValue)
            {
                m_data[i][j] = val;
                j++;
            }
            i++;
        }
    }
    T operator()(int i, int j)
    {
        return m_data[i][j];
    }
};

} // namespace raytracer::transformations::detail
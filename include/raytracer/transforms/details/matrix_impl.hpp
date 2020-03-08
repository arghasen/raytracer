#include <array>

namespace raytracer::transformations::detail
{
template <typename T, size_t M = 4, size_t N = 4>
class Matrix
{
private:
    std::array<std::array<T, 4>, 4> m_data;
    size_t m_M;
    size_t m_N;

public:
    Matrix():
        m_M(M),m_N(N)
    {
        m_data = {{
            {{0, 0, 0, 0}},
            {{0, 0, 0, 0}},
            {{0, 0, 0, 0}},
            {{0, 0, 0, 0}},
        }};
    }

    Matrix(std::initializer_list<std::initializer_list<T>> values):
        m_M(M), m_N(N)
    {
        int i = 0;
        for (const auto internalValue : values)
        {
            int j = 0;
            for (const auto val : internalValue)
            {
                m_data[i][j] = val;
                j++;
            }
            i++;
        }
    }

    T operator()(int i, int j) const
    {
        if (i >= m_M || j >= m_N)
        {
            throw std::out_of_range("Matrix subscript are out of range");
        }
        return m_data[i][j];
    }

    bool operator==(const Matrix<T, M, N> &m) const
    {
        for (int i = 0; i < m_M; i++)
        {
            for (int j = 0; j < m_N; j++)
            {
                if(m_data[i][j] != m(i, j))
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Matrix<T, M, N> &m) const
    {
        return !(*this == m);
    }
};

} // namespace raytracer::transformations::detail
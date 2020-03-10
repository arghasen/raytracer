#pragma once
#include <array>

namespace raytracer::transformations::detail
{
template <typename T, size_t M = 4, size_t N = 4>
class Matrix
{
private:
    std::array<std::array<T, N>, M> m_data;

public:
    Matrix()
    {
        for(int i = 0; i <M; i++)
        {
            for(int j = 0; j <N; j++)
            {
                m_data[i][j] = 0;
            }
        }
    }

    Matrix(const std::initializer_list<std::initializer_list<T>> values)
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

    constexpr size_t getRows()const
    {
        return  M;
    }
    
    constexpr size_t getCols()const
    {
        return  N;
    }

    void set(size_t i, size_t j, T val )
    {
        m_data[i][j] = val;
    }

    T operator()(int i, int j) const
    {
        if (i >= M || j >= N)
        {
            throw std::out_of_range("Matrix subscript are out of range");
        }
        return m_data[i][j];
    }

    bool operator==(const Matrix<T, M, N> &m) const
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
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

    template <size_t K>
    Matrix<T, M, K>operator*(const Matrix<T, N, K> &m ) const
    {
       Matrix<T, M, K> ret;
       for (size_t i = 0; i < M; i++)
       {
           for (size_t k = 0; k < K; k++)
           {
               for(size_t j = 0; j <N; j++)
               {
                   auto val = ret(i,k)+ this->operator()(i,j)* m(j,k);
                   ret.set(i, k, val);
               }
           }
       }
       return std::move(ret);
    }

    Matrix<T,N,M> transpose()const
    {
        Matrix<T,N,M> ret;
        for (size_t i = 0; i <N;i++)
        {
            for (size_t j =0; j < M; j++)
            {
                ret.set(i,j, this->operator()(j,i));
            }
        }
        return std::move(ret);
    }

};

} // namespace raytracer::transformations::detail
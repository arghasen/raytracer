#pragma once
#include <raytracer/transforms/details/matrix_impl.hpp>
#include <raytracer/transforms/details/identity.hpp>

namespace raytracer::transformations
{
template<typename T, std::size_t M, std::size_t N>
using Matrix =detail::Matrix<T,M,N>;
} // namespace raytracer::transformations

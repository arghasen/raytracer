#pragma once
#include <raytracer/transforms/details/matrix_impl.hpp>
#include <raytracer/transforms/details/identity.hpp>

namespace raytracer::transformations
{
template<typename T, size_t M, size_t N>
using Matrix =detail::Matrix<T,M,N>;
} // namespace raytracer::transformations
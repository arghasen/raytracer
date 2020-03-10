#include <raytracer/transforms/translation.hpp>
#include <raytracer/core/point.hpp>
#include <catch2/catch.hpp>

TEST_CASE("Multiplication by a translation matrix","[transform]")
{
    raytracer::core::Point p{-3,4,5};
    REQUIRE(p.translate(5,-3,2) == raytracer::core::Point{2,1,7});
}
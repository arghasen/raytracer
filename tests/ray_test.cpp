#include "raytracer/ray.hpp"

#include <catch2/catch.hpp>

using namespace raytracer::utils;
TEST_CASE("create empty ray","[Ray]")
{
    Ray<float> tr;
    REQUIRE(tr.origin() == Vec3d<float>{0,0,0});
    REQUIRE(tr.direction() == Vec3d<float>{0,0,0});
}
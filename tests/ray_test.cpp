#include "raytracer/ray.hpp"

#include <catch2/catch.hpp>

using namespace raytracer::utils;
TEST_CASE("create empty ray", "[Ray]")
{
    Ray3d<float> tr;
    REQUIRE(tr.origin() == Vec3d<float>{0,0,0});
    REQUIRE(tr.direction() == Vec3d<float>{0,0,0});
}

TEST_CASE("create ray with origin and direction", "[Ray]")
{
    auto origin = Vec3d<float>{1,1,1};
    auto direction = Vec3d<float>{2,2,2};
    Ray3d<float> tr{origin, direction};
    
    REQUIRE(tr.origin() == origin);
    REQUIRE(tr.direction() == direction);
}
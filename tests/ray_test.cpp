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

TEST_CASE("parametric point","[ray]")
{
    auto origin = Vec3d<float>{1,1,1};
    auto direction = Vec3d<float>{2,2,2};
    Ray3d<float> tr{origin, direction};

    auto c = tr.pointAtParameter(0);
    REQUIRE(c == Vec3d<float>{1,1,1});

    auto d = tr.pointAtParameter(1);
    REQUIRE(d == Vec3d<float>{3,3,3});
    
    auto e = tr.pointAtParameter(2);
    REQUIRE(e == Vec3d<float>{5,5,5});
}
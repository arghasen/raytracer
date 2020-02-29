#include "raytracer/vec3d.hpp"

#include <catch2/catch.hpp>

TEST_CASE("3d vectors can be created","[vec3d]")
{
    raytracer::utils::Vec3d<int> v;
    REQUIRE(v.x() == 0);
    REQUIRE(v.y() == 0);
    REQUIRE(v.z() == 0);
}

TEST_CASE("Non Zero 3d vectors can be created","[vec3d]")
{
    raytracer::utils::Vec3d<int> v(1,2,3);
    REQUIRE(v.x() == 1);
    REQUIRE(v.y() == 2);
    REQUIRE(v.z() == 3);
}

TEST_CASE("Vectors of 0 have 0 length","[vec3d]")
{
    raytracer::utils::Vec3d<int> v;
    REQUIRE(v.length() == 0);
}

TEST_CASE("Non Zero Vectors have non zero length","[vec3d]")
{
    raytracer::utils::Vec3d<int> v(1,1,1);
    REQUIRE(v.length() == sqrt(3));
}

TEST_CASE("Add two vectors","[vec3d]")
{

    raytracer::utils::Vec3d<int> v(1,1,1);
    raytracer::utils::Vec3d<int> u(1,1,1);
    auto c = u + v;
    REQUIRE(c.x() == 2);
    REQUIRE(c.y() == 2);
    REQUIRE(c.z() == 2);
}
#include "raytracer/vec3d.hpp"

#include <catch2/catch.hpp>

TEST_CASE("3d vectors can be created", "[vec3d]")
{
    raytracer::utils::Vec3d<int> v;
    REQUIRE(v.x() == 0);
    REQUIRE(v.y() == 0);
    REQUIRE(v.z() == 0);
}

TEST_CASE("Non Zero 3d vectors can be created", "[vec3d]")
{
    raytracer::utils::Vec3d<int> v(1, 2, 3);
    REQUIRE(v.x() == 1);
    REQUIRE(v.y() == 2);
    REQUIRE(v.z() == 3);
}

TEST_CASE("Vectors of 0 have 0 length", "[vec3d]")
{
    raytracer::utils::Vec3d<int> v;
    REQUIRE(v.length() == 0);
}

TEST_CASE("Non Zero Vectors have non zero length", "[vec3d]")
{
    raytracer::utils::Vec3d<int> v(1, 1, 1);
    REQUIRE(v.length() == sqrt(3));
}

TEST_CASE("Add two vectors", "[vec3d]")
{
    raytracer::utils::Vec3d<int> v(1, 1, 1);
    raytracer::utils::Vec3d<int> u(1, 1, 1);
    auto c = u + v;
    REQUIRE(c.x() == 2);
    REQUIRE(c.y() == 2);
    REQUIRE(c.z() == 2);
}

TEST_CASE("subtract two vectors", "[vec3d]")
{
    raytracer::utils::Vec3d<int> v(4, 4, 4);
    raytracer::utils::Vec3d<int> u(1, 1, 1);
    SECTION("a-b")
    {
        auto c = v - u;
        REQUIRE(c.x() == 3);
        REQUIRE(c.y() == 3);
        REQUIRE(c.z() == 3);
    }
    SECTION("b-a")
    {
        auto c = u - v;

        REQUIRE(c.x() == -3);
        REQUIRE(c.y() == -3);
        REQUIRE(c.z() == -3);
    }
}

TEST_CASE("Multiply two vectors", "[vec3d]")
{
    raytracer::utils::Vec3d<int> v(2, 2, 2);
    raytracer::utils::Vec3d<int> u(3, 3, 3);
    auto c = u * v;
    REQUIRE(c.x() == 6);
    REQUIRE(c.y() == 6);
    REQUIRE(c.z() == 6);
}

TEST_CASE("Divide two vectors", "[vec3d]")
{
    raytracer::utils::Vec3d<float> v(2, 2, 2);
    raytracer::utils::Vec3d<float> u(3, 3, 3);
    auto c = u / v;
    REQUIRE(c.x() == 1.5);
    REQUIRE(c.y() == 1.5);
    REQUIRE(c.z() == 1.5);
}
TEST_CASE("Multiply vector with scalar", "[vec3d]")
{
    raytracer::utils::Vec3d<int> v(2, 2, 2);

    auto c = v*2;
    REQUIRE(c.x() == 4);
    REQUIRE(c.y() == 4);
    REQUIRE(c.z() == 4);
}

TEST_CASE("Divide vector with scalar", "[vec3d]")
{
    raytracer::utils::Vec3d<int> v(2, 2, 2);

    auto c =  v/2;
    REQUIRE(c.x() == 1);
    REQUIRE(c.y() == 1);
    REQUIRE(c.z() == 1);
}

TEST_CASE("Equality of vectors", "[vec3d]")
{
    raytracer::utils::Vec3d<int> v(2, 2, 2);
    raytracer::utils::Vec3d<int> u(3, 3, 3);
    raytracer::utils::Vec3d<int> r(2, 2, 2);

    REQUIRE(v == r);
    REQUIRE(u != r);
}
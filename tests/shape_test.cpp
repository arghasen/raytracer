#include "raytracer/shape.hpp"
#include <catch2/catch.hpp>

using namespace raytracer::utils;
using namespace raytracer::shape;

TEST_CASE("create spheres", "[shape]")
{
    Sphere<float> sphere;
    REQUIRE(sphere.center() == Vec3d<float>(0.0f, 0.0f, 0.0f));
    REQUIRE(sphere.radius() == Approx(0.0f));
}

TEST_CASE("create spheres with center and radius", "[shape]")
{
    Vec3d<float> center{0.0f, 0.0f, 0.0f};
    auto radius = 5.0f;
    Sphere<float> sphere{center, radius};

    REQUIRE(sphere.center() == center);
    REQUIRE(sphere.radius() == radius);
}
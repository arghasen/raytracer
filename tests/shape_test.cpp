#include "raytracer/shape.hpp"
#include <catch2/catch.hpp>

using namespace raytracer::utils;
using namespace raytracer::shape;

TEST_CASE("create spheres", "[sphere]")
{
    Sphere<float> sphere;
    REQUIRE(sphere.center() == Vec3d<float>(0.0f, 0.0f, 0.0f));
    REQUIRE(sphere.radius() == Approx(0.0f));
}

TEST_CASE("create spheres with center and radius", "[sphere]")
{
    Vec3d<float> center{0.0f, 0.0f, 0.0f};
    auto radius = 5.0f;
    Sphere<float> sphere{center, radius};

    REQUIRE(sphere.center() == center);
    REQUIRE(sphere.radius() == radius);
}


TEST_CASE("hit sphere with a ray", "[sphere]")
{
    Vec3d<float> center{0.0f, 0.0f, 0.0f};
    auto radius = 5.0f;
    Sphere<float> sphere{center, radius};
}
#include "raytracer/shape.hpp"
#include <catch2/catch.hpp>

using namespace raytracer::utils;
using namespace raytracer::shape;

TEST_CASE("create spheres","[shape]")
{
    Sphere<float> sphere;
    REQUIRE(sphere.center() == Vec3d<float>(0.0f, 0.0f, 0.0f));
}
#include "raytracer/shape.hpp"
#include <catch2/catch.hpp>

using namespace raytracer::utils;
using namespace raytracer::shape;

TEST_CASE("create spheres", "[sphere]")
{
    Sphere3d<float> sphere;
    REQUIRE(sphere.center() == Vec3d<float>(0.0f, 0.0f, 0.0f));
    REQUIRE(sphere.radius() == Approx(0.0f));
}

TEST_CASE("create spheres with center and radius", "[sphere]")
{
    Vec3d<float> center{0.0f, 0.0f, 0.0f};
    auto radius = 5.0f;
    Sphere3d<float> sphere{center, radius};

    REQUIRE(sphere.center() == center);
    REQUIRE(sphere.radius() == radius);
}

TEST_CASE("hit sphere with a ray", "[sphere]")
{
    Vec3d<float> center{0.0f, 0.0f, 0.0f};
    auto radius = 5.0f;
    Sphere3d<float> sphere{center, radius};
    
    SECTION("Ray hit successfully")
    {
        Ray3d<float> ray{Vec3d<float>{5, 5, 5}, Vec3d<float>{-1, -1, -1}};
        REQUIRE(sphere.hit(ray, 0, 0) == true);
    }

    SECTION("Ray hit unsuccessfully")
    {
        Ray3d<float> ray1{Vec3d<float>{5, 5, 5}, Vec3d<float>{1, 0, 0}};
        REQUIRE(sphere.hit(ray1, 0, 0) == false);
    }
}
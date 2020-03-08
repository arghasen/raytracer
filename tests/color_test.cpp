#include <raytracer/color.hpp>
#include <catch2/catch.hpp>

TEST_CASE("Default color","[color]")
{
    raytracer::color::Color3d<float> c;
    REQUIRE(c.x()== Approx(0.0f));
    REQUIRE(c.y()== Approx(0.0f));
    REQUIRE(c.z()== Approx(0.0f));
}

TEST_CASE("Other color","[color]")
{
    raytracer::color::Color3d<float> c{-0.5,0.4,1.7};
    REQUIRE(c.x()== Approx(-0.5f));
    REQUIRE(c.y()== Approx(0.4f));
    REQUIRE(c.z()== Approx(1.7f));
}
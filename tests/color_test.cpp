#include <raytracer/color.hpp>
#include <catch2/catch.hpp>

TEST_CASE("Default color", "[color]")
{
    raytracer::color::Color3d<float> c;
    REQUIRE(c.x() == Approx(0.0f));
    REQUIRE(c.y() == Approx(0.0f));
    REQUIRE(c.z() == Approx(0.0f));
}

TEST_CASE("Other color", "[color]")
{
    raytracer::color::Color3d<float> c{-0.5, 0.4, 1.7};
    REQUIRE(c.x() == Approx(-0.5f));
    REQUIRE(c.y() == Approx(0.4f));
    REQUIRE(c.z() == Approx(1.7f));
}

TEST_CASE("Add color", "[color]")
{
    raytracer::color::Color3d<float> c1{0.9, 0.6, 0.75};
    raytracer::color::Color3d<float> c2{0.7, 0.1, 0.25};
    raytracer::color::Color3d<float> c3{1.6, 0.7, 1.0};
    auto c = c1 + c2;
    REQUIRE(c == c3);
}
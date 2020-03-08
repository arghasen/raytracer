#include <raytracer/color.hpp>
#include <catch2/catch.hpp>

TEST_CASE("Default color", "[color]")
{
    raytracer::color::Color3d<float> c;
    REQUIRE(c.red() == Approx(0.0f));
    REQUIRE(c.green() == Approx(0.0f));
    REQUIRE(c.blue() == Approx(0.0f));
}

TEST_CASE("Other color", "[color]")
{
    raytracer::color::Color3d<float> c{-0.5, 0.4, 1.7};
    REQUIRE(c.red() == Approx(-0.5f));
    REQUIRE(c.green() == Approx(0.4f));
    REQUIRE(c.blue() == Approx(1.7f));
}

TEST_CASE("Add color", "[color]")
{
    raytracer::color::Color3d<float> c1{0.9, 0.6, 0.75};
    raytracer::color::Color3d<float> c2{0.7, 0.1, 0.25};
    raytracer::color::Color3d<float> c3{1.6, 0.7, 1.0};

    auto c = c1 + c2;
    REQUIRE(c == c3);
}

TEST_CASE("Subtract color", "[color]")
{
    raytracer::color::Color3d<float> c1{0.9, 0.6, 0.75};
    raytracer::color::Color3d<float> c2{0.7, 0.1, 0.25};
    raytracer::color::Color3d<float> c3{0.2, 0.5, 0.5};

    auto c = c1 - c2;
    REQUIRE(c == c3);
}

TEST_CASE("Multiply by scalar", "[color]")
{
    raytracer::color::Color3d<float> c1{0.2, 0.3, 0.4};
    raytracer::color::Color3d<float> c2{0.4, 0.6, 0.8};

    auto c = c1 * 2;
    REQUIRE(c == c2);
}

TEST_CASE("Hamadard product", "[color]")
{
    raytracer::color::Color3d<float> c1{1, 0.2, 0.4};
    raytracer::color::Color3d<float> c2{0.9, 1, 0.1};
    raytracer::color::Color3d<float> c3{0.9, 0.2, 0.04};
    
    auto c = hamadard(c1,c2);
    REQUIRE(c == c3);
}
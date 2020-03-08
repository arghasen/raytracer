#include <raytracer/core/canvas.hpp>
#include <raytracer/color.hpp>
#include <catch2/catch.hpp>


TEST_CASE("canvas create","[canvas]")
{
    raytracer::core::Canvas<raytracer::color::Color3d<float>> c(10,20); 
    REQUIRE(c.height() == 10);
    REQUIRE(c.width() == 20);
    for (int i = 0; i <c.height(); i++)
    {
        for (int j = 0; j <c.width(); j++)
        {
            REQUIRE(c.getPixelColor(i,j)==raytracer::color::black<float>);
        }
    }
}

TEST_CASE("canvas write color","[canvas]")
{
    raytracer::core::Canvas<raytracer::color::Color3d<float>> c(10,20); 
    c.setPixelColor(2,3,raytracer::color::red<float>);
    REQUIRE(c.getPixelColor(2,3) == raytracer::color::red<float>);
}
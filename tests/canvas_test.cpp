#include <raytracer/core/canvas.hpp>
#include <raytracer/color.hpp>
#include <gtest/gtest.h>


TEST(canvas,canvasCreate)
{
    raytracer::core::Canvas<raytracer::color::Color3d<float>> c(5,6); 
    EXPECT_EQ(c.height(), 5);
    EXPECT_EQ(c.width(), 6);
    for (int i = 0; i <c.height(); i++)
    {
        for (int j = 0; j <c.width(); j++)
        {
            EXPECT_EQ(c.getPixelColor(i,j),raytracer::color::black<float>);
        }
    }
}

TEST(canvas, canvasWriteColor)
{
    raytracer::core::Canvas<raytracer::color::Color3d<float>> c(10,20); 
    c.setPixelColor(2,3,raytracer::color::red<float>);
    EXPECT_EQ(c.getPixelColor(2,3) ,raytracer::color::red<float>);
}

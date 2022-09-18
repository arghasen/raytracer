#include <raytracer/color.hpp>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace raytracer::test
{
    using testing::Eq;
    using testing::FloatEq;

    TEST(color, Defaultcolor)
    {
        raytracer::color::Color3d<float> c;
        EXPECT_THAT(c.red(), FloatEq(0.0f));
        EXPECT_THAT(c.green(), FloatEq(0.0f));
        EXPECT_THAT(c.blue(), FloatEq(0.0f));
    }

    TEST(color, Othercolor)
    {
        raytracer::color::Color3d<float> c{-0.5, 0.4, 1.7};
        EXPECT_THAT(c.red(), FloatEq(-0.5f));
        EXPECT_THAT(c.green(), FloatEq(0.4f));
        EXPECT_THAT(c.blue(), FloatEq(1.7f));
    }

    TEST(color, Addcolor)
    {
        raytracer::color::Color3d<float> c1{0.9, 0.6, 0.75};
        raytracer::color::Color3d<float> c2{0.7, 0.1, 0.25};
        raytracer::color::Color3d<float> c3{1.6, 0.7, 1.0};

        auto c = c1 + c2;
        EXPECT_THAT(c, Eq(c3));
    }

    TEST(color, Subtractcolor)
    {
        raytracer::color::Color3d<float> c1{0.9, 0.6, 0.75};
        raytracer::color::Color3d<float> c2{0.7, 0.1, 0.25};
        raytracer::color::Color3d<float> c3{0.2, 0.5, 0.5};

        auto c = c1 - c2;
        EXPECT_THAT(c, Eq(c3));
    }

    TEST(color, MultiplybyScalar)
    {
        raytracer::color::Color3d<float> c1{0.2, 0.3, 0.4};
        raytracer::color::Color3d<float> c2{0.4, 0.6, 0.8};

        auto c = c1 * 2;
        EXPECT_THAT(c, Eq(c2));
    }
    TEST(color, HamadardProduct)
    {
        raytracer::color::Color3d<float> c1{1, 0.2, 0.4};
        raytracer::color::Color3d<float> c2{0.9, 1, 0.1};
        raytracer::color::Color3d<float> c3{0.9, 0.2, 0.04};

        auto c = hamadard(c1, c2);
        EXPECT_THAT(c, Eq(c3));
    }
} // namespace raytracer::test

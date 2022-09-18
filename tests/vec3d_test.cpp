#include "raytracer/vec3d.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace raytracer::test
{
    using testing::DoubleEq;
    TEST(Vec3dTest, Create3dVectors)
    {
        raytracer::utils::Vec3d<int> v;
        EXPECT_EQ(v.x(), 0);
        EXPECT_EQ(v.y(), 0);
        EXPECT_EQ(v.z(), 0);
    }

    TEST(Vec3dTest, Vec3dTest_CreateNonZero3dvectors)
    {
        raytracer::utils::Vec3d<int> v(1, 2, 3);
        EXPECT_EQ(v.x(), 1);
        EXPECT_EQ(v.y(), 2);
        EXPECT_EQ(v.z(), 3);
    }

    TEST(Vec3dTest, ZeroLengthVector)
    {
        raytracer::utils::Vec3d<int> v;
        EXPECT_EQ(v.length(), 0);
    }

    TEST(Vec3dTest, NonZeroLengthVector)
    {
        raytracer::utils::Vec3d<int> v(1, 1, 1);
        EXPECT_EQ(v.length(), sqrt(3));
    }

    TEST(Vec3dTest, Addition)
    {
        raytracer::utils::Vec3d<int> v(1, 1, 1);
        raytracer::utils::Vec3d<int> u(1, 1, 1);
        auto c = u + v;
        EXPECT_EQ(c.x(), 2);
        EXPECT_EQ(c.y(), 2);
        EXPECT_EQ(c.z(), 2);
    }

    TEST(Vec3dTest, subtract)
    {
        raytracer::utils::Vec3d<int> v(4, 4, 4);
        raytracer::utils::Vec3d<int> u(1, 1, 1);
        // SECTION("a-b")
        {
            auto c = v - u;
            EXPECT_EQ(c.x(), 3);
            EXPECT_EQ(c.y(), 3);
            EXPECT_EQ(c.z(), 3);
        }
        // SECTION("b-a")
        {
            auto c = u - v;

            EXPECT_EQ(c.x(), -3);
            EXPECT_EQ(c.y(), -3);
            EXPECT_EQ(c.z(), -3);
        }
    }

    TEST(Vec3dTest, Multiply)
    {
        raytracer::utils::Vec3d<int> v(2, 2, 2);
        raytracer::utils::Vec3d<int> u(3, 3, 3);
        auto c = u * v;
        EXPECT_EQ(c.x(), 6);
        EXPECT_EQ(c.y(), 6);
        EXPECT_EQ(c.z(), 6);
    }

    TEST(Vec3dTest, Divide)
    {
        raytracer::utils::Vec3d<float> v(2, 2, 2);
        raytracer::utils::Vec3d<float> u(3, 3, 3);
        auto c = u / v;
        EXPECT_EQ(c.x(), 1.5);
        EXPECT_EQ(c.y(), 1.5);
        EXPECT_EQ(c.z(), 1.5);
    }
    TEST(Vec3dTest, MultiplyVectorWithScalar)
    {
        raytracer::utils::Vec3d<int> v(2, 2, 2);

        auto c = v * 2;
        EXPECT_EQ(c.x(), 4);
        EXPECT_EQ(c.y(), 4);
        EXPECT_EQ(c.z(), 4);
    }

    TEST(Vec3dTest, DivideVectorWithScalar)
    {
        raytracer::utils::Vec3d<int> v(2, 2, 2);

        auto c = v / 2;
        EXPECT_EQ(c.x(), 1);
        EXPECT_EQ(c.y(), 1);
        EXPECT_EQ(c.z(), 1);
    }

    TEST(Vec3dTest, Equality)
    {
        raytracer::utils::Vec3d<int> v(2, 2, 2);
        raytracer::utils::Vec3d<int> u(3, 3, 3);
        raytracer::utils::Vec3d<int> r(2, 2, 2);

        EXPECT_EQ(v, r);
        EXPECT_NE(u , r);
    }

    TEST(Vec3dTest, UnitVectors)
    {
        raytracer::utils::Vec3d<float> v(1, 1, 1);
        auto c = unit_vector(v);
        EXPECT_THAT(c.length(), testing::DoubleEq(1.0));
    }

    TEST(Vec3dTest, DotProduct)
    {
        raytracer::utils::Vec3d<float> v(2, 3, 4);
        raytracer::utils::Vec3d<float> u(5, 6, 7);
        raytracer::utils::Vec3d<float> r(1, 1, 1);
        raytracer::utils::Vec3d<float> s(1, 2, 3);

        EXPECT_EQ(dot(v, u), 56);
        EXPECT_EQ(dot(v, r), 9);
        EXPECT_EQ(dot(v, s), 20);
        EXPECT_EQ(dot(u, r), 18);
    }

    TEST(Vec3dTest, CrossProduct)
    {
        raytracer::utils::Vec3d<float> v(2, 3, 4);
        raytracer::utils::Vec3d<float> u(5, 6, 7);
        raytracer::utils::Vec3d<float> r(1, 1, 1);

        EXPECT_EQ(raytracer::utils::cross(v, u), raytracer::utils::Vec3d<float>(-3, 6, -3));
        EXPECT_EQ(raytracer::utils::cross(v, r), raytracer::utils::Vec3d<float>(-1, 2, -1));
        EXPECT_EQ(raytracer::utils::cross(r, r), raytracer::utils::Vec3d<float>(0, 0, 0));
    }
} // namespace raytracer::test
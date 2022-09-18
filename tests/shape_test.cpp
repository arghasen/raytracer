#include "raytracer/shape.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace raytracer::test
{

    using namespace raytracer::utils;
    using namespace raytracer::shape;

    using testing::Eq;
    using testing::FloatEq;

    TEST(sphereTest, createSpheres)
    {
        Sphere3d<float> sphere;
        EXPECT_THAT(sphere.center(), Eq(Vec3d<float>(0.0f, 0.0f, 0.0f)));
        EXPECT_THAT(sphere.radius(), FloatEq(0.0f));
    }

    TEST(sphereTest, createSpheresWithCenterAndRadius)
    {
        Vec3d<float> center{0.0f, 0.0f, 0.0f};
        auto radius = 5.0f;
        Sphere3d<float> sphere{center, radius};

        EXPECT_EQ(sphere.center(), center);
        EXPECT_EQ(sphere.radius(), radius);
    }

    struct SphereRayTest : public testing::Test
    {
        SphereRayTest() : center(0.0f, 0.0f, 0.0f), radius(5.0f), sphere(center, radius) {}

        Vec3d<float> center;
        float radius;
        Sphere3d<float> sphere;
        ShapeHitRecord3d<float> hitRecord;
    };

    TEST_F(SphereRayTest, hitSphereWithRaySuccess)
    {
        Ray3d<float> ray{Vec3d<float>{5, 5, 5}, Vec3d<float>{-1, -1, -1}};
        EXPECT_TRUE(sphere.hit(ray, 0, 0, hitRecord));
    }

    TEST_F(SphereRayTest, hitSphereWithRayFail)
    {
        Ray3d<float> ray1{Vec3d<float>{5, 5, 5}, Vec3d<float>{1, 0, 0}};
        EXPECT_FALSE(sphere.hit(ray1, 0, 0, hitRecord));
    }
} // namespace raytracer::test
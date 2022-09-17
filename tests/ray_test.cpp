#include "raytracer/ray.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace raytracer::utils;

TEST(rayTest, createEmptyRay)
{
    Ray3d<float> tr;
    EXPECT_EQ(tr.origin() ,  Vec3d<float>(0,0,0));
    EXPECT_EQ(tr.direction(), Vec3d<float>(0, 0, 0));
}

TEST(rayTest, createRayWithOriginAndDirection)
{
    auto origin = Vec3d<float>{1, 1, 1};
    auto direction = Vec3d<float>{2, 2, 2};
    Ray3d<float> tr{origin, direction};

    EXPECT_EQ(tr.origin(), origin);
    EXPECT_EQ(tr.direction(), direction);
}

TEST(rayTest, parametricPoint)
{
    auto origin = Vec3d<float>{1, 1, 1};
    auto direction = Vec3d<float>{2, 2, 2};
    Ray3d<float> tr{origin, direction};

    auto c = tr.pointAtParameter(0);
    EXPECT_EQ(c, Vec3d<float>(1, 1, 1));

    auto d = tr.pointAtParameter(1);
    EXPECT_EQ(d, Vec3d<float>(3, 3, 3));

    auto e = tr.pointAtParameter(2);
    EXPECT_EQ(e, Vec3d<float>(5, 5, 5));
}
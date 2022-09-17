#include <raytracer/shape.hpp>
#include <raytracer/shape_list.hpp>
#include <raytracer/vec3d.hpp>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace raytracer::shape;
using namespace raytracer::utils;

struct ShapeListTest : public ::testing::Test
{
    ShapeListTest()
    {
        shapes.push_back(std::make_shared<Sphere3d<float>>(Vec3d<float>(0.0f, 0.0f, 0.0f), 4));
        shapes.push_back(std::make_shared<Sphere3d<float>>(Vec3d<float>(10.0f, 10.0f, 10.0f), 4));
    }

    std::vector<std::shared_ptr<Shape<float>>> shapes;

    ShapeHitRecord3d<float> hitRecord;
};

TEST_F(ShapeListTest, RayHitSuccessfully)
{
    ShapeList3d<float> shapesList(shapes);
    Ray3d<float> ray(Vec3d<float>(5.0f, 5.0f, 5.0f), Vec3d<float>(1.0f, 1.0f, 1.0f));
    EXPECT_TRUE(shapesList.hit(ray, 0, 0, hitRecord));
}
TEST_F(ShapeListTest, RayHitUnsuccessfully)
{

    ShapeList3d<float> shapesList(shapes);
    Ray3d<float> ray2(Vec3d<float>(5.0f, 5.0f, 5.0f), Vec3d<float>(1.0f, 0.0f, 0.0f));
    EXPECT_FALSE(shapesList.hit(ray2, 0, 0, hitRecord));
}
#include <raytracer/vec3d.hpp>
#include <raytracer/shape.hpp>
#include <raytracer/shape_list.hpp>

#include <catch2/catch.hpp>

using namespace raytracer::shape;
using namespace raytracer::utils;

TEST_CASE("ray hits a list of shapes","[shapelist]")
{
    std::vector<std::shared_ptr<Shape<float>>> shapes;
    shapes.push_back(std::make_shared<Sphere3d<float>>(Vec3d<float>(0.0f, 0.0f, 0.0f),4));
    shapes.push_back(std::make_shared<Sphere3d<float>>(Vec3d<float>(10.0f, 10.0f, 10.0f),4));

    ShapeList3d<float> shapesList(shapes);
    Ray3d<float> ray(Vec3d<float>(5.0f, 5.0f, 5.0f),Vec3d<float>(1.0f, 1.0f, 1.0f));

    REQUIRE(shapesList.hit(ray, 0, 0) == true);
    
    Ray3d<float> ray2(Vec3d<float>(5.0f, 5.0f, 5.0f),Vec3d<float>(1.0f, 0.0f, 0.0f));
    
    REQUIRE(shapesList.hit(ray2, 0, 0) == false);
}
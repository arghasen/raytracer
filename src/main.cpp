#include "raytracer/vec3d.hpp"
#include "raytracer/ray.hpp"
#include "raytracer/color.hpp"
#include "raytracer/shape.hpp"
#include "raytracer/shape_list.hpp"

#include <iostream>

using namespace raytracer::utils;
using namespace raytracer::shape;
using namespace raytracer::color;
using Vec = Vec3d<float>;
using Ray = Ray3d<float>;
using Sphere = Sphere3d<float>;
constexpr auto White = white<float>;
constexpr auto Black = black<float>;
constexpr auto Blue = blue<float>;
constexpr auto Red = red<float>;


int main(int, char **)
{
    int nx = 200; // number of x pixels
    int ny = 200; // number of y pixels

    Vec origin{0.0, 0.0, 0.0}; // position of camera

    // the scene is 100 pixels away from us.
    Vec horizonal{200.0, 0.0, 0.0};
    Vec vertical{0.0, 200.0, 0.0}; // y is vertical
    Vec lower_left_corner{-100.0, -100.0, -100.0};

    // PPM format for image
    std::cout << "P3" << std::endl;
    std::cout << nx << " " << ny << std::endl;
    std::cout << "255" << std::endl;

    std::vector<std::shared_ptr<Shape<float>>> shapes;
    shapes.push_back(std::make_shared<Sphere3d<float>>(Vec3d<float>(0.0f, 0.0f, -100.0f), 10));
    shapes.push_back(std::make_shared<Sphere3d<float>>(Vec3d<float>(50.0f, 50.0f, -100.0f), 10));
    shapes.push_back(std::make_shared<Sphere3d<float>>(Vec3d<float>(-50.0f, -50.0f, -100.0f), 10));
    

    ShapeList3d<float> shapesList(shapes);
    raytracer::shape::ShapeHitRecord3d<float> rec;
    for (int j = ny - 1; j >= 0; j--)
    {
        for (int i = 0; i < nx; i++)
        {
            float u = float(i) / float(nx);
            float v = float(j) / float(ny);
            Ray r{origin, lower_left_corner + horizonal * u + vertical * v};
            Vec col = getColor(r, Blue, Red);
            if(shapesList.hit(r, 0, 0, rec))
                col = Vec(0,0,0);
            std::cout << int(255 *col.x()) <<" "<< int(255 *col.y()) << " "
                      << int(255 *col.z()) << std::endl;
        }
    }
}

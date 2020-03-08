#include <raytracer/transforms/details/matrix_impl.hpp>
#include <catch2/catch.hpp>

using namespace raytracer::transformations::detail;
TEST_CASE("4d matrices can be created", "[4dmatrix]")
{
    Matrix4d<float> m;
    REQUIRE(m(0, 0) == Approx(0.0f));
    REQUIRE(m(0, 3) == Approx(0.0f));
    REQUIRE(m(1, 0) == Approx(0.0f));
    REQUIRE(m(1, 2) == Approx(0.0f));
    REQUIRE(m(2, 2) == Approx(0.0f));
    REQUIRE(m(3, 0) == Approx(0.0f));
    REQUIRE(m(3, 2) == Approx(0.0f));
}



TEST_CASE("4d matrices can be created", "[4dmatrix]")
{
    Matrix4d<float> m = {
                            {1, 2, 3, 4},
                            {5.5, 6.5, 7.5, 8.5},
                            {9, 10, 11, 12},
                            {13.5, 14.5, 15.5, 16.5}
                        };
    REQUIRE(m(0, 0) == Approx(1.0f));
    REQUIRE(m(0, 3) == Approx(4.0f));
    REQUIRE(m(1, 0) == Approx(5.5f));
    REQUIRE(m(1, 2) == Approx(7.5f));
    REQUIRE(m(2, 2) == Approx(11.0f));
    REQUIRE(m(3, 0) == Approx(13.5f));
    REQUIRE(m(3, 2) == Approx(15.5f));
}
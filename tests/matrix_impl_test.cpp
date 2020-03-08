#include <raytracer/transforms/details/matrix_impl.hpp>
#include <catch2/catch.hpp>

using namespace raytracer::transformations::detail;
TEST_CASE("4d matrices can be created by default", "[4dmatrix]")
{
    Matrix<float> m;
    REQUIRE(m(0, 0) == Approx(0.0f));
    REQUIRE(m(0, 3) == Approx(0.0f));
    REQUIRE(m(1, 0) == Approx(0.0f));
    REQUIRE(m(1, 2) == Approx(0.0f));
    REQUIRE(m(2, 2) == Approx(0.0f));
    REQUIRE(m(3, 0) == Approx(0.0f));
    REQUIRE(m(3, 2) == Approx(0.0f));
}

TEST_CASE("4d matrices can be created", "matrix]")
{
    Matrix<float> m = {
        {1, 2, 3, 4},
        {5.5, 6.5, 7.5, 8.5},
        {9, 10, 11, 12},
        {13.5, 14.5, 15.5, 16.5}};

    REQUIRE(m(0, 0) == Approx(1.0f));
    REQUIRE(m(0, 3) == Approx(4.0f));
    REQUIRE(m(1, 0) == Approx(5.5f));
    REQUIRE(m(1, 2) == Approx(7.5f));
    REQUIRE(m(2, 2) == Approx(11.0f));
    REQUIRE(m(3, 0) == Approx(13.5f));
    REQUIRE(m(3, 2) == Approx(15.5f));
}

TEST_CASE("2d matrices are representable", "[matrix]")
{
    Matrix<float, 2, 2> m = {
        {-3, 5},
        {1, -2}};

    REQUIRE(m(0, 0) == Approx(-3));
    REQUIRE(m(0, 1) == Approx(5));
    REQUIRE(m(1, 0) == Approx(1));
    REQUIRE(m(1, 1) == Approx(-2));
}

TEST_CASE("3d matrices are representable", "[matrix]")
{
    Matrix<float, 3, 3> m = {
        {-3, 5, 0},
        {1, -2, -7},
        {0, 1, 1}};

    REQUIRE(m(0, 0) == Approx(-3));
    REQUIRE(m(1, 1) == Approx(-2));
    REQUIRE(m(2, 2) == Approx(1));
}

TEST_CASE("Matrix equality", "[matrix]")
{
    Matrix<float> m = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    Matrix<float> n = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    
    REQUIRE(m == n);
}

TEST_CASE("Matrix inequality", "[matrix]")
{
    Matrix<float> m = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    Matrix<float> n = {
        {11, 12, 13, 14},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    
    REQUIRE(m != n);
}

#include <raytracer/transforms/details/matrix_impl.hpp>
#include <raytracer/transforms/details/identity.hpp>
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

TEST_CASE("4d matrices can be created", "[matrix]")
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

TEST_CASE("Matrix multiplication", "[matrix]")
{
    Matrix<float> m = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6},
        {5, 4, 3, 2}};

    Matrix<float> n = {
        {-2, 1, 2, 3},
        {3, 2, 1, -1},
        {4, 3, 6, 5},
        {1, 2, 7, 8}};
    auto c = m * n;
    CHECK(c(0, 0) == Approx(20));
    CHECK(c(0, 1) == Approx(22));
    CHECK(c(0, 2) == Approx(50));
    CHECK(c(0, 3) == Approx(48));
    CHECK(c(1, 0) == Approx(44));
    CHECK(c(1, 1) == Approx(54));
    CHECK(c(1, 2) == Approx(114));
    CHECK(c(1, 3) == Approx(108));
    CHECK(c(2, 0) == Approx(40));
    CHECK(c(2, 1) == Approx(58));
    CHECK(c(2, 2) == Approx(110));
    CHECK(c(2, 3) == Approx(102));
    CHECK(c(3, 0) == Approx(16));
    CHECK(c(3, 1) == Approx(26));
    CHECK(c(3, 2) == Approx(46));
    CHECK(c(3, 3) == Approx(42));
}

TEST_CASE("Multiply by Idenity Matrix","[matrix]")
{
    Matrix<float> A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6},
        {5, 4, 3, 2}};
    
    REQUIRE(A*Identity4d<float> == A);
}

TEST_CASE("Identity Matrix multiplication","[matrix]")
{
    REQUIRE(Identity4d<float>* Identity4d<float> == Identity4d<float>);
}
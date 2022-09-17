#include <raytracer/transforms/details/identity.hpp>
#include <raytracer/transforms/details/matrix_impl.hpp>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace raytracer::transformations::detail;
using testing::FloatEq;

TEST(matrixTest, A4d_matrix_can_be_created_by_default)
{
    Matrix<float> m;
    EXPECT_THAT(m(0, 0), FloatEq(0.0f));
    EXPECT_THAT(m(0, 3), FloatEq(0.0f));
    EXPECT_THAT(m(1, 0), FloatEq(0.0f));
    EXPECT_THAT(m(1, 2), FloatEq(0.0f));
    EXPECT_THAT(m(2, 2), FloatEq(0.0f));
    EXPECT_THAT(m(3, 0), FloatEq(0.0f));
    EXPECT_THAT(m(3, 2), FloatEq(0.0f));
}

TEST(matrixTest, A4d_matrix_can_be_created)
{
    Matrix<float> m = {
        {1, 2, 3, 4},
        {5.5, 6.5, 7.5, 8.5},
        {9, 10, 11, 12},
        {13.5, 14.5, 15.5, 16.5}};

    EXPECT_THAT(m(0, 0), FloatEq(1.0f));
    EXPECT_THAT(m(0, 3), FloatEq(4.0f));
    EXPECT_THAT(m(1, 0), FloatEq(5.5f));
    EXPECT_THAT(m(1, 2), FloatEq(7.5f));
    EXPECT_THAT(m(2, 2), FloatEq(11.0f));
    EXPECT_THAT(m(3, 0), FloatEq(13.5f));
    EXPECT_THAT(m(3, 2), FloatEq(15.5f));
}

TEST(matrixTest, A2d_matrix_is_representable)
{
    Matrix<float, 2, 2> m = {
        {-3, 5},
        {1, -2}};

    EXPECT_THAT(m(0, 0), FloatEq(-3));
    EXPECT_THAT(m(0, 1), FloatEq(5));
    EXPECT_THAT(m(1, 0), FloatEq(1));
    EXPECT_THAT(m(1, 1), FloatEq(-2));
}

TEST(matrixTest, A3d_matrix_is_representable)
{
    Matrix<float, 3, 3> m = {
        {-3, 5, 0},
        {1, -2, -7},
        {0, 1, 1}};

    EXPECT_THAT(m(0, 0), FloatEq(-3));
    EXPECT_THAT(m(1, 1), FloatEq(-2));
    EXPECT_THAT(m(2, 2), FloatEq(1));
}

TEST(matrixTest, MatrixEquality)
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

    EXPECT_EQ(m, n);
}

TEST(matrixTest, MatrixInequality)
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

    EXPECT_NE(m, n);
}

TEST(matrixTest, MatrixMultiplication)
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
    EXPECT_THAT(c(0, 0), FloatEq(20));
    EXPECT_THAT(c(0, 1), FloatEq(22));
    EXPECT_THAT(c(0, 2), FloatEq(50));
    EXPECT_THAT(c(0, 3), FloatEq(48));
    EXPECT_THAT(c(1, 0), FloatEq(44));
    EXPECT_THAT(c(1, 1), FloatEq(54));
    EXPECT_THAT(c(1, 2), FloatEq(114));
    EXPECT_THAT(c(1, 3), FloatEq(108));
    EXPECT_THAT(c(2, 0), FloatEq(40));
    EXPECT_THAT(c(2, 1), FloatEq(58));
    EXPECT_THAT(c(2, 2), FloatEq(110));
    EXPECT_THAT(c(2, 3), FloatEq(102));
    EXPECT_THAT(c(3, 0), FloatEq(16));
    EXPECT_THAT(c(3, 1), FloatEq(26));
    EXPECT_THAT(c(3, 2), FloatEq(46));
    EXPECT_THAT(c(3, 3), FloatEq(42));
}

TEST(matrixTest, MatrixMultiplication2)
{
    Matrix<float> m = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6},
        {5, 4, 3, 2}};

    Matrix<float> n = {
        {-2},
        {3},
        {4},
        {1}};
    auto c = m * n;
    EXPECT_THAT(c(0, 0), FloatEq(20));
    EXPECT_THAT(c(1, 0), FloatEq(44));
    EXPECT_THAT(c(2, 0), FloatEq(40));
    EXPECT_THAT(c(3, 0), FloatEq(16));
}

TEST(matrixTest, MultiplybyIdenityMatrix)
{
    Matrix<float> A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6},
        {5, 4, 3, 2}};

    EXPECT_THAT(A * Identity4d<float>, A);
}

TEST(matrixTest, IdentityMatrixMultiplication)
{
    EXPECT_THAT(Identity4d<float> * Identity4d<float>, Identity4d<float>);
}

TEST(matrixTest, MatrixTranspose)
{
    Matrix<float> A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6},
        {5, 4, 3, 2}};

    Matrix<float> B = {
        {1, 5, 9, 5},
        {2, 6, 8, 4},
        {3, 7, 7, 3},
        {4, 8, 6, 2}};

    EXPECT_THAT(A.transpose(), B);
}

TEST(matrixTest, IdentityTranspose)
{
    EXPECT_THAT(Identity4d<float>.transpose(), Identity4d<float>);
}

#include <raytracer/core/point.hpp>
#include <raytracer/transforms/translation.hpp>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace raytracer::test
{
    using testing::Eq;
    TEST(transformsTest, MultiplicationByATranslationMatrix)
    {
        raytracer::core::Point p{-3, 4, 5};
        EXPECT_THAT(p.translate(5, -3, 2), Eq(raytracer::core::Point{2, 1, 7}));
    }

} // namespace raytracer::test
#pragma once

#include <raytracer/color.hpp>
#include <vector>

namespace raytracer::core
{
template <typename Color>
class Canvas
{
private:
    size_t m_height;
    size_t m_width;
    std::vector<std::vector<Color>> m_colors;

public:
    Canvas(size_t m, size_t n) : m_height(m),
                                 m_width(n),
                                 m_colors(m_height, std::vector<Color>(n))
    {
    }

    ~Canvas() = default;

    size_t width() const
    {
        return m_width;
    }

    size_t height() const
    {
        return m_height;
    }

    const Color& getPixelColor(size_t x, size_t y) const
    {
        return m_colors[x][y];
    }

    void setPixelColor(size_t x, size_t y, const Color& color)
    {
        m_colors[x][y] = color;
    }
};
} // namespace raytracer::core
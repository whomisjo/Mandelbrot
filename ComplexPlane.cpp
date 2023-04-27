#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ComplexPlane.h"
#include <sstream>
#include <vector>
#include <complex>

using namespace std;


ComplexPlane::ComplexPlane(float aspectRatio)
{
    m_aspectRatio = aspectRatio;
    m_zoomCount = 0;
    m_view.setSize(BASE_WIDTH, -BASE_HEIGHT * m_aspectRatio);
    m_view.setCenter(0.0f, 0.0f);
}

void ComplexPlane::zoomIn()
{
    m_zoomCount++;

    float xSize = BASE_WIDTH * pow(BASE_ZOOM, m_zoomCount);
    float ySize = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);

    m_view.setSize(xSize, ySize);
}

void ComplexPlane::zoomOut() 
{
    m_zoomCount--;

    float xSize = BASE_WIDTH * pow(BASE_ZOOM, m_zoomCount);
    float ySize = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);

    m_view.setSize(xSize, ySize);
}

void ComplexPlane::setCenter(Vector2f coord) 
{
    m_view.setCenter(coord);
}

void ComplexPlane::setMouseLocation(Vector2f coord)
{
    m_mouseLocation = coord;
}

void ComplexPlane::loadText(Text& text)
{
    stringstream ss;
    ss << "Mandelbrot Set" << endl;
    ss << "Center: (" << m_view.getCenter().x << ", " << m_view.getCenter().y << ")" << endl;
    ss << "Cursor: (" << m_mouseLocation.x << ", " << m_mouseLocation.y << ")" << endl;
    ss << "Left-click to Zoom in" << endl;
    ss << "Right-click to Zoom out" << endl;

    text.setString(ss.str());
}

size_t ComplexPlane::countIterations(Vector2f coord)
{
    complex<float> c(coord.x, coord.y);
    complex<float> z(0, 0);
    size_t i = 0;
    while (i < MAX_ITER && abs(z) < 2)
    {
        z = z * z + c;
        i++;
    }
    return i;

}

void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b)
{
    size_t iterations = count;
    if (iterations == MAX_ITER)
    {
        r = 0;
        g = 69;
        b = 0;
    }
    else
    {
        r = 0;
        g = (255 * iterations) / MAX_ITER;
        b = 0;
    }
}

View ComplexPlane::getView()
{
    return m_view;
}

#include <raylib.h>
#include <raymath.h>
#include <iostream>

#include "definitions.hpp"
#include "elements.hpp"

using namespace std;
Checkbox::Checkbox(int startX, int startY, int rectangleWidth, int rectanagleHeight) : x(startX),
                                                                                       y(startY),
                                                                                       width(rectangleWidth),
                                                                                       height(rectanagleHeight)
{

    cout << "Checkbox: (" << x << "," << y << ")\t" << "(" << x + width << "," << y + height << ")" << "\n";
}

void Checkbox::draw()
{
    DrawRectangle(x, y, width, height, RED);
}
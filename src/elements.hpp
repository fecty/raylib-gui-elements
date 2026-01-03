#pragma once

class Checkbox
{

private:
public:
    int x, y;
    int width;
    int height;

    Checkbox(int startX, int startY, int rectangleWidth, int rectanagleHeight);
    void draw();
};
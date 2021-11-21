#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
const double PI = 3.1456;
using namespace std;

class Point
{
public:
    double x, y;
};
class Shape
{
protected:
    vector<Point> points;
    double area;
    int id;

public:
    string type;

public:
    double getAreaofMultiangleShape();
    double getArea();
    int getID();
    vector<Point> getPoints();
    void addShape(int soDinh);
    void showInfo();
    void subtractArea();
};
class Triangle : public Shape
{
public:
    static int nTri;
    static double aTri;
    Triangle()
    {
        id = nTri;
        type = "Triangle";
        nTri++;
    }
    void addShape();
};
class Parallelogram : public Shape
{
public:
    static int nParallel;
    static double aParallel;
    Parallelogram()
    {
        id = nParallel;
        type = "Parallelogram";
        nParallel++;
    }

    void addShape();

}; //bình hành
class Rectangle : public Shape
{
public:
    static int nRect;
    static double aRect;
    Rectangle()
    {
        id = nRect;
        type = "Rectangle";
        nRect++;
    }

    void addShape();
};
class Rhombus : public Shape
{
public:
    static int nRhombus;
    static double aRhombus;
    Rhombus()
    {
        id = nRhombus;
        type = "Rhombus";
        nRhombus++;
    }

    void addShape();

}; // thoi
class Square : public Shape
{
public:
    static int nSquare;
    static double aSquare;
    Square()
    {
        id = nSquare;
        type = "Square";
        nSquare++;
    }

    void addShape();
};
class Ellipse : public Shape
{
public:
    static int nEllipse;
    static double aEllipse;
    Ellipse()
    {
        id = nEllipse;
        type = "Ellipse";
        nEllipse++;
    }

    void addShape();
};
class Circle : public Shape
{
    double r;

public:
    static int nCircle;
    static double aCircle;
    Circle()
    {
        id = nCircle;
        type = "Circle";
        nCircle++;
    }
    void showInfo();
    void addShape();
};
class ShapeManager
{
    vector<Shape *> shapes;

public:
    void addNewShape();
    void removeShape();
    void sortByArea();
    void inputthenremove();
    void listAllExisted();
    void listShapeConditional();
    void listTypebyArea();
};
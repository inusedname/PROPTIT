#include "class.h"

int Triangle::nTri = 0;
int Rectangle::nRect = 0;
int Parallelogram::nParallel = 0;
int Square::nSquare = 0;
int Circle::nCircle = 0;
int Ellipse::nEllipse = 0;
int Rhombus::nRhombus = 0;
double Triangle::aTri = 0;
double Rectangle::aRect = 0;
double Parallelogram::aParallel = 0;
double Square::aSquare = 0;
double Circle::aCircle = 0;
double Ellipse::aEllipse = 0;
double Rhombus::aRhombus = 0;

double lengthBetweenTwoPoints(double x1, double y1, double x2, double y2)
{
    double x = (x2 - x1) * (x2 - x1);
    double y = (y2 - y1) * (y2 - y1);
    return sqrt(y + x);
}
void Shape::showInfo()
{
    cout << "Type: " << type << "\n";
    cout << "Shape ID: " << id << "\n";
    cout << "Points: ";
    for (int i = 0; i < points.size(); i++)
        cout << "[" << points[i].x << "," << points[i].y << "] ";
    cout << "\n";
    cout << "Area: " << area << "\n";
}
vector<Point> Shape::getPoints()
{
    return points;
}
void Shape::subtractArea()
{
    if (type == "Triangle")
        Triangle::aTri -= area;
    else if (type == "Parallelogram")
        Parallelogram::aParallel -= area;
    else if (type == "Rectangle")
        Rectangle::aRect -= area;
    else if (type == "Rhombus")
        Rhombus::aRhombus -= area;
    else if (type == "Square")
        Square::aSquare -= area;
    else if (type == "Ellipse")
        Ellipse::aEllipse -= area;
    else if (type == "Circle")
        Circle::aCircle -= area;
}
int Shape::getID()
{
    return id;
}
double Shape::getArea()
{
    return area;
}
double Shape::getAreaofMultiangleShape()
{
    double area1 = 0;
    double area2 = 0;
    for (int i = 0; i < points.size() - 1; i++)
        area1 += points[i].x * points[i + 1].y;
    area1 += points[points.size() - 1].x * points[0].y;
    for (int i = 0; i < points.size() - 1; i++)
        area2 += points[i].y * points[i + 1].x;
    area2 += points[points.size() - 1].y * points[0].x;
    return (area1 - area2) / 2.0;
}
void Shape::addShape(int soDinh)
{
    Point tmp;
    cout << "Nhap vao " << soDinh << " dinh:\n";
    for (int i = 0; i < soDinh; i++)
    {
        cout << "Toa do dinh " << i + 1 << " : ", cin >> tmp.x >> tmp.y;
        points.push_back(tmp);
    }
}
void Triangle::addShape()
{
    cout << "Hinh tam giac\n";
    Shape::addShape(3);
    area = getAreaofMultiangleShape();
    aTri += area;
    cout << "Add Triangle Successfully\n";
}
void Parallelogram::addShape()
{
    cout << "Hinh binh hanh\n";
    Shape::addShape(4);
    area = getAreaofMultiangleShape();
    aParallel += area;
    cout << "Add Parallelogram Successfully\n";
}
void Rectangle::addShape()
{
    cout << "Hinh chu nhat\n";
    Shape::addShape(4);
    area = getAreaofMultiangleShape();
    aRect += area;
    cout << "Add Rectangle Successfully\n";
}
void Rhombus::addShape()
{
    cout << "Hinh thoi\n";
    Shape::addShape(4);
    area = getAreaofMultiangleShape();
    aRhombus += area;
    cout << "Add Rhombus Successfully\n";
}
void Square::addShape()
{
    cout << "Hinh vuong\n";
    Shape::addShape(4);
    area = getAreaofMultiangleShape();
    aSquare += area;
    cout << "Add Square Successfully\n";
}
void Ellipse::addShape()
{
    cout << "Hinh elipse\n";
    cout << "Nhap theo thu tu: trai -> tren -> phai -> duoi:\n";
    Shape::addShape(4);
    double b = lengthBetweenTwoPoints(points[0].x, points[0].y, points[2].x, points[2].y) / 2;
    double a = lengthBetweenTwoPoints(points[1].x, points[1].y, points[3].x, points[3].y) / 2;
    area = PI * a * b;
    aEllipse += area;
    cout << "Add Ellipse Successfully\n";
}
void Circle::addShape()
{
    cout << "Hinh tron\n";
    cout << "Nhap tam duong tron:\n";
    Shape::addShape(1);
    cout << "Nhap ban kinh R: ", cin >> r;
    area = PI * r * r;
    aCircle += area;
    cout << "Add Circle Successfully\n";
}
void Circle::showInfo()
{
    Shape::showInfo();
    cout << "Radius: " << r << "\n";
}
void ShapeManager::addNewShape()
{
    cout << "Which type of shape\n";
    cout << "[1] Triangle\n"
         << "[2] Parallelogram\n"
         << "[3] Rectangle\n"
         << "[4] Rhombus\n"
         << "[5] Square\n"
         << "[6] Ellipse\n"
         << "[7] Circle\n"
         << "[0] Exit\n";
    int choice;
    cout << "Your choice: ", cin >> choice;
    if (!choice)
    {
        cout << "Close task.\n";
        return;
    }
    switch (choice)
    {
    case 1:
    {
        Triangle *newshape = new Triangle;
        newshape->addShape();
        shapes.push_back(newshape);
        break;
    }
    case 2:
    {
        Parallelogram *newshape = new Parallelogram;
        newshape->addShape();
        shapes.push_back(newshape);
        break;
    }
    case 3:
    {
        Rectangle *newshape = new Rectangle;
        newshape->addShape();
        shapes.push_back(newshape);
        break;
    }
    case 4:
    {
        Rhombus *newshape = new Rhombus;
        newshape->addShape();
        shapes.push_back(newshape);
        break;
    }
    case 5:
    {
        Square *newshape = new Square;
        newshape->addShape();
        shapes.push_back(newshape);
        break;
    }
    case 6:
    {
        Ellipse *newshape = new Ellipse;
        newshape->addShape();
        shapes.push_back(newshape);
        break;
    }
    case 7:
    {
        Circle *newshape = new Circle;
        newshape->addShape();
        shapes.push_back(newshape);
        break;
    }
    }
}
void ShapeManager::removeShape()
{
    cout << "typeid test:" << typeid(Triangle).name() << "\n";
    string choice;
    int id;
    cout << "Input shape type (string): \n";
    cout << "Triangle\n"
         << "Parallelogram\n"
         << "Rectangle\n"
         << "Rhombus\n"
         << "Square\n"
         << "Ellipse\n"
         << "Circle\n";
    cout << "Your choice: ", cin >> choice;
    cout << choice << " id: ", cin >> id;
    bool success = 0;
    for (int i = 0; i < shapes.size(); i++)
    {
        if (shapes[i]->type == choice && shapes[i]->getID() == id)
        {
            cout << "Found\n";
            shapes[i]->subtractArea();
            shapes.erase(shapes.begin() + i);
            cout << "Erase completed\n";
            success = 1;
            break;
        }
    }
    if (!success)
    {
        cout << "Not found\n";
    }
}
void ShapeManager::sortByArea()
{
    cout << shapes[1]->getID() << endl;
    vector<Shape *> tmp = shapes;
    sort(tmp.begin(), tmp.end(), [](Shape *x, Shape *y)
         { return x->getArea() < y->getArea(); });
    cout << "Shape | id | Area |\n";
    for (int i = 0; i < tmp.size(); i++)
        cout << tmp[i]->type << " | " << tmp[i]->getID() << " | " << tmp[i]->getArea() << "\n";
}
void ShapeManager::inputthenremove()
{
    cout << "Tinh nang moi chi cho phep nguoi dung nhap vao hinh chu nhat co 2 canh lien tiep song song voi Ox, Oy\n";
    cout << "Nhap toa do hinh chu nhat\n";
    Point form[4];
    cout << "1. Top-left: ", cin >> form[0].x >> form[0].y;
    cout << "2. Top-right: ", cin >> form[1].x >> form[1].y;
    cout << "3. Bottom-right: ", cin >> form[2].x >> form[2].y;
    cout << "4. Bottom-left: ", cin >> form[3].x >> form[3].y;
    for (int i = 0; i < shapes.size(); i++)
    {
        Point toCheck = shapes[i]->getPoints()[0];
        if (toCheck.x < form[0].x || toCheck.x > form[1].y || toCheck.y < form[1].y || toCheck.x > form[2].y)
        {
            cout << "Found shape! Deleting...\n";
            shapes[i]->subtractArea();
            shapes.erase(shapes.begin() + i);
            i--;
        }
    }
    cout << "Erase shapes violated completes.\n";
}
void ShapeManager::listAllExisted()
{
    cout << "There are " << shapes.size() << " shapes existed.\n";
    for (int i = 0; i < shapes.size(); i++)
        shapes[i]->showInfo();
    cout << "Task completes\n";
}
void ShapeManager::listShapeConditional()
{
    double s;
    cout << "Filter 1. Area:  ", cin >> s;
    string shapefilters;
    cout << "Filter 2. Type every types of shape in a single line in lower case: \n";
    cin >> shapefilters;
    for (int i = 0; i < shapes.size(); i++)
    {
        if (shapes[i]->getArea() > s && shapefilters.find(shapes[i]->type) != string::npos)
        {
            cout << "Found!\n";
            shapes[i]->showInfo();
        }
    }
    cout << "Task completes.\n";
}
void ShapeManager::listTypebyArea()
{
    vector<pair<double, string>> allArea;
    allArea.push_back({Triangle::aTri, "Triangle"});
    allArea.push_back({Rectangle::aRect, "Rectangle"});
    allArea.push_back({Square::aSquare, "Square"});
    allArea.push_back({Circle::aCircle, "Circle"});
    allArea.push_back({Ellipse::aEllipse, "Ellipse"});
    allArea.push_back({Rhombus::aRhombus, "Rhombus"});
    allArea.push_back({Parallelogram::aParallel, "Parallelogram"});
    sort(allArea.begin(), allArea.end(), [](pair<double, string> x, pair<double, string> y)
         { return x.first < y.first; });
    for (int i = 0; i < 7; i++)
        cout << allArea[i].second << " : " << allArea[i].first << "\n";
}
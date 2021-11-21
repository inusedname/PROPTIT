#include "class.h"

int main()
{
    int choice;
    ShapeManager myShape;
    while (1)
    {
        cout << "=================MENU================\n";
        cout << "1. Add Shape\n";
        cout << "2. Remove shape\n";
        cout << "3. Sort by area\n";
        cout << "4. Input a rectangle and then remove all shapes which the first point inside it.\n";
        cout << "5. List all existed shaped\n";
        cout << "6. List all shapes which larger than S and are type of X,Y,Z...\n";
        cout << "7. List each type of shape, ascendingly by area\n";
        // cout << "8. Reshape A by B, with the same area and the first point\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        if (!choice)
        {
            cout << "Chuong trinh ket thuc.";
            break;
        }
        cout << "=====================================\n";
        switch (choice)
        {
        case 1:
            myShape.addNewShape();
            break;
        case 2:
            myShape.removeShape();
            break;
        case 3:
            myShape.sortByArea();
            break;
        case 4:
            myShape.inputthenremove();
            break;
        case 5:
            myShape.listAllExisted();
            break;
        case 6:
            myShape.listShapeConditional();
            break;
        case 7:
            myShape.listTypebyArea();
            break;
        }
    }
}
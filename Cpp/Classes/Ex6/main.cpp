#include <iostream>

using std::cout;

/*
Create a class named 'Shape' with a function to print "This is a shape".
Then create two other classes named 'Rectangle' and 'Circle' inheriting the Shape class,
both having a function to print "This is rectangular shape" and "This is circular shape"
respectively. Create a subclass 'Square' of 'Rectangle' having a function to print "Square is a rectangle".
Now call the function of the 'Shape' and the 'Rectangle' class by the object of the 'Square' class.
*/

class Shape {

public:
    void printShape() {
        cout << "This is a shape" << "\n";
    }
};

class Rectangle : public Shape {
public:
    void printRectangle() {
        cout << "This is rectangular shape" << "\n";
    }
};

class Circle : public Shape {
public:
    void printCircle() {
        cout << "This is circular shape" << "\n";
    }
};

class Square : public Rectangle {
public:
    void printSquare() {
        cout << "Square is a rectangle" << "\n";
    }
};

int main() {

    Square *s = new Square();

    s->printRectangle();
    s->printShape();

    return 0;
}

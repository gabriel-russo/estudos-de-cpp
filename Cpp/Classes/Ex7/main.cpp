#include <iostream>

using std::cout;

/*
Create a class named 'Rectangle' with two data members 'length' and 'breadth' and
two functions to print the area and perimeter of the rectangle respectively. Its constructor having
parameters for length and breadth is used to initialize the length and breadth of the rectangle.
Let class 'Square' inherit the 'Rectangle' class with its constructor having a parameter for
its side (suppose s) calling the constructor of its parent class.
Print the area and perimeter of a rectangle and a square.
*/

class Rectangle {
private:
    float length;
    float breadth;
public:
    Rectangle(float l, float b) : length(l), breadth(b) {}

    void area() {
        cout << "Area é: " << this->length * this->breadth << "\n";
    }

    void perimeter() {
        cout << "Perímetro é: " << 2 * (this->length + this->breadth) << "\n";
    }
};

class Square : public Rectangle {
public:
    Square(float side) : Rectangle(side, side) {}
};

int main() {

    Rectangle *r = new Rectangle(10, 5);
    Square *s = new Square(5);

    r->area();
    r->perimeter();

    s->area();
    s->perimeter();

    delete r;
    delete s;

    return 0;
}

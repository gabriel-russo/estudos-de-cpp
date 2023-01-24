#include <iostream>

/*
Write a program to print the area and perimeter of a triangle having
sides of 3, 4 and 5 units by creating a class named 'Triangle'
with a function to print the area and perimeter.
*/

class Triangle {
private:
    uint16_t side1;
    uint16_t side2;
    uint16_t side3;
public:
    void area_and_perimeter() {
        float area = (this->side1 * this->side2) / 2;

        uint16_t perimeter = (this->side1 + this->side2 + this->side3);

        std::cout << "Área: " << area << "\n";
        std::cout << "Perímetro: " << perimeter << "\n";
    }

    Triangle(uint16_t side1, uint16_t side2, uint16_t side3) {
        this->side1 = side1;
        this->side2 = side2;
        this->side3 = side3;
    }
};

int main() {

    Triangle *t = new Triangle(3, 4, 5);

    t->area_and_perimeter();

    delete t;

    return 0;
}

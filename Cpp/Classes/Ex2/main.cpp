#include <iostream>

/*
Write a program to print the volume of a box by creating a class named 'Volume'
with an initialization list to initialize its length, breadth and height.
(just to make you familiar with initialization lists)
*/

class Volume {
private:
    uint16_t length;
    uint16_t breadth;
    uint16_t height;

public:
    Volume(uint16_t length, uint16_t breadth, uint16_t height) : length(length), breadth(breadth), height(height) {}

    void show() {
        std::cout << "L: " << this->length << " B: " << this->breadth << " H: " << this->height << "\n";
        std::cout << "Volume: " << (this->length * this->breadth * this->height) << "\n";
    }

};

int main() {

    Volume *v = new Volume(190, 150, 86);

    v->show();

    delete v;

    return 0;
}

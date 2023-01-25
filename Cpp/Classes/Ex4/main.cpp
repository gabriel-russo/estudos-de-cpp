#include <iostream>

/*
Create a class with a function that prints
"This is parent class" and its subclass with another function that prints "This is child class".
Now, create an object for each class and call
1 - function of the parent class by the object of the parent class
2 - function of the child class by the object of the child class
3 - function of the parent class by the object of the child class
*/

class Parent {
public:
    void printParent() {
        std::cout << "This is parent class" << "\n";
    }
};

class Children : public Parent {
public:
    void printChildren() {
        std::cout << "This is children class" << "\n";
    }
};

int main() {

    Parent *p = new Parent();
    Children *c = new Children();

    // 1)
    p->printParent();

    // 2)
    c->printChildren();

    // 3)
    c->printParent();

    delete p;
    delete c;

    return 0;
}

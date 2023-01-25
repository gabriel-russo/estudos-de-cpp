#include <iostream>

using std::string, std::cout;

/*
Create a class named 'Programming'. While creating an object of the class, if nothing is passed to it, then
the message "I love programming languages" should be printed. If some String is passed to it, then in place
of "programming languages" the name of that String variable should be printed.
For example, while creating the object if we pass "cpp", then "I love cpp" should be printed.
*/

class Programming {
private:
    string language = "programming languages";
public:
    Programming(string language) : language(language) {}

    Programming() = default;

    void print() {
        cout << "I love " << this->language << "\n";
    }
};

int main() {

    Programming *p1 = new Programming();
    Programming *p2 = new Programming("cpp");

    p1->print();
    p2->print();

    delete p1;
    delete p2;

    return 0;
}

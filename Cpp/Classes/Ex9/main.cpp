#include <iostream>
#include <vector>

using std::vector, std::cout;

/*
Write a program to calculate the average height of all the students of a class.
 The number of students and their heights are entered by the user.
*/

class Student {
private:
    float height;
public:
    Student(float h) : height(h) {}

    float getHeight() {
        return this->height;
    }

};

int main() {

    vector <Student>
            classroom{
            Student(1.55),
            Student(1.80),
            Student(1.90),
            Student(1.69),
            Student(1.45),
            Student(1.70)
    };

    float sum = 0.0;

    for (int i = 0; i <= classroom.size(); i++) {
        sum += classroom[i].getHeight();
    }

    cout << "A média de altura dos alunos é: " << sum / classroom.size() << " metros" << "\n";

    return 0;
}

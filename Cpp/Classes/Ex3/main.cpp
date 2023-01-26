#include <iostream>

/*
Write a program by creating an 'Employee' class having the following functions and print the final salary.
1 - 'getInfo()' which takes the salary, number of hours of work per day of employee as parameters
2 - 'AddSal()' which adds $10 to the salary of the employee if it is less than $500.
3 - 'AddWork()' which adds $5 to the salary of the employee if the number of hours of work per day is more than 6 hours.
*/

class Employee {
private:
    float salary;
    unsigned short int work_hours_per_day;
public:
    Employee(float salary,
             unsigned short int work_hours_per_day
    ) : salary(salary), work_hours_per_day(work_hours_per_day) {}

    void getInfo() {
        std::cout << "Salário: " << this->salary << " || Horas trabalhadas por dia: " << this->work_hours_per_day
                  << "\n";
    }

    void addSal() {
        if (this->salary < 500) {
            this->salary += 10;
        }
    }

    void addWork() {
        if (this->work_hours_per_day > 6) {
            this->salary += 5;
        }
    }

};


int main() {

    Employee *e1 = new Employee(350, 8);
    Employee *e2 = new Employee(700, 3);

    std::cout << "Antes do checkup: ";
    e1->getInfo();

    e1->addSal();
    e1->addWork();

    std::cout << "Depois do checkup: ";
    e1->getInfo();

    std::cout << "\n ============== \n";

    std::cout << "Antes do checkup: ";
    e2->getInfo();

    e2->addSal();
    e2->addWork();

    std::cout << "Depois do checkup: ";
    e2->getInfo();

    delete e1;
    delete e2;

    return 0;
}

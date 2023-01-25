#include <iostream>

using std::string;

/*
Create a class named 'Member' having the following members:
Data members
1 - Name
2 - Age
3 - Phone number
4 - Address
5 - Salary
It also has a function named 'printSalary' which prints the salary of the members.
Two classes 'Employee' and 'Manager' inherits the 'Member' class. The 'Employee' and 'Manager'
classes have data members 'specialization' and 'department' respectively.
Now, assign name, age, phone number, address and salary to an employee and a manager by
making an object of both of these classes and print the same.
*/

class Member {
private:
    string name;
    uint16_t age;
    string phone;
    string address;
    float salary;
public:
    Member(string name, uint16_t age, string phone, string address, float salary)
            : name(name), age(age), phone(phone), address(address), salary(salary) {}

    void printSalary() {
        std::cout << "O salário de " << this->name << " é: " << this->salary << std::endl;
    }
};

class Employee : public Member {
private:
    string specialization;
public:
    Employee(string name, uint16_t age, string phone, string address, float salary, string espec)
            : Member(name, age, phone, address, salary), specialization(espec) {}
};

class Manager : public Member {
private:
    string department;
public:
    Manager(string name, uint16_t age, string phone, string address, float salary, string dept)
            : Member(name, age, phone, address, salary), department(dept) {}
};

int main() {

    Employee *e = new Employee("Gabriel",
                               22,
                               "999923934",
                               "Rua 1",
                               1299.99,
                               "Computer Scientist");

    Manager *m = new Manager("John Deer",
                             27,
                             "40028922",
                             "Rua 1",
                             3684.57,
                             "I.T");

    e->printSalary();
    m->printSalary();

    delete e;
    delete m;

    return 0;
}

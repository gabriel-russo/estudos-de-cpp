#include <iostream>

// Write a program that asks the user to enter integers as inputs to be stored 
// in the variables 'a' and 'b' respectively. There are also two integer pointers named 
// ptrA and ptrB. Assign the values of 'a' and 'b' to ptrA and ptrB respectively, and display them.

int main(){    
    
    int a;
    int b;

    std::cout << "Variable A: ";
    std::cin >> a;

    std::cout << "Variable B: ";
    std::cin >> b;

    int* ptrA = &a;
    int* ptrB = &b;

    std::cout << "Value of variable A: " << *ptrA << " Address of variable A: " << ptrA << std::endl;

    std::cout << "Value of variable B: " << *ptrB << " Address of variable B: " << ptrB << std::endl;

	return 0;
}


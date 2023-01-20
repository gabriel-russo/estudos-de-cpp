#include <iostream>

// Write a program to find the factorial of a number using pointers.  

int main(){    

    int num;
    std::cout << "Entre com um número: ";
    std::cin >> num;

	int* ptr = &num;
	
	std::cout << "Fatorial do numero " << num << " é ";

	for (int i = *ptr - 1; i > 0; i--){
		*ptr = *ptr * *(&i);
	}

	std::cout << *ptr << std::endl;

	return 0;
}


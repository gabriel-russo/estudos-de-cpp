#include <iostream>

// Write a function which will take pointer and display the number on screen. 
// Take number from user and print it on screen using that function.

void print_pointer(int* num){
	std::cout << "O valor do número é: " <<  *num << std::endl;
}

int main(){    
    
    int num;
    std::cout << "Entre com um número: ";
    std::cin >> num;
    
    print_pointer(&num);

	return 0;
}


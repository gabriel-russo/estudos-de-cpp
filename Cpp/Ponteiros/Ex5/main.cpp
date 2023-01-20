#include <iostream>

// Write a program to reverse the digits a number using pointers.   

void reverse_number(int* num){
	int reversed = 0;

	bool isNegative = (*num < 0);
	
	if (isNegative)
		*num = -(*num);

	while(*num > 0){
		reversed = reversed * 10 + *num % 10;
		*num = *num / 10;
	}

	*num = isNegative ? -reversed : reversed;
}

int main(){    

    int num;
    std::cout << "Entre com um número: ";
    std::cin >> num;

	reverse_number(&num);

	std::cout << "O número ao contrário é: " << num << std::endl;

	return 0;
}


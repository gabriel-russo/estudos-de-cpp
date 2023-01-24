#include <iostream>

/*
Write a C++ program to find the max of an integral data set. The program will ask
the user to input the number of data values in the set and each value.
The program prints on screen a pointer that points to the max value.
*/

int main() {

    int array_lenght;

    std::cout << "How many numbers in data set?: ";
    std::cin >> array_lenght;

    int array[array_lenght];

    int i = 0;
    while (i <= array_lenght) {
        int value;

        std::cout << "Enter the value " << i << " of " << array_lenght << " :";
        std::cin >> value;

        array[i] = value;

        i++;
    }

    int *ptr = nullptr;

    for (i = 0; i <= array_lenght; i++) {
        if (!ptr)
            ptr = &array[i];

        if (*ptr < array[i])
            ptr = &array[i];
    }

    std::cout << "O maior valor do array é: " << *ptr << std::endl;

    return 0;
}

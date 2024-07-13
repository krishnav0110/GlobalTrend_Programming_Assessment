#include <iostream>

unsigned int factorial(unsigned int n) {
	int fact = 1;
	for(int i = 2; i <= n; i++) {
		fact *= i;
    }
	return fact;
}





int main() {
	int num = 5;
	std::cout << "Number: " << num;
	std::cout << "\nFactorial: " << factorial(num);
	return 0;
}

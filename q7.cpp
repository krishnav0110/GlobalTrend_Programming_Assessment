#include <iostream>

int getSumOfDigits(int n) {
	int sum = 0;
	while(n) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}





int main() {
	int n = 213;
	std::cout << "Number: " << n;
	std::cout << "\nSum of digits: " << getSumOfDigits(n);
	return 0;
}
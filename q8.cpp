#include <iostream>

int gcd(int a, int b) {
	int result = std::min(a, b);
	while(result > 0) {
		if(a % result == 0 && b % result == 0) {
			break;
        }
		result--;
	}
	return result;
}





int main() {
	int a = 98, b = 56;
	std::cout << "Number 1: " << a;
	std::cout << "\nNumber 2: " << b;
	std::cout << "\nGCD: " << gcd(a, b);
	return 0;
}
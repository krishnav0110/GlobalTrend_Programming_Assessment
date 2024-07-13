#include <iostream>
#include <vector>
#include <random>

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

void rotateRightArray(std::vector<int> &array, int k) {
    int size = array.size();
    k %= size;
    std::vector<int> arr(k);

    for(int i = 0; i < k; i++) {
        arr[i] = array[i];
    }
    for(int i = 0; i < size - k; i++) {
        array[i] = array[i + k];
    }
    for(int i = 0; i < k; i++) {
        array[i + size - k] = arr[i];
    }
}

void printArray(const std::vector<int> &array) {
    for(int num: array) {
        std::cout << num << ", ";
    }
}





int main() {
    std::vector<int> array;
    std::default_random_engine random;
    for(int i = 0; i < 10; ++i) {
        array.emplace_back((int)(100.0f * random() / random.max()));
    }

    std::cout << "Array: ";
    printArray(array);

    int k = 6;
    std::cout << "\nRotating by k = " << k << "\n";

    rotateRightArray(array, k);
    std::cout << "Rotated Array: ";
    printArray(array);
    return 0;
}
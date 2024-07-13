#include <iostream>
#include <vector>
#include <random>

int getMaxDifference(const std::vector<int> &array) {
	int min = array[0];
	int max = array[0];
    int size = array.size();
	for (int i = 1; i < size; i++) {
		min = std::min(min, array[i]);
		max = std::max(max, array[i]);
	}
	return(max - min);
}

void printArray(const std::vector<int> &array) {
	for(int num: array) {
		std::cout << num << ", ";
	}
}





int main() {
	std::default_random_engine random;
    std::vector<int> array;
	for(int i = 0; i < 10; ++i) {
		array.emplace_back((int)(100.0f * random() / random.max()));
	}

	printArray(array);
	std::cout << "\nMax Difference: " << getMaxDifference(array);
	return 0;
}

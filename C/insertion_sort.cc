#include <iostream>
#include <vector>
std::vector<int> arr;

void insertion_sort();
void print();

int main() {
	int n, in;
	std::cin >> n;

	while( n-- ) {
		std::cin >> in;
		arr.push_back(in);
	}

	insertion_sort();

	print();
}

void insertion_sort() {
	for (int i = 1; i < arr.size(); ++ i) {
		int key = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			-- j;
		}
		arr[j + 1] = key;	
	}
}

void print() {
	for (auto i = arr.begin(); i != arr.end(); ++ i) {
		std::cout << *i << ' ';
	}
	std::cout << '\n';
}
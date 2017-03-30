#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <unistd.h>

const int cases = 5;
const int range = 100;
int input[cases];
int left[cases];
int right[cases];
int inversion = 0;

void generate_input(int);
void merge_sort(int, int);
void merge(int, int, int);
void print_output();

int main() {
	generate_input(cases);
	merge_sort(0, cases);
	print_output();
}

void generate_input(int size) {
	srand(time(NULL));
	std::cout << "The Init Random Array is:\n";
	for(int i = 0; i < size; ++i ) {
		input[i] = rand() % range + 1;
		std::cout << input[i] << " ";
	}
	std::cout << "\n";
}

void merge_sort(int start, int end) {
	if(start + 1 == end)
		return;

	int mid = (start + end) / 2;
	merge_sort(start, mid);
	merge_sort(mid, end);
	merge(start, mid, end);
}

void merge(int start, int mid, int end) {
	int nl = mid - start;
	int nr = end - mid;

	// sentinal
	left[nl] = std::numeric_limits<int>::max();
	right[nr] = std::numeric_limits<int>::max();

	for(int i = 0; i < nl; ++i)
		left[i] = input[start + i];

	for(int i = 0; i < nr; ++i)
		right[i] = input[mid + i];

	int l = 0, r = 0;

	for(int i = start; i < end; ++i) {
		if(left[l] <= right[r]) {
			input[i] = left[l++];
		} else {
			input[i] = right[r++];
			inversion += (nl - l);
		}
	}
}

void print_output() {
	std::cout << "After Merge Sort:\n";
	for(int i = 0; i < cases; ++i) {
		std::cout << input[i] << ' ';
	}
	std::cout << '\n';
	std::cout << "Number of inversion: " << inversion << '\n';
}

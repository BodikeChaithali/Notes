#include <stdio.h>

int sum_array(int arr[], int size) {
	int sum = 0;
	for(int i = 0; i < size; i++)
		sum += arr[i];
	return sum;
}

int max_element(int arr[], int size) {
	int max = arr[0];
	for(int i = 1; i < size; i++) {
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}

int main() {
	int data[] = {4, 8, 15, 16, 23, 42};
	int n = sizeof(data) / sizeof(data[0]);
	int total = sum_array(data, n);
	printf("Sum: %d\n", total);
	int maximum = max_element(data, n);
	printf("Max: %d\n", maximum);
	return 0;
}

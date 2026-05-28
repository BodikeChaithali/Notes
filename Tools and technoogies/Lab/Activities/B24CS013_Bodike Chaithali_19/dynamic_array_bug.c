#include<stdio.h>
#include<stdlib.h>

#define CAPACITY 5

typedef struct {
	int* data;
	int size;
	int capacity;
} DynamicArray;

void initArray(DynamicArray* arr) {
	arr->data = malloc(sizeof(int) * CAPACITY);
	arr->size = 0;
	arr->capacity = CAPACITY;
}

void insert(DynamicArray* arr, int index, int value) {
	if (index < 0 || index > arr->size || arr->size == arr->capacity) {
		printf("Insert Error: Invalid index or array full\n");
		return;
	}
	// Shift elements right to make space (fixed)
	for (int i = arr->size - 1; i >= index; i--) 
    		arr->data[i + 1] = arr->data[i];
	arr->data[index] = value;
	arr->size++;
}

void removeAt(DynamicArray* arr, int index) {
	if (index < 0 || index >= arr->size) {
		printf("Remove Error: Invalid index\n");
		return;
	}
	for (int i = index; i < arr->size - 1; i++) 
		arr->data[i] = arr->data[i+1];
	arr->size--;
}

void printArray(DynamicArray* arr) {
	printf("Array contents: ");
	for (int i = 0; i < arr->size; i++) 
		printf("%d ", arr->data[i]);
	printf("\n");
}

int main() {
	DynamicArray arr;
	initArray(&arr);
	insert(&arr, 0, 10);
	insert(&arr, 1, 20);
	insert(&arr, 2, 30);
	insert(&arr, 1, 15);
	insert(&arr, 4, 40);
	printArray(&arr);
	removeAt(&arr, 2);
	printArray(&arr);
	insert(&arr, 2, 25);
	printArray(&arr);
	insert(&arr, 5, 50);
	insert(&arr, -1, 60);
	free(arr.data);
	return 0;
}

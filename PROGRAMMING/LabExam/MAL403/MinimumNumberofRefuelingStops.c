#include <stdio.h>
#include <stdlib.h>

/* ---------- Max Heap Functions ---------- */

void heapSwap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapUp(int *heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[parent] < heap[idx]) {
            heapSwap(&heap[parent], &heap[idx]);
            idx = parent;
        } else {
            break;
        }
    }
}

void heapDown(int *heap, int size, int idx) {
    while (1) {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;
        int largest = idx;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != idx) {
            heapSwap(&heap[idx], &heap[largest]);
            idx = largest;
        } else break;
    }
}

void heapPush(int *heap, int *size, int val) {
    heap[*size] = val;
    (*size)++;
    heapUp(heap, *size - 1);
}

int heapPop(int *heap, int *size) {
    int top = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapDown(heap, *size, 0);
    return top;
}

/* ---------- Main Solution Function ---------- */

int minRefuelStops(int target, int startFuel, int** stations, int stationsSize, int* stationsColSize) {
    int fuel = startFuel;
    int stops = 0;
    
    int *maxHeap = (int*)malloc(sizeof(int) * (stationsSize + 5));
    int heapSize = 0;
    
    int i = 0;
    
    while (fuel < target) {
        while (i < stationsSize && stations[i][0] <= fuel) {
            heapPush(maxHeap, &heapSize, stations[i][1]);
            i++;
        }

        if (heapSize == 0)
            return -1;

        fuel += heapPop(maxHeap, &heapSize);
        stops++;
    }
    
    free(maxHeap);
    return stops;
}

/* ---------- Full Working main() for Testing ---------- */

int main() {
    int target, startFuel, stationsSize;

    printf("Enter target distance: ");
    scanf("%d", &target);

    printf("Enter starting fuel: ");
    scanf("%d", &startFuel);

    printf("Enter number of stations: ");
    scanf("%d", &stationsSize);

    int** stations = (int**)malloc(stationsSize * sizeof(int*));
    int* stationsColSize = (int*)malloc(stationsSize * sizeof(int));

    printf("Enter stations as <position fuel>:\n");
    for (int i = 0; i < stationsSize; i++) {
        stations[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &stations[i][0], &stations[i][1]);
        stationsColSize[i] = 2;
    }

    int result = minRefuelStops(target, startFuel, stations, stationsSize, stationsColSize);
    printf("Minimum refueling stops = %d\n", result);

    for (int i = 0; i < stationsSize; i++)
        free(stations[i]);
    free(stations);
    free(stationsColSize);

    return 0;
}

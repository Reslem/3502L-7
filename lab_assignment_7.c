#include <stdio.h>
#include <stdlib.h>

int bSort(int* array, int* swap, int n) {
    int totalSwaps = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (array[j+1] < array[j]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swap[array[j]]++;
                swap[array[j+1]]++;
                totalSwaps++;
            }
        }
    }
    return totalSwaps;
}

int sSort(int* array, int* swap, int n) {
    int totalSwaps = 0;
    for (int i = 0; i < n; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (array[j] < array[minIdx]) {
                minIdx = j;
            }
        }
        if (i != minIdx) {
            int temp = array[i];
            array[i] = array[minIdx];
            array[minIdx] = temp;
            swap[array[i]]++;
            swap[array[minIdx]]++;
            totalSwaps++;
        }
    }
    return totalSwaps;
}

int main() {
    const size_t size = 9;
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int swap1[100] = {0};
    int swap2[100] = {0};
    
    printf("Array 1 Bubble Sort: \n");
    printf("Total swaps: %d\n", bSort(array1, swap1, size));
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", array1[i], swap1[array1[i]]);
    }
    
    printf("Array 2 Bubble Sort: \n");
    printf("Total swaps: %d\n", bSort(array2, swap2, size));
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", array2[i], swap2[array2[i]]);
    }

    int array1s[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2s[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int swap1s[100] = {0};
    int swap2s[100] = {0};

    printf("Array 1 Selection Sort: \n");
    printf("Total swaps: %d\n", sSort(array1s, swap1s, size));
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", array1s[i], swap1s[array1s[i]]);
    }

    printf("Array 2 Selection Sort: \n");
    printf("Total swaps: %d\n", sSort(array2s, swap2s, size));
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", array2s[i], swap2s[array2s[i]]);
    }

    return 0;
}
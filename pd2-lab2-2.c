#include <stdio.h>

int findMax(int array[], int size) {
    
    if (size == 0) {
        return -1; 
    }

    
    int lastElement = array[size - 1];

    
    int restMax = findMax(array, size - 1);

    
    return (lastElement > restMax) ? lastElement : restMax;
}

int main() {
    int array[] = {3, 8, 1, 6, 2, 5, 7, 4};
    int size = sizeof(array) / sizeof(array[0]);

    int maxElement = findMax(array, size);

    printf("Dizinin en buyuk elemani: %d\n", maxElement);

    return 0;
}


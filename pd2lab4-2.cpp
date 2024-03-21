#include <stdio.h>

int countOddNumbers(int *arr, int size)
{
    
    if (size == 0)
        return 0;

    
    int count = (*arr % 2 == 1) ? 1 : 0;

   
    count += countOddNumbers(arr + 1, size - 1);

    return count;
}

int main()
{
    
    int myArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arraySize = sizeof(myArray) / sizeof(myArray[0]);

    int oddCount = countOddNumbers(myArray, arraySize);

    printf("Number of odd numbers in the array: %d\n", oddCount);

    return 0;
}


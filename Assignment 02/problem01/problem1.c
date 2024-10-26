/*
* Name: Asad Imran 
* ID: 24K-0721
* File: problem1.c
* Date: 16 October 2024
*/

#include <stdio.h>

int main() {
    int n = 5, arr[5], smallest, second_smallest;

    printf("Input 5 elements in the array (value must be < 9999)!\n");

    for (int i = 0; i < n; i++) {
        printf("element - %d: ", i);
        scanf("%d", &arr[i]);
    }

    if (arr[0] > arr[1]) {
        smallest = arr[1];
        second_smallest = arr[0];
    } else {
        smallest = arr[0];
        second_smallest = arr[1];
    }

    for (int i = 2; i < n; i++) {
        if (arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < second_smallest && arr[i] != smallest) {
            second_smallest = arr[i];
        }
    }

    printf("The Second smallest element in the array is: %d\n", second_smallest);

    return 0;
}

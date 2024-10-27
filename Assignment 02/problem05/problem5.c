#include <stdio.h>

// Function to print the horizontal histogram
void printHorizontalHistogram(int values[], int count) {
    printf("Horizontal Histogram\n");
    for (int i = 0; i < count; i++) {
        printf("Value %d: ", i + 1);
        for (int j = 0; j < values[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print the vertical histogram
void printVerticalHistogram(int values[], int count) {
    printf("Vertical Histogram\n");
    
    // Finding the maximum value for determining the height of the histogram
    int max = values[0];
    for (int i = 1; i < count; i++) {
        if (values[i] > max) {
            max = values[i];
        }
    }
    
    // Print the histogram from the top down
    for (int i = max; i > 0; i--) {
        for (int j = 0; j < count; j++) {
            if (values[j] >= i) {
                printf("* "); // Print asterisks where the value is >= current height
            } else {
                printf("  "); // Print spaces where the value is < current height
            }
        }
        printf("\n"); // New line after each level
    }
    
    // Print the values below the histogram
    for (int i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    printf("\n"); // New line after printing values
}

int main() {
    int values[] = {6, 2, 9, 4};
    int count = sizeof(values) / sizeof(values[0]); // Calculate the count of values

    // Generate histograms
    printHorizontalHistogram(values, count);
    printf("\n"); 
    printVerticalHistogram(values, count);

    return 0;
}

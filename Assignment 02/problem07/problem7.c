#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  // Include time.h for seeding rand()

#define ROWS 6
#define COLS 5

// Function to generate a 2D array with random alphabet characters based on time seed
void generateArray(char array[ROWS][COLS], int studentID) {
    // Fill the first 5 rows with random letters
    for (int i = 0; i < ROWS - 1; i++) {
        for (int j = 0; j < COLS; j++) {
            array[i][j] = 'A' + (rand() % 26); // Generates a letter from 'A' to 'Z'
        }
    }

    // Fill the last row with the last four digits of the student ID and a random letter
    int lastFourDigits = studentID % 10000;
    for (int i = COLS - 2; i >= 0; i--) {
        array[ROWS - 1][i] = '0' + (lastFourDigits % 10); // Convert each digit to a character
        lastFourDigits /= 10;
    }
    array[ROWS - 1][COLS - 1] = 'A' + (rand() % 26); // Random letter in the last column
}

// Function to print the 2D array in a tabular format
void printArray(char array[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
}

// Function to search for a string horizontally and vertically
int searchString(char array[ROWS][COLS], char* str) {
    int len = strlen(str);

    // Search left to right
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLS - len; j++) {
            if (strncmp(&array[i][j], str, len) == 0) {
                return 1; // String found
            }
        }
    }

    // Search top to bottom
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i <= ROWS - len; i++) {
            int match = 1;
            for (int k = 0; k < len; k++) {
                if (array[i + k][j] != str[k]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                return 1; // String found
            }
        }
    }

    return 0; // String not found
}

int main() {
    char array[ROWS][COLS];
    int studentID = 721; // Replace with your actual student ID
    char searchStr[50];
    int score = 0;

    srand(time(NULL));  // Seed the random number generator with current time

    // Generate and print the initial array
    generateArray(array, studentID);
    printArray(array);

    // Main loop to search for strings
    while (1) {
        printf("Search Str= ");
        scanf("%s", searchStr);

        // End program if "END" is entered
        if (strcmp(searchStr, "END") == 0) {
            generateArray(array, studentID); // Re-generate array with new random characters
            printArray(array); // Print the new array
            continue;
        }

        // Search for the string in the array
        if (searchString(array, searchStr)) {
            score++;
            printf("%s is present. Score: %d\n", searchStr, score);
        } else {
            score--;
            printf("%s is not present. Score: %d\n", searchStr, score);
        }
    }

    return 0;
}

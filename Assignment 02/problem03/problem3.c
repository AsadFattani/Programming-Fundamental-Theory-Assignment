/*
* Name: Asad Imran 
* ID: 24K-0721
* File: problem3.c
* Date: 16 October 2024
*/

#include <stdio.h>

void compressWords(char words[][20], int numWords) {
    // string can be up to 19 characters long (20 including the null terminator)
    char result[20]; 
    int removedCount;

    // Process each word
    for (int i = 0; i < numWords; i++) {
        removedCount = 0;
        int j = 0; // Index for the result array

        // Compress current word k to k - 1
        for (int k = 0; words[i][k] != '\0'; k++) {
            if (k == 0 || words[i][k] != words[i][k - 1]) {
                result[j++] = words[i][k];
            } else {
                removedCount++;
            }
        }
        result[j] = '\0'; // Null-terminate to end the string

        printf("Original: %s, Compressed: %s, Characters removed: %d\n", words[i], result, removedCount);
    }
}// end function compressWords

int main() {
    // Example input: an array of words
    char words[3][20] = {"booooook", "coooool", "heeeey"};
    int numWords = 3;

    // calling the function
    compressWords(words, numWords);

    return 0;
}

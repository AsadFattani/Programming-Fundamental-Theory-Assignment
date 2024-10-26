#include <stdio.h>
#include <string.h>

#define Max_Transaction 100
#define Max_Length 20    

// Sorting the string characters in ascending order
void sortString(char* str){ //direct replace the original
    int length = strlen(str);
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (str[i] > str[j]) {
                // Character swap 
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

// Function to group anagrams
void groupAnagrams(char transactions[][Max_Length], int numTransactions) {
    char sorted[Max_Transaction][Max_Length]; // To hold sorted versions of transactions
    int groupCount[Max_Transaction] = {0}; // To count occurrences of each sorted string
    int groupIndex = 0; // To track the number of unique groups

    for (int i = 0; i < numTransactions; i++) {
        char temp[Max_Length];
        strcpy(temp, transactions[i]); // Copy the current transaction
        sortString(temp); // Sort the copied transaction

        // Check if the sorted string is already in the sorted array
        int found = 0;
        for (int j = 0; j < groupIndex; j++) {
            if (strcmp(temp, sorted[j]) == 0) {
                found = 1; // Found an existing group
                break;
            }
        }

        // If not found, add the sorted string to the sorted array
        if (!found) {
            strcpy(sorted[groupIndex], temp); // Add the sorted string
            groupCount[groupIndex] = 1; // Initialize count
            groupIndex++; // Move to the next group
        } else {
            // If found, increment the count for that group
            groupCount[groupIndex - 1]++;
        }
    }

    // Output the grouped anagrams
    printf("[");
    for (int i = 0; i < groupIndex; i++) {
        printf("[");

        
        int first = 1; // Flag to manage comma placement
        for (int j = 0; j < numTransactions; j++) {
            char temp[Max_Length];
            strcpy(temp, transactions[j]);
            sortString(temp);
            if (strcmp(temp, sorted[i]) == 0) {
                if (!first) {
                    printf(", "); // Print comma before every transaction except the first
                }
                printf("'%s'", transactions[j]); // Print the original transaction
                first = 0; // After the first transaction, set flag to false
            }
        }

        printf("]");
    }
    printf("]");
}

// Main function
int main() {
    // Example input
    char transactions[Max_Transaction][Max_Length] = {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };
    int numTransactions = 6; // Total number of transactions

    // Group and display anagrams
    groupAnagrams(transactions, numTransactions);

    return 0;
}

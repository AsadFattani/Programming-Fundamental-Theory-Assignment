#include <stdio.h>
#include <string.h>

void analyze_slogan(const char *slogan) {
    int freq[256] = {0}; // Array to hold frequency of characters
    int length = strlen(slogan);
    
    // Count the frequency of each character
    for (int i = 0; i < length; i++) {
        freq[(unsigned char)slogan[i]]++;
    }
    
    // Print the results in the expected format
    printf("For \"%s\": {", slogan);
    int first = 1; // To handle comma placement
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            if (!first) {
                printf(", "); // Print comma before all but the first entry
            }
            printf("'%c': %d", i, freq[i]);
            first = 0; // Set first to false after the first entry
        }
    }
    printf("}\n");
}

int main() {
    const char *slogans[] = {
        "buy now",
        "save big",
        "limited offer"
    };
    int num_slogans = sizeof(slogans) / sizeof(slogans[0]);

    // Analyze each slogan
    for (int i = 0; i < num_slogans; i++) {
        analyze_slogan(slogans[i]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert binary to decimal
int BinaryToDecimal(int number) {
    int decimal = 0, base = 1;
    while (number > 0) {
        int last_digit = number % 10;
        decimal += last_digit * base;
        base *= 2;
        number /= 10;
    }
    return decimal;
}

// Function to convert decimal to binary
int DecimalToBinary(int number) {
    int binary = 0, base = 1;
    while (number > 0) {
        int remainder = number % 2;
        binary += remainder * base;
        base *= 10;
        number /= 2;
    }
    return binary;
}

// Function to convert decimal to hexadecimal
void DecimalToHexadecimal(int number) {
    char hex[20];
    int i = 0;
    while (number != 0) {
        int temp = number % 16;
        if (temp < 10) {
            hex[i] = temp + '0';  // Convert to character
        } else {
            hex[i] = temp - 10 + 'A';  // Convert to character A-F
        }
        number /= 16;
        i++;
    }
    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        putchar(hex[j]);
    }
    printf("\n");
}

// Function to convert hexadecimal to decimal
void HexadecimalToDecimal(char hexNumber[]) {
    int decimal = 0;
    for (int i = 0; hexNumber[i] != '\0'; i++) {
        decimal *= 16;
        char c = hexNumber[i];
        if (c >= '0' && c <= '9') {
            decimal += c - '0';  // Convert '0'-'9' to 0-9
        } else if (c >= 'A' && c <= 'F') {
            decimal += c - 'A' + 10;  // Convert 'A'-'F' to 10-15
        } else if (c >= 'a' && c <= 'f') {
            decimal += c - 'a' + 10;  // Convert 'a'-'f' to 10-15
        }
    }
    printf("Decimal: %d\n", decimal);
}

// Function to convert binary to hexadecimal
void BinaryToHexadecimal(int number) {
    int decimal = BinaryToDecimal(number);
    DecimalToHexadecimal(decimal);
}

// Function to convert hexadecimal to binary
void HexadecimalToBinary(char hexNumber[]) {
    int decimal = 0;
    for (int i = 0; hexNumber[i] != '\0'; i++) {
        decimal *= 16;
        char c = hexNumber[i];
        if (c >= '0' && c <= '9') {
            decimal += c - '0';  // Convert '0'-'9' to 0-9
        } else if (c >= 'A' && c <= 'F') {
            decimal += c - 'A' + 10;  // Convert 'A'-'F' to 10-15
        } else if (c >= 'a' && c <= 'f') {
            decimal += c - 'a' + 10;  // Convert 'a'-'f' to 10-15
        }
    }
    int binary = DecimalToBinary(decimal);
    printf("Binary: %d\n", binary);
}

int main() {
    int choice, decimal, binary;
    char hexNumber[20];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Hexadecimal to Decimal\n");
        printf("5. Binary to Hexadecimal\n");
        printf("6. Hexadecimal to Binary\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%d", &binary);
                printf("Decimal: %d\n", BinaryToDecimal(binary));
                break;
            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                printf("Binary: %d\n", DecimalToBinary(decimal));
                break;
            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                DecimalToHexadecimal(decimal);
                break;
            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToDecimal(hexNumber);
                break;
            case 5:
                printf("Enter a binary number: ");
                scanf("%d", &binary);
                BinaryToHexadecimal(binary);
                break;
            case 6:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToBinary(hexNumber);
                break;
            case 7:
                exit(0);  // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

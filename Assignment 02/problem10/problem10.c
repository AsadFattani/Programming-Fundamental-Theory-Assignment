#include <stdio.h>


// for n=3
//     *
//    * *
// ***   ***
//  *     *
//   *   *
//  * * * *
// *       *




// for n=5
//         *
//        * *
//       *   *
//      *     *
// *****       *****
//  *             *
//   *           *
//    *         *
//     *       *
//    *   * *   *
//   *  *     *  *
//  * *         * *
// *               *


void printStar(int n){
    for (int i = 1; i < n;i++){

        //Print spaces for first lines
        for (int j = 0; j < 2 * n - 1 - i; j++){
            printf(" ");
        }

        // Print stars and spaces for the hollow effect
        for (int k = 1; k <= (2 * i - 1); k++) {
            if (k == 1 || k == (2 * i - 1) || i == n) {
                printf("*"); // Print star for the border or the last row
            } else {
                printf(" "); // Print space for hollow effect
            }
        }

    printf("\n");
    }
    // printing the line with straight hands
    for (int l = 0; l < (4 * n) - 3; l++) {
        if (l < n || l >= (4 * n - 3 ) - n){
            printf("*");
        }else{
            printf(" ");
        }

    }
    printf("\n");

    // printing the spaces and stericks for the mid section 
    for (int m = 1; m <= n - 1; m++) {
        for (int o = 0; o < m; o++) {
            printf(" ");
        }
        printf("*");
        for (int p = 0; p <= ((4 * n - 7) - 2 * m + 1); p++) {
            printf(" ");
        }
        if (m < 4 * n - 7) {
            printf("*");
        }
        printf("\n");
    }

    // printing the lower/ending section 

    for (int q = 1; q <= n - 2; q++){
        for (int r = n-2; r >= 0 + q; r--) {
            printf(" ");
        }
        printf("*");
        for (int r = n-2; r >= 0 + q; r--) {
            printf(" ");
        }
        printf("*");

        
        if (n == 3) {
        printf(" "); // Only one underscore
        } 
        // Handle the case when n = 5 or greater
        else if (n >= 5) {
                // Calculate the number of underscores based on the pattern
                int underscoresCount = 1 + (q - 1) * 4; // 1, 5, 9
                
                // Print leading underscores
                for (int t = 0; t < 1 + (q - 1) * 4; t++) {
                    printf(" ");
                }
        }
        
        printf("*");
        for (int r = n-2; r >= 0 + q; r--) {
            printf(" ");
        }
        printf("*");
            printf("\n"); // Move to the next line after printing underscores
    }




    // printing the last line
    printf("*");
    for (int u = 1; u <= 4 * n - 5; u++){
        printf(" ");
    }
    printf("*");

    printf("\n");
}

int main(){
    int n;
    printf("Enter num: ");
    scanf("%d", &n);

    printStar(n);

    return 0;
}
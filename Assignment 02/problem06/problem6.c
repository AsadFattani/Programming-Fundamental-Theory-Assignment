#include <stdio.h>

int firstMoveToWin(int N) {
    // If N is a multiple of 5, A cannot guarantee a win
    if (N % 5 == 0) {
        return -1;
    }
    // Otherwise, A should pick N % 5 matchsticks to leave a multiple of 5 for B
    return N % 5;
}

int main() {
    int N; 
    printf("Enter a sampple value: ");
    scanf("%d", &N);
    int result = firstMoveToWin(N);
    if (result == -1) {
        printf("It's impossible for A to guarantee a win.\n");
    } else {
        printf("A should pick %d matchstick(s) on the first turn to guarantee a win.\n", result);
    }
    return 0;
}

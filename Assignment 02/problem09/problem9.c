#include <stdio.h>

// Function to display the grid
void displayGrid(char grid[5][5]) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to find the player's current position
void findPlayerPosition(char grid[5][5], int *playerX, int *playerY) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (grid[i][j] == 'P') {
                *playerX = i;
                *playerY = j;
                return;
            }
        }
    }
}

// Function to handle player movement
void movePlayer(char grid[5][5], char direction) {
    int playerX, playerY;
    findPlayerPosition(grid, &playerX, &playerY);

    int newX = playerX;
    int newY = playerY;

    // Update new position based on input direction
    switch (direction) {
        case 'W': // Move up
            newX--;
            break;
        case 'S': // Move down
            newX++;
            break;
        case 'A': // Move left
            newY--;
            break;
        case 'D': // Move right
            newY++;
            break;
        case 'Q': // Quit
            return; // Just return to exit the game
        default:
            printf("Invalid move. Please enter W, A, S, D or Q.\n");
            return;
    }

    // Check for boundaries and obstacles
    if (newX < 0 || newX >= 5 || newY < 0 || newY >= 5 || grid[newX][newY] == 'X') {
        printf("Invalid move. You hit an obstacle or went out of bounds!\n");
    } else {
        // Collect item if present
        if (grid[newX][newY] == 'I') {
            printf("You collected an item!\n");
        }

        // Move the player to the new position
        grid[playerX][playerY] = ' '; // Clear old position
        grid[newX][newY] = 'P'; // Set new position
    }
}

int main() {
    char grid[5][5] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    char move;
    while (1) {
        displayGrid(grid);
        printf("Enter your move (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c", &move); // Space before %c to ignore any whitespace

        if (move == 'Q') {
            printf("Thank you for playing!\n");
            break;
        }

        movePlayer(grid, move);
    }

    return 0;
}

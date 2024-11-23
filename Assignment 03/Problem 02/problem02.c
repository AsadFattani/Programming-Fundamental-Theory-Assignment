#include <stdio.h>
#include <string.h>

struct Player {
    int ballScores[12]; // Change char to int
    char playerNames[100];
    int totalScore;
};

int validateScore(int score); // Change void to int

void playGame(struct Player *player1, struct Player *player2){
    const int balls = 12;

    for (int i = 0; i < balls; i++) {
        printf("Enter %s's score for ball # %d: ", player1->playerNames, i + 1);
        scanf("%d", &player1->ballScores[i]);
        player1->ballScores[i] = validateScore(player1->ballScores[i]);
        player1->totalScore += player1->ballScores[i];

        printf("Enter %s's score for ball # %d: ", player2->playerNames, i + 1);
        scanf("%d", &player2->ballScores[i]);
        player2->ballScores[i] = validateScore(player2->ballScores[i]);
        player2->totalScore += player2->ballScores[i];
    }   
}

int validateScore(int score) { // Change void to int
    if (score < 0 || score > 6) {
        printf("Invalid score: %d. Score must be between 0 and 6.\n", score);
        return 0; // Return 0 for invalid score
    }
    return score; // Return valid score
}

void findWinner(struct Player player1, struct Player player2){
    if (player1.totalScore > player2.totalScore) {
        printf("Player %s wins with %d runs\n", player1.playerNames, player1.totalScore);
    } else if (player1.totalScore < player2.totalScore) {
        printf("Player %s wins with %d runs\n", player2.playerNames, player2.totalScore);
    } else {
        printf("Match is a draw\n");
    }
}

void displayMatchScoreboard(struct Player player1, struct Player player2){
    printf("Player %s scored %d runs\n", player1.playerNames, player1.totalScore);
    printf("Player %s scored %d runs\n", player2.playerNames, player2.totalScore);
}

int main() {
    struct Player player1, player2;
    printf("Enter player 1 name: ");
    fgets(player1.playerNames, 100, stdin);
    player1.playerNames[strcspn(player1.playerNames, "\n")] = '\0'; // Remove newline character
    player1.totalScore = 0; // Initialize totalScore to 0

    printf("Enter player 2 name: ");
    fgets(player2.playerNames, 100, stdin);
    player2.playerNames[strcspn(player2.playerNames, "\n")] = '\0'; // Remove newline character
    player2.totalScore = 0; // Initialize totalScore to 0

    playGame(&player1, &player2);
    displayMatchScoreboard(player1, player2);
    findWinner(player1, player2);

    return 0;
}

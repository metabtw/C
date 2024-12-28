#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to initialize the game board
void initializeBoard(char board[3][3]) {
    int cell = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = cell + '0';
            cell++;
        }
    }
}

// Function to display the current state of the board
void displayBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2) {
            printf("\n---+---+---\n");
        }
    }
    printf("\n\n");
}

// Function to check if a move is valid
bool isValidMove(char board[3][3], int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (position < 1 || position > 9) {
        return false;
    }

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }

    return true;
}

// Function to make a move
void makeMove(char board[3][3], int position, char symbol) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    board[row][col] = symbol;
}

// Function to check if there's a winner
bool checkWinner(char board[3][3], char symbol) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return true;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return true;
    }

    return false;
}

// Function to check if the board is full (draw)
bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[3][3];
    int position;
    char currentPlayer = 'X';
    bool gameWon = false;

    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1: X\nPlayer 2: O\n");
    printf("Enter positions (1-9) to make your move:\n");

    initializeBoard(board);
    displayBoard(board);

    while (!gameWon && !isBoardFull(board)) {
        printf("Player %c's turn. Enter position: ", currentPlayer);
        scanf("%d", &position);

        if (!isValidMove(board, position)) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        makeMove(board, position, currentPlayer);
        displayBoard(board);

        if (checkWinner(board, currentPlayer)) {
            printf("Player %c wins!\n", currentPlayer);
            gameWon = true;
        } else if (isBoardFull(board)) {
            printf("It's a draw!\n");
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}

# Tic Tac Toe Game in C
A simple command-line implementation of the classic Tic Tac Toe game for two players.
----
**Features**

Two-player gameplay (X and O)
Visual game board display
Input validation
Win detection
Draw detection

**Functions Description**

*void initializeBoard(char board[3][3])*

Initializes the game board with numbers 1-9
Each number represents a cell position where players can make their moves

----

*void displayBoard(char board[3][3])*

Displays the current state of the board
Shows a formatted 3x3 grid with cell contents and dividing lines

----

*bool isValidMove(char board[3][3], int position)*

Validates if a move is legal
Checks if:

Position is within range (1-9)
Selected cell is not already occupied

----

*void makeMove(char board[3][3], int position, char symbol)*

Places the player's symbol (X or O) in the specified position
Converts the position (1-9) to corresponding row and column indices

----

*bool checkWinner(char board[3][3], char symbol)*

Checks if the current player has won
Verifies all winning conditions:

Three in a row (horizontal)
Three in a column (vertical)
Three in a diagonal

----

*bool isBoardFull(char board[3][3])*

Checks if the game board is full (draw condition)
Returns true if no empty cells remain

----

How to Play

The game starts with an empty 3x3 grid numbered 1-9
Players take turns placing their symbols (X or O)
Enter a number (1-9) to place your symbol in the corresponding cell
First player to get three symbols in a row (horizontal, vertical, or diagonal) wins
If all cells are filled and no winner is found, the game is a draw

----

Technical Implementation

Uses a 2D char array to represent the game board
Position input is converted to row/column indices using integer division and modulo
Game loop continues until there's a winner or draw
Input validation prevents illegal moves
Player turns alternate between X and O

Would you like me to make any modifications to the code or add more documentation for your GitHub repository?

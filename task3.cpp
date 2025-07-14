#include <iostream>
using namespace std;

// 3x3 Board
char board[3][3];

// Initialize board with 1-9
void initializeBoard() {
    char num = '1';
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = num++;
}

// Display board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n---+---+---\n";
    }
    cout << "\n";
}

// Check for a win
bool checkWin(char player) {
    // Rows and Columns
    for (int i = 0; i < 3; ++i)
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;

    // Diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

// Check for a draw
bool checkDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Make a move
bool makeMove(char player) {
    int choice;
    cout << "Player " << player << ", enter your move (1-9): ";
    cin >> choice;

    if (choice < 1 || choice > 9) {
        cout << "Invalid choice. Try again.\n";
        return false;
    }

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "That cell is already taken. Try again.\n";
        return false;
    }

    board[row][col] = player;
    return true;
}

// Main game loop
void playGame() {
    char currentPlayer = 'X';
    bool gameOver = false;

    initializeBoard();

    while (!gameOver) {
        displayBoard();
        if (!makeMove(currentPlayer)) continue;

        if (checkWin(currentPlayer)) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } else if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            gameOver = true;
        } else {
            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

// Main menu
int main() {
    char playAgain;

    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}

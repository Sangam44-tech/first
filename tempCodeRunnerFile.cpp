#include <iostream>
using namespace std;

// Function prototypes
void displayBoard(char board[3][3]);
bool isWinner(char board[3][3], char mark);
bool isDraw(char board[3][3]);

int main() {
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int choice;
    int row, col;
    char currentPlayer = 'X';
    bool gameRunning = true;

    cout << "Welcome to Tic Tac Toe!" << endl;

    while (gameRunning) {
        // Display the current state of the board
        displayBoard(board);

        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> choice;

        if (choice >= 1 && choice <= 9) {
            row = (choice - 1) / 3;
            col = (choice - 1) % 3;

            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = currentPlayer; 
            } else {
                cout << "Cell already taken! Try again." << endl;
                continue;
            }
        } else {
            cout << "Invalid input! Enter a number between 1 and 9." << endl;
            continue;
        }

        if (isWinner(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
            gameRunning = false;
        } 
        else if (isDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            gameRunning = false;
        } 
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}

void displayBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
            if (j < 2) cout << "| ";
        }
        cout << "\n";
        if (i < 2) cout << "--+---+--\n";
    }
    cout << "\n";
}


bool isWinner(char board[3][3], char mark) {
    
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) || 
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) {
            return true;
        }
    }

    
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
        return true;
    }

    return false;
}

bool isDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

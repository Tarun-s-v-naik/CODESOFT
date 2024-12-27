#include <iostream>
using namespace std;

void table();
void game();
bool result();
void resetBoard();

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
char token = 'x';
bool draw = false;
string n1 = "", n2 = "";

int main() {
    cout << "XO...TIC-TAC-TOE...XO" << endl;
    cout << "Enter the name of the first player: ";
    cin >> n1;
    cout << "Enter the name of the second player: ";
    cin >> n2;
    cout << n1 << " is Player 1 (x)" << endl;
    cout << n2 << " is Player 2 (0)" << endl;

    char play = 'y';
    do {
        while (!result()) {
            table();
            game();
        }

        table();

        if (token == 'x' && !draw) {
            cout << n2 << " Wins!!!" << endl;
        } else if (token == '0' && !draw) {
            cout << n1 << " Wins!!!" << endl;
        } else {
            cout << "It's a Draw!!!" << endl;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> play;

        if (play == 'y' || play == 'Y') {
            resetBoard();
        }

    } while (play == 'y' || play == 'Y');

    cout << "Thank you for playing Tic-Tac-Toe!" << endl;
    return 0;
}

void table() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---------\n";
    }
    cout << "\n";
}

void game() {
    int digit;
    cout << (token == 'x' ? n1 : n2) << ", please enter a number (1-9): ";
    cin >> digit;

    if (digit == 1) { row = 0; column = 0; }
    else if (digit == 2) { row = 0; column = 1; }
    else if (digit == 3) { row = 0; column = 2; }
    else if (digit == 4) { row = 1; column = 0; }
    else if (digit == 5) { row = 1; column = 1; }
    else if (digit == 6) { row = 1; column = 2; }
    else if (digit == 7) { row = 2; column = 0; }
    else if (digit == 8) { row = 2; column = 1; }
    else if (digit == 9) { row = 2; column = 2; }
    else {
        cout << "Invalid input. Please enter a number between 1 and 9.\n";
        game();
        return;
    }

    if (board[row][column] != 'x' && board[row][column] != '0') {
        board[row][column] = token;
        token = (token == 'x') ? '0' : 'x';
    } else {
        cout << "The position is already occupied! Try again.\n";
        game();
    }
}

bool result() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][0] == board[i][2]) || (board[0][i] == board[1][i] && board[0][i] == board[2][i])) {
            return true;
        }
    }
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2] == board[2][0])) {
        return true;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'x' && board[i][j] != '0') {
                return false;
            }
        }
    }

    draw = true;
    return false;
}

void resetBoard() {
    char count = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = count++;
        }
    }
    token = 'x';
    draw = false;
}

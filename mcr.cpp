#include <iostream>
using namespace std;

bool isWin(char game[3][3]){
    bool win = false;
    // Check rows and columns for a win
    for(int i = 0; i < 3; i++) {
        if ((game[i][0] == game[i][1] && game[i][1] == game[i][2]) ||
            (game[0][i] == game[1][i] && game[1][i] == game[2][i])) {
            if (game[i][i] == 'X' || game[i][i] == 'O') {
                win = true;
                break;
            }
        }
    }
    // Check diagonals for a win
    if ((game[0][0] == game[1][1] && game[1][1] == game[2][2]) ||
        (game[0][2] == game[1][1] && game[1][1] == game[2][0])) {
        if (game[1][1] == 'X' || game[1][1] == 'O') {
            win = true;
        }
    }
    return win;
}
	
void displayBoard(char game[3][3]) {
	cout << game[0][0] << " | " << game[0][1] << " | " << game[0][2] << endl;
	cout << "----------" << endl;
    cout << game[1][0] << " | " << game[1][1] << " | " << game[1][2] << endl;
	cout << "----------" << endl;
    cout << game[2][0] << " | " << game[2][1] << " | " << game[2][2] << endl;
	return;
}

int main() {
    int i, j;
    char game[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player1 = 'X';
    char player2 = 'O';
    bool turn = true; // false for player 1's turn, true for player 2's turn, Player 1 first
    cout << "X = Player 1" << endl << "O = Player 2" << endl;

	int n = 9;
    while(n--) {
        turn = !turn; // use the not-operator to change true to false or false to true

        if (turn == false)
            cout << "Player 1: ";
        else
            cout << "Player 2: ";

        cout << "Which cell to mark? i:[1..3], j:[1..3]: ";
		
        while (1){
			if (!(cin >> i >> j)) {
				cout << "Error: Please input an integer!" << endl;
				cin.clear();
				cin.ignore(40,'\n');
				continue;
			}
			if ((i > 0 && i < 4) && (j > 0 && j < 4)) {
				if (game[i-1][j-1] != ' ') {
					cout << "Error: This position has been occupied!" << endl;
					cin.clear();
				    cin.ignore(40,'\n');
					continue;
				}
				break;
			}
			else {
				cout << "Error: Please input cell position in range form 1 to 3" << endl;
				displayBoard(game);
			}
		}

        if (turn == false)
            game[i-1][j-1] = 'X';
        else
            game[i-1][j-1] = 'O';

        if (isWin(game)) {
			if (turn)
				cout << "Player 2 Win!" << endl;
			else
				cout << "Player 1 Win!" << endl;
			displayBoard(game);
            break; // Need to terminate the program
        }
        // Show the game to console
        displayBoard(game);
    }
	
	if (!n) {
        // All cells with i, 0 to 2 have been inputted above but no winner yet
        cout << "Tie!" << endl;
		displayBoard(game);
    }

    return 0;
}

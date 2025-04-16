#include <iostream>
#include <string>
using namespace std;

void Board(char seira[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3 ; j++){
                cout << " "<< seira[i][j] << " ";
        }cout << endl;
    }
}

bool CheckWinner(char seira [3][3]){
//Winner Check for Player [X]
    if ((seira[0][0] == 'X' && seira[0][1] == 'X' && seira[0][2] == 'X') ||
        (seira[1][0] == 'X' && seira[1][1] == 'X' && seira[1][2] == 'X') ||
        (seira[2][0] == 'X' && seira[2][1] == 'X' && seira[2][2] == 'X') ||
        (seira[0][0] == 'X' && seira[1][0] == 'X' && seira[2][0] == 'X') ||
        (seira[0][1] == 'X' && seira[1][1] == 'X' && seira[2][1] == 'X') ||
        (seira[0][2] == 'X' && seira[1][2] == 'X' && seira[2][2] == 'X') ||
        (seira[0][0] == 'X' && seira[1][1] == 'X' && seira[2][2] == 'X') ||
        (seira[0][2] == 'X' && seira[1][1] == 'X' && seira[2][0] == 'X')) {
        system("cls");
        cout << "Player X won" << endl;
        return true;
    }

//Winner Check for Player [O]
    if ((seira[0][0] == 'O' && seira[0][1] == 'O' && seira[0][2] == 'O') ||
        (seira[1][0] == 'O' && seira[1][1] == 'O' && seira[1][2] == 'O') ||
        (seira[2][0] == 'O' && seira[2][1] == 'O' && seira[2][2] == 'O') ||
        (seira[0][0] == 'O' && seira[1][0] == 'O' && seira[2][0] == 'O') ||
        (seira[0][1] == 'O' && seira[1][1] == 'O' && seira[2][1] == 'O') ||
        (seira[0][2] == 'O' && seira[1][2] == 'O' && seira[2][2] == 'O') ||
        (seira[0][0] == 'O' && seira[1][1] == 'O' && seira[2][2] == 'O') ||
        (seira[0][2] == 'O' && seira[1][1] == 'O' && seira[2][0] == 'O')) {
        system("cls");
        cout << "Player O won" << endl;
        return true;
    }
    return false;
}

bool CheckDraw(char seira[3][3]){
    for (int i = 0; i <3 ; i++) {
        for (int j = 0; j < 3; j++) {
            if (seira[i][j] != 'X' && seira[i][j] != 'O') {
                return false; 
            }
        }
    }
    return true;
}

int main() {
    //Variables
    char seira[3][3] = {{'1','2','3'}, {'4','5','6'},{'7','8','9'}};
    int position;
    char player = 'X';
    bool gameOver = false;


    while (gameOver != true){
    system("cls");
    cout << "Tic Tac Toe Game" << endl;
        Board(seira);
        
        cout << endl << "As player [" << player << "], choose where you want to place " << player << " (1-9): ";
        cin >> position;
        
        //Check validity
        if (position < 1 || position > 9) {
            cout << "Invalid position! Please choose a number between 1 and 9." << endl;
            continue;
        }
    
        //Translating Position to Rows & Columns
        int row = (position - 1 ) / 3;
        int col = (position - 1) % 3;

        //Check if there is space
        if (seira[row][col] == 'X' || seira[row][col] == 'O'){
            cout << "Position is already taken " << endl;
            continue;
        }

        // Placing Move
        seira[row][col] = player;

        //Switch Turns for players
        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
        
        if (CheckWinner(seira)) {
            Board(seira);
            gameOver = true;
        } else if (CheckDraw(seira)) {
            system("cls");
            Board(seira);
            cout << endl << "The game ended in a Draw" << endl;
            gameOver = true;
        }
    }
    return 0;
}
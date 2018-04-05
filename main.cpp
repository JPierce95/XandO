//Author: Joshua E. Pierce
#include <iostream>

using namespace std;

//GLOBAL CONSTANTS
const int ROWS = 3;
const int COLUMNS = 3;
const char BLANK = ' ';
const char X = 'X';
const char O = 'O';
const int QUIT = -1;

int main()
{
        //3x3 matrix of characters, initially with blank spaces in each position
        char board[ROWS][COLUMNS] = {{BLANK, BLANK, BLANK},
                {BLANK, BLANK, BLANK},
                {BLANK, BLANK, BLANK}};

        char turn = X; //Player X always goes first
        char win = ' ';
        int row;
        int column;
        bool playing = true; //Continue playing by default

        do
        {
                cout<<turn<<"'s turn.\n";
                cout<<"Which column and row (0-2, or -1 for both to quit)?\n";
                cin>>column;
                cin>>row;

                if(column == QUIT && row == QUIT)
                {
                        playing = false;
                }
                else if( column < 0 || row < 0 || column > 2 || row > 2 )
                {
                        cout<<"Values must be between 0 and 2.\n";
                }
                else{
                        if(turn == X){
                                board[row][column] = X;
                                turn = O;
                        }
                        else{
                                board[row][column] = O;
                                turn = X;
                        }
                }

                cout<<"\nBOARD\n-----\n";
                cout << board[0][0] << " " << board[0][1] << " " << board[0][2] << " \n";
                cout << board[1][0] << " " << board[1][1] << " " << board[1][2] << " \n";
                cout << board[2][0] << " " << board[2][1] << " " << board[2][2] << " \n";

                if((board[0][1] == board[0][0] && board[0][2] == board[0][0]) && (board[0][0] == 'X' || board[0][0] == 'O')){
                                win = board[0][0];
                                playing = false;
                }

                else if((board[1][0] == board[0][0] && board[2][0] == board[0][0]) && (board[0][0] == 'X' || board[0][0] == 'O')){
                                win = board[0][0];
                                playing = false;
                }

                else if((board[1][1] == board[0][0] && board[2][2] == board[0][0]) && (board[0][0] == 'X' || board[0][0] == 'O')){
                                win = board[0][0];
                                playing = false;
                }
                
                else if((board[1][1] == board[1][0] && board[1][2] == board[1][0]) && (board[1][0] == 'X' || board[1][0] == 'O')){
                                win = board[1][0];
                                playing = false;
                }

                else if((board[2][1] == board[2][0] && board[2][2] == board[2][0]) && (board[2][0] == 'X' || board[2][0] == 'O')){
                                win = board[2][0];
                                playing = false;
                }

                else if((board[1][1] == board[0][2] && board[2][0] == board[0][2]) && (board[0][2] == 'X' || board[0][2] == 'O')){
                                win = board[0][2];
                                playing = false;
                }
                else if((board[1][1] == board[0][1] && board[2][1] == board[0][1]) && (board[0][1] == 'X' || board[0][1] == 'O')){
                                win = board[0][1];
                                playing = false;
                }

                else if((board[1][2] == board[0][2] && board[2][2] == board[0][2]) && (board[0][2] == 'X' || board[0][2] == 'O')){
                                win = board[0][2];
                                playing = false;
                }

        }while( playing );
		if(win == 'X' || win == 'O'){
			cout << "Winner is " << win << endl;
		}
        cout<<"Goodbye!\n";

        return 0;
}

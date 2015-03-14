#include <iostream>
#include <iomanip>
using namespace std;

// g++ -std=c++11 intro.cpp -o name
// ./name

char** buildBoard(int x, int y);
void showboard(int x,int y,char **board);
void showWinner(string name);

const char open = '_';
const char p1   = '+';
const char p2   = 'x';
const int pad   = 6;

int main()
{
	// start with fixed
	int x=8,y=8;

	char **board = buildBoard(x, y);
	showboard(x,y,board);

	// begin
	bool winner  = false;
	bool player1 = true; // use a pointer or struct
	int column = 0;

	while (!winner) {		

		do {
			
			if (player1) {
				cout << "Player 1 ("<< p1<< ") - ";
			} else {
				cout << "Player 2 ("<< p2<< ") - ";
			}

			cout << "Add to which column: ";
			cin >> column;

		} while (column > x || column < 1);

		int xcord=0,ycord=0;

		for (int i=x; i>=0; --i) {
			if (board[column-1][i] == open) {

				xcord = column-1;
				ycord = i;

				if (player1) {
					board[xcord][ycord] = p1;
				} else {
					board[xcord][ycord] = p2;
				}

				break;
			}
		}

		
		char piece;

		if (player1) {
			piece = p1;
		} else {
			piece = p2;
		}


		// check winner, just check in relation to newest addition
		// (1) check both vertical directions
		// (2) check both horizontal directions
		// (3) check all four diagnol positions

		// 1 - same column [][x] +/- 3
		if (ycord+3 < y && ycord+2 < y && ycord+1 < y) {
			if (board[xcord][ycord+1] == piece && board[xcord][ycord+2] == piece && board[xcord][ycord+3] == piece) {
			
				if (player1) {
					showWinner("Player 1");
				} else {
					showWinner("Player 2");
				}
					
				winner = true;
			}
		}
		
		// 2 - same row, count left, count right, sum up
		// left
		int horiz = 1;
		if (xcord-1 >= 0 && board[xcord-1][ycord] == piece) {
			horiz++;
			if (xcord-2 >= 0 && board[xcord-2][ycord] == piece) {
				horiz++;
				if (xcord-3 >= 0 && board[xcord-3][ycord] == piece) {
					horiz++;
				}
			}
		}
		// check winner hear to
		if (xcord+1 < x && board[xcord+1][ycord] == piece) {
			horiz++;
			if (xcord+2 < x && board[xcord+2][ycord] == piece) {
				horiz++;
				if (xcord+3 < x && board[xcord+3][ycord] == piece) {
					horiz++;
				}
			}
		}	

		if (horiz > 3) {
			
			if (player1) {
				showWinner("Player 1");
			} else {
				showWinner("Player 2");
			}
				
			winner = true;
		}
		if (player1) {
			player1=false;
		} else {
			player1=true;
		}

		showboard(x,y,board);
	}
}

char** buildBoard(int x, int y)
{
	char **board = new char*[x];

	for (int i=0; i<x; i++) {
		board[i] = new char[y];

		for (int j=0; j<y; j++) {
			board[i][j] = open;
		}
	}

	return board;
}

void showboard(int x,int y,char **board)
{
	cout << "\n";
	cout << setw(pad) << " ";

	for (int i=1; i<=x; i++) {
		cout << setw(3) << i << " ";
	}

	cout << "\n";

	for (int i=0; i<x; i++) {

		cout << setw(pad) << " ";

		for (int j=0; j<y; j++) {
			cout << setw(3) << board[j][i] << " ";
		}		

		cout << "\n";
	}

	cout << "\n";

}

void showWinner(string name)
{
	cout << "\n\n";
	cout << "          " << "*************************";
		
	cout << "\n          *** " + name + " WINS!!!! ***\n";

	cout << "          "  << "*************************";
	cout << "\n\n";
}
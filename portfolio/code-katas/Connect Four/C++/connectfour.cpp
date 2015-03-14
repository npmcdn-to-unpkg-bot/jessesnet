#include <iostream>
#include <iomanip>
using namespace std;

// g++ -std=c++11 intro.cpp -o name
// ./name

char** buildBoard(int x, int y);
void showboard(int x,int y,char **board);
void showWinner(string name);
bool checkVertical(char** board, int y, int ycord, char piece, int xcord);

struct Player {
	int id;
	std::string name;
	char token;
};

struct GamePiece {
	char token;
	int xcord = -1;
	int ycord = -1;
};

struct Game {
	char** board;
	int width;
	int height;
	int player = 0;
	const int pad = 6;
	const char open = '_';

	Player players[2];
	GamePiece piece;

	Game(int x=8, int y=8)
	{
		// validate coords
		width  = x;
		height = y;

		players[0].id    = 1;
		players[0].name  = "Player 1";
		players[0].token = '+';
		players[1].id    = 2;
		players[1].name  = "Player 2";
		players[1].token = 'x';

		buildBoard();
	}

	void destruct()
	{

	}

	void buildBoard()
	{
		board = new char*[width];

		for (int i=0; i<width; i++) {
			board[i] = new char[height];

			for (int j=0; j<height; j++) {
				board[i][j] = open;
			}
		}
	}

	void displayBoard()
	{
		cout << "\n";
		cout << setw(pad) << " ";

		for (int i=1; i<=width; i++) {
			cout << setw(3) << i << " ";
		}

		cout << "\n";

		for (int i=0; i<width; i++) {

			cout << setw(pad) << " ";

			for (int j=0; j<height; j++) {
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

	bool connectFour()
	{
		// check vertical
		if (vertical()) {
			return true;
		}

		// check horizontal
		if (horizontal()) {
			return true;
		}

		return false;
	}

	bool vertical()
	{
		if (piece.ycord+3 < height && piece.ycord+2 < height && piece.ycord+1 < height) {
			if (board[piece.xcord][piece.ycord+1] == players[player].token && 
				board[piece.xcord][piece.ycord+2] == players[player].token && 
				board[piece.xcord][piece.ycord+3] == players[player].token
			) {
				return true;
			}
		}

		return false;
	}

	bool horizontal()
	{
		int horiz = 1;

		if (piece.xcord-1 >= 0 && board[piece.xcord-1][piece.ycord] == players[player].token) {
			horiz++;
			if (piece.xcord-2 >= 0 && board[piece.xcord-2][piece.ycord] == players[player].token) {
				horiz++;
				if (piece.xcord-3 >= 0 && board[piece.xcord-3][piece.ycord] == players[player].token) {
					horiz++;
				}
			}
		}
		
		if (horiz > 3) {	
			return true;
		}

		if (piece.xcord+1 < width && board[piece.xcord+1][piece.ycord] == players[player].token) {
			horiz++;
			if (piece.xcord+2 < width && board[piece.xcord+2][piece.ycord] == players[player].token) {
				horiz++;
				if (piece.xcord+3 < width && board[piece.xcord+3][piece.ycord] == players[player].token) {
					horiz++;
				}
			}
		}	

		if (horiz > 3) {	
			return true;
		}

		return false;
	}

	void nextPlayer()
	{
		player = (player == 0) ? 1 : 0;
	}
};

int main()
{
	Game game (8,8);
	game.displayBoard();

	// @todo Update to use Pointers, std::shared_ptr from #include <memory>

	// Player *player = game.players;
	// player->id % 2 == 0 ? player-- : player++;
	
	// begin
	bool winner   = false;
	int addcolumn = 0;

	while (!winner) {		

		int active = game.player;

		do {
			
			cout << game.players[active].name << " (" << game.players[active].token << ") - Add to which column: ";
			cin >> addcolumn;

		} while (addcolumn > game.width || addcolumn < 1);

		GamePiece piece;

		// "drop" piece to bottom of board
		for (int i=game.width; i>=0; --i) {
			if (game.board[addcolumn-1][i] == game.open) {
				piece.xcord = addcolumn-1;
				piece.ycord = i;
				game.board[piece.xcord][piece.ycord] = game.players[active].token;
				break;
			}
		}

		// make sure piece correctly registered
		if (piece.xcord < 0 || piece.ycord < 0) {
			cout << "Sorry somebody broke the board\n\n";
			exit(1);
		}

		// update game
		game.piece = piece;
		
		// checl for winner
		if (game.connectFour()) {
			winner = true;
			// update to correctly use pointers here
			game.showWinner(game.players[active].name);
		}

		// next players turn
		game.nextPlayer();
		game.displayBoard();
	}

	// good habits
	game.destruct();
}




#ifndef GAME_H
#define GAME_H

#include <iomanip>

/**
 * Connect Four Game 
 */
struct Game {

	char** board;
	int width;
	int height;
	int player = 0; // update to use pointers
	const int pad = 6;
	const char open = '_';

	Player players[2];
	GamePiece piece;

	Game()
	{
		players[0].token = '+';
		players[1].token = 'x';

		// players[0].id    = 1; // was used with pointers
		// players[1].id    = 2; // was used with pointers
	}

	void destruct()
	{
		// free memory
	}

	/**
	 * Builds the game board array
	 */
	void buildBoard(int x=8, int y=8)
	{
		if (!validSize(x, y)) {
			// @todo Update to use exceptions
			std::cout << "Invalid board dimensions \n\n";
			exit(1);
		}

		width  = x;
		height = y;

		// build the board vertically since tokens "drop"
		board = new char*[height];

		for (int i=0; i<height; i++) {
			board[i] = new char[width];
			for (int j=0; j<width; j++) {
				board[i][j] = open;
			}
		}
	}

	/**
	 * Show the board
	 */
	void displayBoard()
	{
		std::cout << "\n";
		std::cout << std::setw(pad) << " ";

		for (int i=1; i<=width; i++) {
			std::cout << std::setw(3) << i << " ";
		}

		std::cout << "\n";

		for (int i=0; i<height; i++) {

			std::cout << std::setw(pad) << " ";

			for (int j=0; j<width; j++) {
				std::cout << std::setw(3) << board[i][j] << " ";
			}		

			std::cout << "\n";
		}

		std::cout << "\n";
	}

	/**
	 * Add piece to column for current player
	 */
	void addPiece(int column)
	{
		bool pieceset = false;

		for (int i=height-1; i>=0; --i) {
			if (board[i][column -1] == open) {
				piece.xcord = column -1;
				piece.ycord = i;
				piece.token = players[player].token;
				pieceset = true;
				
				break;
			}
		}

		// make sure piece correctly registered
		if (!pieceset) {
			// @todo throw exception instead
			std::cout << "\nSorry somebody broke the board\n\n";
			exit(1);
		}

		board[piece.ycord][piece.xcord] = piece.token;
	}

	/**
	 * Check if last piece made a Connect Four
	 */
	bool connectFour()
	{
		if (vertical()) {
			return true;
		}

		if (horizontal()) {
			return true;
		}

		if (diagnol()) {
			return true;
		}

		return false;
	}

	/**
	 * Connect four vertical check
	 */
	bool vertical()
	{
		if (piece.ycord+3 < height && piece.ycord+2 < height && piece.ycord+1 < height) {
			if (board[piece.ycord+1][piece.xcord] == players[player].token && 
				board[piece.ycord+2][piece.xcord] == players[player].token && 
				board[piece.ycord+3][piece.xcord] == players[player].token
			) {
				return true;
			}
		}

		return false;
	}

	/**
	 * Connect four horizontal check
	 */
	bool horizontal()
	{
		int horiz = 1;

		if (piece.xcord-1 >= 0 && board[piece.ycord][piece.xcord-1] == players[player].token) {
			horiz++;
			if (piece.xcord-2 >= 0 && board[piece.ycord][piece.xcord-2] == players[player].token) {
				horiz++;
				if (piece.xcord-3 >= 0 && board[piece.ycord][piece.xcord-3] == players[player].token) {
					return true;
				}
			}
		}
		
		if (piece.xcord+1 < width && board[piece.ycord][piece.xcord+1] == players[player].token) {
			horiz++;
			if (piece.xcord+2 < width && board[piece.ycord][piece.xcord+2] == players[player].token) {
				horiz++;
				if (piece.xcord+3 < width && board[piece.ycord][piece.xcord+3] == players[player].token) {
					return true;
				}
			}
		}	

		if (horiz > 3) {	
			return true;
		}

		return false;
	}

	/**
	 * Connect four diagnol check
	 */
	bool diagnol()
	{
		int horiz = 1;

		// downward diagnol
		if (piece.xcord-1 >=0 && piece.ycord+1 < height && board[piece.ycord+1][piece.xcord-1] == players[player].token) {
			horiz++;
			if (piece.xcord-2 >=0 && piece.ycord+2 < height && board[piece.ycord+2][piece.xcord-2] == players[player].token) {
				horiz++;
				if (piece.xcord-3 >=0 && piece.ycord+3 < height && board[piece.ycord+3][piece.xcord-3] == players[player].token) {
					return true;
				}
			}
		}
		
		if (piece.xcord+1 >= 0 && piece.ycord-1 >= 0 && board[piece.ycord-1][piece.xcord+1] == players[player].token) {
			horiz++;
			if (piece.xcord+2 >=0 && piece.ycord-2 >= 0 && board[piece.ycord-2][piece.xcord+2] == players[player].token) {
				horiz++;
				if (piece.xcord+3 >=0 && piece.ycord-3 >= 0 && board[piece.ycord-3][piece.xcord+3] == players[player].token) {
					return true;
				}
			}
		}

		if (horiz > 3) {	
			return true;
		}

		return false;
	}

	/**
	 * Next players turn
	 * @todo Update to use pointers
	 */
	void nextPlayer()
	{
		player = (player == 0) ? 1 : 0;
	}

	/**
	 * Validate board size
	 */
	bool validSize(int x, int y)
	{
		if (x < 4 || x > 20) {
			return false;
		}

		if (y < 4 || y > 20) {
			return false;
		}

		return true;
	}

	/**
	 * Validate user name
	 */
	bool validName(std::string name)
	{
		// @todo do this statically ???
		Player player;
		return player.validName(name);
	}

	/**
	 * Show winner message
	 * @todo Update to use pointer vs param
	 */
	void showWinner(std::string name)
	{
		std::cout << "\n\n";
		std::cout << "          " << "*************************";
			
		std::cout << "\n          *** " + name + " WINS!!!! ***\n";

		std::cout << "          "  << "*************************";
		std::cout << "\n\n";
	}
};

#endif
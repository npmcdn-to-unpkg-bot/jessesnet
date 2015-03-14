#include <iostream>

#include "player.h"
#include "gamepiece.h"
#include "game.h"

using namespace std;

// g++ -std=c++11 connectfour.cpp -o name
// ./name

void buildBoard(Game& game);
void setPlayers(Game& game);

int main()
{
	Game game;
	
	buildBoard(game);
	setPlayers(game);
		
	// game on 
	game.displayBoard();

	while (true) {		

		int active = game.player; // use pointers
		int column = 0;
		bool valid = false;

		do {
			
			cout << game.players[active].name << " (" << game.players[active].token << ") - Add to which column: ";
			cin >> column ;

			// letters breaking shat

			if (column <= game.width && column > 0) {
				valid = true;
				// @todo add try/catch to prevent going over the top of the board
				game.addPiece(column);
			}

		} while (!valid);

		// check for winner
		if (game.connectFour()) {
			// update to correctly use pointers here
			game.showWinner(game.players[active].name);
			game.displayBoard();
			break;
		}

		// next players turn
		game.nextPlayer();
		game.displayBoard();
	}

	// good habits
	game.destruct();

	// @todo Update to use Pointers, std::shared_ptr from #include <memory>
	// Player *player = game.players;
	// player->id % 2 == 0 ? player-- : player++;
}

void buildBoard(Game& game)
{
	int x,y;
	bool validboard = false;

	do {

		cout << "\nEnter board width: ";
		cin >> x;
		cout << "Enter board height: ";
		cin >> y;

		if (game.validSize(x,y)) {
			validboard = true;
		} else {
			cout << "\nBoard width/height must be between 4 and 20 \n";
		}

	} while (!validboard);

	game.buildBoard(x, y);
}

void setPlayers(Game& game)
{
	string player1, player2;
	bool valid = false;

	cout << "\n";

	do {
		
		cout << "Enter Player 1 Name: ";
		cin >> player1;

		if (game.validName(player1)) {
			valid = true;
		}

	} while (!valid);

	game.players[0].name = player1;
	valid = false;

	do {
		
		cout << "Enter Player 2 Name: ";
		cin >> player2;

		if (game.validName(player2)) {
			valid = true;
		}

	} while (!valid);

	game.players[1].name = player2;	
}
#pragma once

#include <iostream>

class Game
{
public:
	Game();
	// Constructor->Game: Initializes each element of the dynamic array '_board' with a single whitespace character.

	~Game();
	// Destructor->Game: Free memory used by '_board'.

	void Play();
	// Play: A single game loop.

private:
	const int WIN_COMBINATIONS[8][3] = { {0,1,2}, {3,4,5}, {6,7,8},
										 {0,3,6}, {1,4,7}, {2,5,8},
										 {0,4,8}, {2,4,6} };
	// WIN_COMBINATIONS: Combinations of '_board' indices which define a winning set.

	char* _board;
	// _board: An array of characters which the playable area of the board is comprised of.

	//  + | + | + 
	// -----------
	//  + | + | + 
	// -----------
	//  + | + | + 

	int InputToIndex();
	// InputToIndex: Prompts the user for input and converts the input, 1-9, to a '_board' index, 0-8.

	bool IsValidMove(int);
	// IsValidMove(_board->index): Returns true only when the '_board->index' is available.

	int Turn();
	// Turn: Returns the number of turns taken.

	char Token();
	// Token: Returns the current token, 'O' or 'X'.

	void Move(int, char);
	// Move(_board->index, token): Places the 'token' in the 'board->index'.

	bool IsGameOver();
	// IsGameOver: Returns true if the game is over.

	void CongratulateWinner(char);
	// CongratulateWinner: Congratulates the winner.

	friend std::ostream& operator << (std::ostream&, Game&);
	// Operator-><<: Displays the '_board' in an aesthetic manner.
};

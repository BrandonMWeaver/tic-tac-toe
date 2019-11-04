#include "Game.h"

Game::Game()
{
	this->_board = new char[9] { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
}

Game::~Game()
{
	delete[] this->_board;
}

void Game::Play()
{
	char token = 'O';
	do
	{
		std::cout << *this << "Enter 1-9: ";
		int index = this->InputToIndex();
		if (this->IsValidMove(index))
		{
			token = this->Token();
			this->Move(index, token);
		}
	} while (!this->IsGameOver());
	std::cout << *this;
	this->CongratulateWinner(token);
}

int Game::InputToIndex()
{
	int input;
	std::cin >> input;
	return input - 1;
}

bool Game::IsValidMove(int index)
{
	if (index < 0 || index > 8)
		return false;
	if (this->_board[index] == 'O' || this->_board[index] == 'X')
		return false;
	return true;
}

int Game::Turn()
{
	int count = 0;
	for (int i = 0; i < 9; i++)
		if (this->_board[i] == 'O' || this->_board[i] == 'X')
			count++;
	return count;
}

char Game::Token()
{
	return this->Turn() % 2 != 0 ? 'O' : 'X';
}

void Game::Move(int index, char token)
{
	this->_board[index] = token;
}

bool Game::IsGameOver()
{
	if (this->Turn() == 9)
		return true;
	for (int i = 0; i < sizeof(this->WIN_COMBINATIONS) / sizeof(*this->WIN_COMBINATIONS); i++)
	{
		int index1 = this->WIN_COMBINATIONS[i][0];
		int index2 = this->WIN_COMBINATIONS[i][1];
		int index3 = this->WIN_COMBINATIONS[i][2];
		if (this->_board[index1] == 'O' && this->_board[index2] == 'O' && this->_board[index3] == 'O')
			return true;
		if (this->_board[index1] == 'X' && this->_board[index2] == 'X' && this->_board[index3] == 'X')
			return true;
	}
	return false;
}

void Game::CongratulateWinner(char token)
{
	std::cout << "Congratulations " << token << ". You win.";
}

std::ostream& operator << (std::ostream& out, Game& game)
{
	out << ' ' << game._board[0] << ' ' << '|' << ' ' << game._board[1] << ' ' << '|' << ' ' << game._board[2] << ' ' << '\n'
		<< "-----------\n"
		<< ' ' << game._board[3] << ' ' << '|' << ' ' << game._board[4] << ' ' << '|' << ' ' << game._board[5] << ' ' << '\n'
		<< "-----------\n"
		<< ' ' << game._board[6] << ' ' << '|' << ' ' << game._board[7] << ' ' << '|' << ' ' << game._board[8] << ' ' << '\n';
	return out;
}

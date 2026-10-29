#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// function to create a field
void printBoard(char board[3][3])
{
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2]  << endl;
	cout << "----------" << endl;
	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "----------" << endl;
	cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

// function for player's move
bool playerMove(char board[3][3], int number)
{
	int row = (number - 1) / 3;
	int col = (number - 1) % 3;


	if (board[row][col] != ' ')
	{
		cout << "The cell is occupied" << endl;
		return false;
	}

	board[row][col] = 'X';
		return true;
}

// looks for a winning move for the player
bool findWinningMove(char board[3][3], char player)
{
	// string checking
	for (int i = 0; i < 3; i++)
	{
		// combination 1
		if (board[i][0] == player && board[i][1] == player && board[i][2] == ' ')
		{
			board[i][2] = 'O';
			return true;
		}

		// combination 2
		if (board[i][0] == player && board[i][2] == player && board[i][1] == ' ')
		{
			board[i][1] = 'O';
			return true;
		}

		// combination 3
		if (board[i][1] == player && board[i][2] == player && board[i][0] == ' ')
		{
			board[i][0] = 'O';
			return true;
		}

	}

	// column checking
	for (int i = 0; i < 3; i++)
	{
		// combination 1
		if (board[0][i] == player && board[1][i] == player && board[2][i] == ' ')
		{
			board[2][i] = 'O';
			return true;
		}

		// combination 2
		if (board[0][i] == player && board[2][i] == player && board[1][i] == ' ')
		{
			board[1][i] = 'O';
			return true;
		}

		// combination 3
		if (board[1][i] == player && board[2][i] == player && board[0][i] == ' ')
		{
			board[0][i] = 'O';
			return true;
		}
	}

	// checking diagonals
	// 1 diagonal

	// combination 1
	if (board[0][0] == player && board[1][1] == player && board[2][2] == ' ')
	{
		board[2][2] = 'O';
		return true;
	}

	// combination 2
	if (board[0][0] == player && board[2][2] == player && board[1][1] == ' ')
	{
		board[1][1] = 'O'; 
		return true;
	}

	// combination 3
	if (board[1][1] == player && board[2][2] == player && board[0][0] == ' ')
	{
		board[0][0] = 'O';
		return true;
	}

	// 2 diagonal
	// combination 1
	if (board[0][2] == player && board[1][1] == player && board[2][0] == ' ')
	{
		board[2][0] = 'O';
		return true;
	}

	// combination 2
	if (board[0][2] == player && board[2][0] == player && board[1][1] == ' ')
	{
		board[1][1] = 'O';
		return true;
	}

	// combination 3
	if (board[1][1] == player && board[2][0] == player && board[0][2] == ' ')
	{
		board[0][2] = 'O';
		return true;
	}

	return false;

}

// function for computer running
void computerMove(char board[3][3])
{
	if (findWinningMove(board, 'O')) return;
	if (findWinningMove(board, 'X')) return;

	int row, col;
	do 
	{
		row = rand() % 3;      
		col = rand() % 3;      
	} while (board[row][col] != ' ');

	board[row][col] = 'O';
}

// function to check the winner
int checkWin(char board[3][3])
{
	// check all rows
	for (int i = 0; i < 3; i++) 
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			if (board[i][1] == 'X')
			{
				return 1;
			}
			else if (board[i][1] == 'O')
			{
				return 2;
			}
		}
	}

	// cheking col
	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			if (board[1][i] == 'X')
			{
				return 1;
			}
			else if (board[1][i] == 'O')
			{
				return 2;
			}
		}
	}

	// checking the first diagonal
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		if (board[1][1] == 'X')
		{
			return 1;
		}
		else if (board[1][1] == 'O')
		{
			return 2;
		}
	}

	// checking the second diagonal
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		if (board[1][1] == 'X')
		{
			return 1;
		}
		else if (board[1][1] == 'O')
		{
			return 2;
		}
	}


	// checking draws
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == ' ') 
				{
					return 0;
				}
			}
		}
		return 3;
}


int main()
{
	srand(time(0));
	char board[3][3];
	char exit;
	while (true)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				board[i][j] = ' ';
			}
		}

		while (true)
		{
			printBoard(board);


			int num;
			cout << "Enter cell number ";
			cin >> num;
			if (!playerMove(board, num)) continue;


			int res = checkWin(board);
			if (res == 1)
			{
				printBoard(board);
				cout << "You won" << endl;
				break;
			}
			if (res == 3)
			{
				printBoard(board);
				cout << "Draw" << endl;
				break;
			}

			computerMove(board);

			res = checkWin(board);
			if (res == 2)
			{
				printBoard(board);
				cout << "The computer won" << endl;
				break;
			}
			if (res == 3)
			{
				printBoard(board);
				cout << "Draw" << endl;
				break;
			}
		}
		cout << "Enter q if you want to exit or any other character to continue ";
		cin >> exit;
		if (exit == 'q')
		{
			break;
		}
	}

	return 0;
}

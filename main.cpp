#include <iostream>
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

int minmax(char board[3][3], bool isComputerTurn) {
	int res = checkWin(board);
	if (res == 1) {
		return -1;
	}
	if (res == 2) {
		return 1;
	}
	if (res == 3) {
		return 0;
	}
	if(isComputerTurn) {
		int best = -2;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == ' ') {
					board[i][j] = 'O';
					int score1 = minmax (board, false);
					board[i][j] = ' ';
					if (score1 > best) {
						best = score1;
					}
				}
			}
		}
		return best;
	}
	int best = 2;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ') {
				board[i][j] = 'X';
				int score2 = minmax (board, true);
				board[i][j] = ' ';
				if (score2 < best) {
					best = score2;
				}
			}
		}
	}
	return best;
}

// function for computer running
void computerMove(char board[3][3]) {
	int bestScore = -2;
	int bestRow = -1;
	int bestCol = -1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ') {
				board[i][j] = 'O';
				 int grade = minmax(board, false);
				board[i][j] = ' ';
				if (grade > bestScore) {
					bestScore = grade;
					bestRow = i;
					bestCol = j;
				}
			}
		}
	}
	board[bestRow][bestCol] = 'O';
}


int main()
{
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

           //check for signs
			int num;
			cout << "Enter cell number ";
			cin >> num;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Enter a number from 1 to 9" << endl;
				continue;
			}

			//range check
			if (num < 1 || num > 9)
			{
				cout << "Enter a number from 1 to 9" << endl;
				continue;
			}

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

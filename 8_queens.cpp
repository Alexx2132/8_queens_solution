#include "stdafx.h"
#include <iostream>
using namespace std;

void createBoard();
void showBoard();
void setQueen(int i, int j);
void removeQueen(int i, int j);
void solve(int i);

int board[8][8];
int found = 0;



int _tmain()
{
	setlocale(LC_ALL, "Russian");
	createBoard();
	solve(0);
	cout << "Ќайдено решений: " << found << endl;
	system("pause");
}

void createBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = 0;
		}
	}
}

void showBoard()
{
	cout << "–асстановка є " << found << endl;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j  < 8; j ++)
			{
				if (board[i][j] == -1)
				{
					cout <<"X ";
				}
				else
				{
					cout << "0 ";
				}
			}
			cout << endl;
		}
	cout << endl;
}



void setQueen(int i, int j)
{
	for (int x = 0; x < 8; x++)
	{
		board[x][j]++;
		board[i][x]++;
		if (i + j - x >= 0 && i + j - x < 8)
		{
			board[i + j - x][x]++;//нисход€ща€ диагональ - главна€ (слева направо)
		}
		if (i - j + x >= 0 && i - j + x < 8)
		{
			board[i - j + x][x]++;//восход€ща€ диагональ - побочна€ (слева направо)
		}
	}
	board[i][j] = -1;
}

void removeQueen(int i, int j)
{
	for (int x = 0; x < 8; x++)
	{
		board[x][j]--;
		board[i][x]--;
		if (i + j - x >= 0 && i + j - x < 8)
		{
			board[i + j - x][x]--;
		}
		if (i - j + x >= 0 && i - j + x < 8)
		{
			board[i - j + x][x]--;
		}
	}
	board[i][j] = 0;
}

void solve(int i)
{
	for (int j = 0; j < 8; j++)
	{
		if (board[i][j] == 0)
		{
			setQueen(i, j);
			if (i == 7)
			{
				found++;
				showBoard();
			}
			else
			{
				solve(i + 1);
			}
			removeQueen(i, j);
		}
	}
}

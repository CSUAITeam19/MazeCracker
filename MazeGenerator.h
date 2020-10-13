#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

// static const int N = 16;

enum sign
{
	WALL = 0,
	ROUTE = 1
};

void dig(vector<vector<int> >& maze, int x, int y)
{
	if (maze[x][y] == WALL)
	{
		if (maze[x + 1][y] + maze[x - 1][y] + maze[x][y + 1] + maze[x][y - 1] <= ROUTE)
		{
			maze[x][y] = ROUTE;

			int direction[4] = { 0,1,2,3 };
			for (int i = 4; i > 0; --i)
			{
				int r = rand() % i;
				swap(direction[r], direction[i - 1]);

				switch (direction[i - 1])
				{
				case 0:
					dig(maze, x - 1, y);
					break;
				case 1:
					dig(maze, x + 1, y);
					break;
				case 2:
					dig(maze, x, y - 1);
					break;
				case 3:
					dig(maze, x, y + 1);
					break;
				default:
					break;
				}
			}
		}
	}
}

void printMaze_1(vector<vector<int> >& maze)
{
	for (int i = 0; i < maze.size() - 2; ++i)
	{
		for (int j = 0; j < maze[i].size() - 2; ++j)
		{
			cout << maze[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}
void printMaze(vector<vector<int> >& maze)
{
	for (int i = 0; i < maze.size() - 2; ++i)
	{
		for (int j = 0; j < maze[i].size() - 2; ++j)
		{
			if (maze[i][j] == ROUTE)
			{
				cout << "  ";
			}
			else if (maze[i][j] == 3 || maze[i][j] == 4)cout << '*';
			else
			{
				cout << "¿Ú";
			}

		}
		cout << endl;
	}
	cout << endl;
}

// Generate a maze
vector<vector<int> > GenerateMaze(vector<vector<int> >& result, int row, int column)
{
	srand((unsigned)time(NULL));

	result.clear();
	result.resize(row);
	for (int i = 0; i < row; i++)
	{
		result[i].resize(column);
		for each (auto var in result[i])
		{
			var = WALL;
		}
	}

	// Set two V route
	for (int i = 0; i < row; i++)
	{
		result[i][row - 1] = ROUTE;
		result[i][0] = ROUTE;
	}
	// Set two H route
	for (int i = 0; i < column; i++)
	{
		result[0][i] = ROUTE;
		result[column - 1][i] = ROUTE;
	}
	dig(result, row - 4, row - 2);
	result[2][2] = 3;
	result[row - 3][column - 3] = 4;

	return result;
}

#endif // MAZEGENERATOR_H

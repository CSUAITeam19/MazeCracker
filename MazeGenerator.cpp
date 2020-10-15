#include "MazeGenerator.h"

namespace MazeCracker
{
	namespace Maze
	{
		void dig(vector<vector<int>>& maze, int x, int y)
		{
			if (maze[x][y] == Wall)
			{
				if (maze[x + 1][y] + maze[x - 1][y] + maze[x][y + 1] + maze[x][y - 1] <= Route)
				{
					maze[x][y] = Route;

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

		// Generate a maze
		vector<vector<int>> generateMaze(vector<vector<int>>& result, int row, int column)
		{
			srand((unsigned)time(NULL));

			result.clear();
			result.resize(row);
			for (int i = 0; i < row; i++)
			{
				result[i].resize(column);
				for each (auto var in result[i])
				{
					var = Wall;
				}
			}

			// Set two V route
			for (int i = 0; i < row; i++)
			{
				result[i][row - 1] = Route;
				result[i][0] = Route;
			}
			// Set two H route
			for (int i = 0; i < column; i++)
			{
				result[0][i] = Route;
				result[column - 1][i] = Route;
			}
			dig(result, row - 4, row - 2);
			result[2][2] = 3;
			result[row - 3][column - 3] = 4;

			return result;
		}
	}
}



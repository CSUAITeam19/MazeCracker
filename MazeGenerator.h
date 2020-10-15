#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

// static const int N = 16;

namespace MazeCracker
{
	namespace Maze
	{
		enum sign
		{
			Wall = 0,
			Route = 1
		};

		void dig(vector<vector<int> >& maze, int x, int y);

		/*void printMaze_1(vector<vector<int> >& maze)
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
					if (maze[i][j] == Route)
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
		}*/

		// Generate a maze
		vector<vector<int> > generateMaze(vector<vector<int> >& result, int row, int column);
	}
}


#endif // MAZEGENERATOR_H

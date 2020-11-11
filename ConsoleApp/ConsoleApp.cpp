#include <iostream>
#include "Maze.h"
#include "MazeUtility.h"

int main()
{
	using namespace std;
	using namespace MazeCracker::Maze;

	BasicMaze _maze = BasicMaze();
	IMaze& maze = _maze;
	int row, col;
	cout << "please input row and col:\n";
	cin >> row >> col;
	cout << "input random seed:" << std::endl;
	string s;
	cin >> s;
	srand(hash<string>{}(s));
	generateMaze(maze, row, col, false);
	/*int count = 0;
	do
	{
		generateMaze(maze, row, col, true);
		count++;
	} while (maze.isValid());
	cout << "[" << count << "] is invalid:"<<endl;*/
	printToStream(cout, maze);
}
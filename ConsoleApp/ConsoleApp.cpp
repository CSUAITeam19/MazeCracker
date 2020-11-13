#include <iostream>
#include "Maze.h"
#include "MazeUtility.h"
#include "GenericMaze.h"
#include "MazeIO.h"

int main()
{
	using namespace std;
	using namespace MazeCracker::Maze;
	using namespace MazeCracker::IO;
	
	GenericMaze<BasicCell> _maze{};
	IMaze& maze = _maze;
	//int row, col;
	//cout << "please input row and col:\n";
	//cin >> row >> col;
	//cout << "input random seed:" << std::endl;
	//string s;
	//cin >> s;
	//srand(hash<string>{}(s));
	//generateMaze(maze, row, col, false);
	//
	//printToStream(cout, maze);
	//saveToFile(maze, "./out.txt");
	readFromFile(maze, "./maze.txt");
	printToStream(cout, maze);
}
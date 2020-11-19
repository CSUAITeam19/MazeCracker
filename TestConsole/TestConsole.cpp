#include <iostream>
#include <fstream>
#include "Maze.h"
#include "MazeIO.h"
#include "UCS.h"

using namespace std;
using namespace MazeCracker::Maze;
using namespace MazeCracker::IO;

int main()
{
	BasicMaze maze;
	readFromFile(maze, "./maze.txt");
	auto out = ofstream("./result.txt");
	UCS ucs = UCS(maze, out);
	ucs.run({ 1,1 });
}
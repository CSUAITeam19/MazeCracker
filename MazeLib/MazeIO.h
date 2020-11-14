#ifndef MAZE_IO_H
#define MAZE_IO_H
#include "Maze.h"
#include <string>

namespace MazeCracker
{
	namespace IO
	{
		void readFromFile(Maze::IMaze& maze, const std::string& path);

		void saveToFile(const Maze::IMaze& maze, const std::string& path, bool nosize = false);
	}
}


#endif

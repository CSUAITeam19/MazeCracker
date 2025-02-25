#include "MazeIO.h"
#include <iostream>
#include <fstream>

namespace MazeCracker
{
	namespace IO
	{
		inline std::istream& operator>>(std::ifstream& istream, Maze::ICell& cell)
		{
			int temp;
			istream >> temp;
			cell = static_cast<Maze::MazeState>(temp);
			return istream;
		}

		inline std::ostream& operator<<(std::ostream& ostream, const Maze::ICell& cell)
		{
			ostream << static_cast<int>(cell.getState());
			return ostream;
		}
		
		void readFromFile(Maze::IMaze& maze, const std::string& path)
		{
			auto file = std::ifstream(path);
			if (!file) throw std::exception(("File \"" + path + "\" not found!").c_str());
			// assumes that the format is right
			int row, col;
			file >> row >> col;
			maze.resize(row, col);
			maze.traverse([&file](Maze::ICell& cell, bool isLineEnd)
			{
				file >> cell;
			});
			file.close();
		}

		void saveToOStream(const Maze::IMaze& maze, std::ostream& ostr, bool nosize)
		{
			if (!nosize) ostr << maze.getHeight() << ' ' << maze.getWidth() << std::endl;
			maze.traverse([&ostr](const Maze::ICell& cell, bool isLineEnd)
			{
				ostr << cell << ' ';
				if (isLineEnd)ostr << std::endl;
			});
		}

		void saveToFile(const Maze::IMaze& maze, const std::string& path, bool nosize)
		{
			auto file = std::ofstream(path, std::ios::out);
			saveToOStream(maze, file, nosize);
			file.close();
		}

	}
}


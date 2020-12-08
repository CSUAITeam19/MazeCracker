#include "pch.h"
#include <sstream>
#include <msclr\marshal_cppstd.h>
#include "MazeCrackerDotnet.h"
#include "MazeIO.h"

using namespace MazeCracker::Maze;
using namespace MazeCracker::IO;


namespace MazeCrackerDotnet
{
	Maze::Maze(int row, int col) : mazeImpl(*new BasicMaze(row, col))
	{
	}

	Maze::Maze(String^ path):mazeImpl(*new BasicMaze)
	{
		readFromFile(mazeImpl, msclr::interop::marshal_as<std::string>(path));
	}

	String^ Maze::ToString()
	{
		std::ostringstream strStream;
		printToStream(strStream, mazeImpl);
		return msclr::interop::marshal_as<String^>(strStream.str());
	}

	String^ Maze::ToDataString(bool nosize)
	{
		std::ostringstream strStream;
		saveToOStream(mazeImpl, strStream, nosize);
		return msclr::interop::marshal_as<String^>(strStream.str());
	}

	void Maze::RandomGenerate()
	{
		generateMaze(mazeImpl, mazeImpl.getHeight(), mazeImpl.getWidth(), true);
	}

	Maze::~Maze()
	{
		delete& mazeImpl;
	}

	Maze::!Maze()
	{
		this->~Maze();
	}
}

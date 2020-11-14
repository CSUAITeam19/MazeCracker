#include <iostream>
#include "Maze.h"
#include "MazeUtility.h"
#include "GenericMaze.h"
#include "MazeIO.h"
#include <sstream>

class InputParser
{
public:
	InputParser(const int& argc, const char* argv[])
	{
		for (int i = 1; i < argc; ++i)
			this->tokens.push_back(std::string(argv[i]));
	}
	/// @author iain
	const std::string& getCmdOption(const std::string& option) const
	{
		std::vector<std::string>::const_iterator itr;
		itr = std::find(this->tokens.begin(), this->tokens.end(), option);
		if (itr != this->tokens.end() && ++itr != this->tokens.end())
		{
			return *itr;
		}
		static const std::string empty;
		return empty;
	}
	/// @author iain
	bool cmdOptionExists(const std::string& option) const
	{
		return std::find(this->tokens.begin(), this->tokens.end(), option)
			!= this->tokens.end();
	}
private:
	std::vector <std::string> tokens;
};

const std::string help = "Usage: ConsoleApp.exe <width> <height> [-o path] [-scr] [-nosize]\n"
"	width:		width of the maze\n"
"	height:		height of the maze\n"
"	[-o path]:	optional, path to output, default is \"./maze.txt\"\n"
"	[-scr]:		optional, allow print to screen in highly readable character painting, default false\n"
"	[-nosize]:	optional, won't print size info. default is false\n";

int main(const int argc, const char* args[])
{
	using namespace std;
	using namespace MazeCracker::Maze;
	using namespace MazeCracker::IO;

	int usedArgc = 1;
	// cmd parsing
	auto parser = InputParser(argc, args);
	if (argc < 3)
	{
		cout << help;
		return 1;
	}
	int row = std::atoi(args[1]);
	int col = std::atoi(args[2]);
	usedArgc += 2;
	string path;

	if ((path = parser.getCmdOption("-o")).empty())
	{
		path = "./maze.txt";
	}
	else
	{
		usedArgc += 2;
	}

	bool printToScreen = parser.cmdOptionExists("-scr");
	if (printToScreen) usedArgc++;

	bool nosize = parser.cmdOptionExists("-nosize");
	if (nosize) usedArgc++;
	if (usedArgc < argc)
	{
		cout << help;
		return 1;
	}

	// run works
	GenericMaze<BasicCell> _maze{};
	IMaze& maze = _maze;
	generateMaze(maze, row, col);
	saveToFile(maze, path, nosize);
	cout << "Output: " << path << endl;
	if (printToScreen) printToStream(cout, maze);
	
	/*BasicMaze maze = BasicMaze{};
	readFromFile(maze, "maze.txt");
	printToStream(cout, maze);
	DFSSearcher searcher{ maze };
	searcher.run();
	searcher.path().traverse([](const MazeCracker::Vector2D& pos)
	{
		cout << pos.x << ' ' << pos.y << '\n';
	});*/
	
}
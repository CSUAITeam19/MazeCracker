#include <iostream>
#include <fstream>
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
	template<typename T>
	T getCmdOption(const std::string& option, T defaultValue, bool* haveArg) const
	{
		std::string temp = getCmdOption(option);
		if (temp.empty())
		{
			if(haveArg) *haveArg = false;
			return defaultValue;
		}
		else
		{
			T result{};
			auto ss = std::istringstream(temp);
			ss >> result;
			if (haveArg) *haveArg = true;
			return result;
		}
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

const std::string help = "Usage: ConsoleApp.exe <-c|-s [-al algorithm]> [-w width] [-h height] [-i inPath] [-o ouPath] [-scr] [-nosize]\n"
"	-c:				create maze\n"
"	-s:				search maze\n"
"		[-al algorithm]:	search algorithm, default=\"DFS\"\n"
"	[-w width]:		width of the maze, default=8\n"
"	[-h height]:	height of the maze, default=8\n"
"	[-i inPath]:	optional, path to maze data, default is \"./maze.txt\"\n"
"	[-o ouPath]:	optional, path to output search result, default is \"out.txt\"\n"
"	[-scr]:			optional, allow print to screen in highly readable character painting, default false\n"
"	[-nosize]:		optional, won't print size info. default is false\n";

int main(const int argc, const char* args[])
{
	using namespace std;
	using namespace MazeCracker::Maze;
	using namespace MazeCracker::IO;

	int usedArgc = 1;
	// cmd parsing
	auto parser = InputParser(argc, args);
	bool createMode;
	if (parser.cmdOptionExists("-c"))
	{
		usedArgc++;
		createMode = true;
	}else if(parser.cmdOptionExists("-s"))
	{
		usedArgc++;
		createMode = false;
	}else
	{
		cout << "missing mode switch! try creating maze.\n" << help;
		createMode = true;
	}

	string mazePath;
	if ((mazePath = parser.getCmdOption("-i")).empty())
	{
		mazePath = "./maze.txt";
	}
	else
	{
		usedArgc += 2;
	}
	string searchDataPath;
	if ((searchDataPath = parser.getCmdOption("-o")).empty())
	{
		searchDataPath = "./out.txt";
	}
	else
	{
		usedArgc += 2;
	}
	
	bool hasArg;
	int row;
	int col;
	row = parser.getCmdOption("-h", 8, &hasArg);
	if (hasArg) usedArgc += 2;
	col = parser.getCmdOption("-w", 8, &hasArg);
	if (hasArg) usedArgc += 2;
	
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
	if(createMode)
	{
		generateMaze(maze, row, col, true);
		try
		{
			saveToFile(maze, mazePath, nosize);
		}
		catch (exception e)
		{
			cout << e.what();
		}
		cout << "Output: " << mazePath << endl;
		if (printToScreen) printToStream(cout, maze);
	}else
	{
		try
		{	
			readFromFile(maze, mazePath);
		}
		catch (exception e)
		{
			cout << e.what()<<endl;
			return -1;
		}
		// TODO: decide which algorithm to use
		DFSSearcher dfs = DFSSearcher(maze);
		dfs.run();
		auto file = ofstream(searchDataPath, ios::ate);
		
		/*file << dfs.path();
		if (printToScreen)
		{
			printToStream(cout, maze);
			cout << dfs.path();
		}*/
		file.close();
		cout << "Output: " << searchDataPath << endl;
	}
	
	
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
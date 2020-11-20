#include "MazeGenerator.h"
#include <unordered_map>
#include "Maze.h"

using std::vector;
using std::unordered_map;

namespace MazeCracker
{
	namespace Maze
	{
		// 四个方向上最多一格标记为Route
		inline bool oneRouteIn4Dir(const IMaze& maze, Vector2D pos)
		{
			int counter = 0;
			for (auto dir : Vector2D::fourDirections)
			{
				auto tempPos = pos + dir;
				if (!maze.validPos(tempPos))
				{
					counter++;
				}else
				{
					if (maze.getCell(tempPos) == MazeState::Route) counter++;
				}
			}
			return counter <= 1;
		}
		
		void dig(IMaze& maze, const int& x, const  int& y)
		{
			if (maze[x][y] == MazeState::Wall)
			{
				if (oneRouteIn4Dir(maze, { x,y }))
				{
					maze[x][y] = MazeState::Route;

					int digList[4] = { 0,1,2,3 };
					// classic implement of random list: this will make the dig operation order random
					for (int i = 4; i > 0; --i)
					{
						int r = rand() % i;
						std::swap(digList[r], digList[i - 1]);
						auto tempPos = Vector2D{ x,y } + Vector2D::fourDirections[digList[i - 1]];
						if (maze.validPos(tempPos)) dig(maze, tempPos.x, tempPos.y);
					}
				}

			}
		}

		IMaze& generateMaze(IMaze& maze, const int& row, const int& col, bool initRand)
		{
			if (initRand) srand(static_cast<unsigned>(time(NULL)));

			// init 
			maze.clear();
			maze.resize(row, col);
			maze[1][1] = MazeState::Entry;
			maze[row - 2][col - 2] = MazeState::Exit;
			dig(maze, 1, 2);
			

			return maze;
		}

		void printToStream(std::ostream& str, const IMaze& maze)
		{
			maze.traverse([&str](const ICell& cell, bool lineEnd)
			{
				str << cellToString(cell);
				if (lineEnd) str << '\n';
			});
		}

		std::string cellToString(const MazeState& cellState)
		{
			unordered_map<MazeState, std::string> map = unordered_map<MazeState, std::string>
			{
				{MazeState::Route, "  "},
				{MazeState::Wall, "█"},
				{MazeState::Entry, "--"},
				{MazeState::Exit, "++"}
			};
			//if(cellState==MazeState::Exit)
			//{
			//	
			//}
			//if (map[cellState] == "++")
			//{
			//	// wtf?
			//}
			return map[cellState];
		}
	}
}

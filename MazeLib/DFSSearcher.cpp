#include "DFSSearcher.h"
#include "ICell.h"
#include <iostream>
#include <vector>

using std::vector;
namespace MazeCracker
{
	namespace Maze
	{
		/*inline std::string repeat(int count, std::string str = "  ")
		{
			std::string temp;
			for(;count>0;count--)
			{
				temp += str;
			}
			return temp;
		}*/
		
		bool DFSSearcher::search(Vector2D from, Vector2D pos, vector<vector<bool>>& visitMap)
		{
			if (mazePath.tryPush(pos))
			{
				visitMap[pos.x][pos.y] = true;
				if (maze[pos] == MazeState::Exit)
				{
					return true;
				}

				for (auto dir : Vector2D::fourDirections)
				{
					auto tempPos = pos + dir;
					if (!visitMap[tempPos.x][tempPos.y])
					{
						if (search(pos, tempPos, visitMap))
						{
							return true;
						}
					}
				}
				mazePath.pop();
			}
			return false;
		}

		DFSSearcher::DFSSearcher(IMaze& maze) : maze(maze), mazePath(maze)
		{
		}

		void DFSSearcher::run(Vector2D entrancePos)
		{
			auto visitMap = std::vector<std::vector<bool>>(maze.getWidth(), std::vector<bool>(maze.getHeight(), false));
			search(entrancePos, entrancePos, visitMap);
		}

		bool DFSSearcher::finished()
		{
			return maze.getCell(mazePath.peek()) == MazeState::Exit;
		}

		int DFSSearcher::totalCost()
		{
			return mazePath.totalCost();
		}

		int DFSSearcher::totalStep()
		{
			return mazePath.step();
		}

		const MazePath& DFSSearcher::path()
		{
			return mazePath;
		}

		std::string DFSSearcher::searcherName() const
		{
			auto static name = std::string("DFS");
			return name;
		}
	}
}
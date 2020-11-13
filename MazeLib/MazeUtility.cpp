#include "MazeUtility.h"
#include "MazeGenerator.h"

namespace MazeCracker
{
	namespace Maze
	{
		bool dfsHasPath(const IMaze& maze, Vector2D pos, Vector2D fromPos)
		{
			if (maze.getCell(pos) == MazeState::Exit) return true;
			bool tempResult = false;
			for (auto dir : Vector2D::fourDirections)
			{
				// 存在可行方向即为true
				auto tempPos = pos + dir;
				if (tempPos != fromPos)
				{
					if (maze.getCell(tempPos) == MazeState::Route)
					{
						tempResult = dfsHasPath(maze, tempPos, pos);
					}
					if (maze.getCell(tempPos) == MazeState::Exit) return true;
				}
				if (tempResult) return true;
			}
			// 四个方向都不行就gg
			return false;
		}
		bool isValid(const IMaze& maze)
		{
			// assume entry on 1,1, exit on row-1,col-1
			Vector2D begin = { 1,1 };
			return dfsHasPath(maze, begin, begin);
		}
	}
}

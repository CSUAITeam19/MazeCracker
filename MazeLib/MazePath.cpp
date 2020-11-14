#include "MazePath.h"

namespace MazeCracker
{
	namespace Maze
	{
		MazePath::MazePath(const IMaze& maze) :path(), maze(maze), cost(0)
		{
		}

		void MazePath::push(const Vector2D& pos)
		{
			path.push_back(pos);
			if (path.size() > 1)
			{
				int tempCost;
				maze.walkable(path[path.size() - 2], pos, &tempCost);
				cost += tempCost;
			}
		}

		bool MazePath::tryPush(const Vector2D& pos)
		{
			if (!path.empty())
			{
				int tempCost;
				if (maze.walkable(path[path.size() - 1], pos, &tempCost))
				{
					path.push_back(pos);
					cost += tempCost;
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				path.push_back(pos);
			}
			return true;
		}

		Vector2D MazePath::pop()
		{
			const Vector2D peek = *(path.end() - 1);
			path.erase(path.end() - 1);
			int tempCost;
			maze.walkable(path[path.size() - 1], peek, &tempCost);
			cost -= tempCost;
			return peek;
		}

		Vector2D MazePath::peek() const
		{
			return path[path.size() - 1];
		}

		long MazePath::totalCost() const
		{
			return cost;
		}

		int MazePath::step() const
		{
			return path.size() - 1;
		}

		void MazePath::traverse(const std::function<void(const Vector2D&)>& func) const
		{
			for (auto pos : path)
			{
				func(pos);
			}
		}

		void MazePath::traverse(const std::function<void(Vector2D&)>& func)
		{
			for (auto& pos : path)
			{
				func(pos);
			}
		}
	}
}
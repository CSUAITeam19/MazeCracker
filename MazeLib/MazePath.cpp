#include "MazePath.h"
#include <iostream>

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

		void MazePath::toStream(std::ostream& ostr) const
		{
			traverse([&ostr](const Vector2D& pos)
			{
				ostr << pos.x << ' ' << pos.y << '\n';
			});
		}

		std::ostream& operator<<(std::ostream& ostr, const MazePath& path)
		{
			path.toStream(ostr);
			return ostr;
		}

		std::ostream& operator<<(std::ostream& ostr, const Operation& oper)
		{
			ostr << oper.pos.x << ' ' << oper.pos.y << ' ' << (oper.isPush ? '1' : '0') << ' ' << oper.cost << ' ';
			return ostr;
		}

		MemorablePath::MemorablePath(const IMaze& maze) :MazePath(maze)
		{
			
		}

		void MemorablePath::push(const Vector2D& pos)
		{
			MazePath::push(pos);
			historyOper.emplace_back(pos, true, cost);
		}

		bool MemorablePath::tryPush(const Vector2D& pos)
		{
			bool temp = MazePath::tryPush(pos);
			if (temp) historyOper.emplace_back(pos, true, cost);
			return temp;
		}

		Vector2D MemorablePath::pop()
		{
			auto temp = MazePath::pop();
			historyOper.emplace_back(temp, false, cost);
			return temp;
		}

		void MemorablePath::toStream(std::ostream& ostr) const
		{
			for (Operation oper : historyOper)
			{
				ostr << oper << std::endl;
			}
			ostr << std::endl;
		}
	}
}
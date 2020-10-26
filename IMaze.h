#ifndef IMAZE_H
#define IMAZE_H
#include "Vector2D.h"
//#include "ICell.h" // 猜猜为什么要注释这一行? 我也不知道.

namespace MazeCracker
{
	namespace Maze
	{
		class ICell;
		// 迷宫单元的状态
		enum class MazeState
		{
			// 每一个位代表一个状态, 在同时比较多种状态的情况下可能有用
			Wall = 0x1,
			Route = 0x2,
			Entry = 0x4,
			Exit = 0x8,
			// Visited = 0x10
		};
		class IMaze
		{
		public:
			// 获取宽度
			virtual int getWidth() const = 0;
			// 获取高度
			virtual int getHeight() const = 0;
			// 清空迷宫为全是墙的状态
			virtual void clear() = 0;
			// 获取一个单元
			virtual ICell* getCell(const int& row, const int& col) const = 0;
			// 获取一个单元
			virtual ICell* getCell(const Vector2D& pos) const = 0;
			// 设置一个单元
			virtual void setCell(const int& row, const int& col, const MazeState& newState) = 0;
			// 设置一个单元
			virtual void setCell(const Vector2D& pos, const MazeState& newState) = 0;
			// 是有效迷宫
			virtual bool isValid() const = 0;
		};
	}
}

#endif // !IMAZE_H
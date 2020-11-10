#ifndef IMAZE_H
#define IMAZE_H
#include <string>

#include "Vector2D.h"
#include "MazeState.h"
//#include "ICell.h" // 猜猜为什么要注释这一行? 我也不知道.

namespace MazeCracker
{
	namespace Maze
	{
		class ICell;
		class RowVisitor;
		
		class IMaze
		{
		public:
			virtual ~IMaze() = default;
			// 获取宽度
			virtual int getWidth() const = 0;
			// 获取高度
			virtual int getHeight() const = 0;
			// 清空迷宫为全是墙的状态
			virtual void clear() = 0;
			// 获取一个单元
			virtual const ICell& getCell(const int& row, const int& col) const = 0;
			virtual ICell& getCell(const int& row, const int& col) = 0;
			// 获取一个单元
			virtual const ICell& getCell(const Vector2D& pos) const = 0;
			// 获取一个单元
			virtual ICell& getCell(const Vector2D& pos) = 0;
			// 设置一个单元
			virtual void setCell(const int& row, const int& col, const MazeState& newState) = 0;
			// 设置一个单元
			virtual void setCell(const Vector2D& pos, const MazeState& newState) = 0;
			// 获取迷宫行访问器
			virtual RowVisitor operator[](int row) = 0;
			// 获取迷宫行访问器
			virtual RowVisitor operator[](int row) const = 0;
			// 是有效迷宫
			virtual bool isValid() const = 0;
		};
	}
}

#endif // !IMAZE_H
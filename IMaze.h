#ifndef IMAZE_H
#define IMAZE_H
#include <functional>

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
			// 重置迷宫
			virtual void resize(const int& row, const int& col) = 0;
			// 遍历迷宫, 传入函数的第二个参数为true, 则当前访问位置为迷宫行末
			virtual void traverse(std::function<void(ICell&, bool)> func) = 0;
			// 遍历迷宫, 传入函数的第二个参数为true, 则当前访问位置为迷宫行末
			virtual void traverse(std::function<void(const ICell&, bool)> func) const = 0;
			// 有效坐标
			virtual bool validPos(const Vector2D& pos) const = 0;
			// 有效坐标
			virtual bool validPos(const int& row, const int& col) = 0;
			// 获取一个单元
			virtual const ICell& getCell(const int& row, const int& col) const = 0;
			// 获取一个单元
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
#ifndef BASICROW_H
#define BASICROW_H

#include "IMaze.h"
//#include "ICell.h"

namespace MazeCracker
{
	namespace Maze
	{
		// 基本的迷宫行(似乎不需要再扩展了?)
		// class ICell;
		// class IMaze;
		class RowVisitor
		{
			IMaze* implementer;
			int row;
		public:
			// 直接传入一个迷宫来实现
			RowVisitor(IMaze* implementer, int row) noexcept;
			ICell const* operator[](const size_t& index) const;
			ICell* operator[](const size_t& index);
		};
	}
}

#endif



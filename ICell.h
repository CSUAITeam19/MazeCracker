#ifndef ICELL_H
#define ICELL_H
#include "IMaze.h"

namespace MazeCracker
{
	namespace Maze
	{
		class IMaze;
		// 迷宫单元
		class ICell
		{
		public:
			virtual ~ICell() = default;
			// 获取单元的状态
			virtual MazeState getState() const = 0;
			// 设置单元的状态
			virtual void setState(const MazeState& newState) = 0;
			// 隐式转换为MazeState
			virtual operator MazeState() const = 0;
			virtual ICell& operator=(const MazeState& state) = 0;
			virtual IMaze* getContainer() const = 0;
		};
	}
}

#endif // !ICELL_H


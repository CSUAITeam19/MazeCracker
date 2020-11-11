#ifndef IASYNC_MAZE_SEARCHER_H
#define IASYNC_MAZE_SEARCHER_H
#include "IMazeSearcher.h"

namespace MazeCracker
{
	namespace Maze
	{
		// 异步的搜索器, 允许主动控制算法流程
		// TODO[Optional]: 异步的搜索器可选的特性, 不一定要实现
		class IAsyncMazeSearcher :virtual public IMazeSearcher
		{
		public:
			void run() override;
			// 开始运算
			virtual void begin() = 0;
			// 执行下一步搜索
			virtual void next() = 0;
		};

		inline void IAsyncMazeSearcher::run()
		{
			// do everything in one for loop
			for (begin(); !finished(); next());
		}
	}
}
#endif

#ifndef IMAZESEARCHER_H
#define IMAZESEARCHER_H
#include "IMaze.h"

namespace MazeCracker
{
	namespace Maze
	{
		// 迷宫搜索器接口, 保留部分搜索结果
		class IMazeSearcher
		{
		public:
			// 初始化搜索算法
			virtual void init(IMaze& maze) = 0;
			// 运行算法
			virtual void run() = 0;
			// 是否完成
			virtual bool finished() = 0;
			// 获取结果路径的总代价
			virtual int totalCost() = 0;
			virtual int totalStep() = 0;
			// 搜索器的名称
			virtual std::string searcherName() = 0;
		};
	}
}
#endif
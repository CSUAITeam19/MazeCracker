#ifndef IMAZESEARCHER_H
#define IMAZESEARCHER_H
#include "IMaze.h"
#include "MazePath.h"

namespace MazeCracker
{
	namespace Maze
	{
		// 迷宫搜索器接口, 保留部分搜索结果
		class IMazeSearcher
		{
		public:
			// 运行算法
			virtual void run(Vector2D entrancePos = Vector2D(1,1)) = 0;
			// 是否完成
			virtual bool finished() = 0;
			//// 获取结果路径的总代价
			//virtual int totalCost() = 0;
			//// 结果路径的步数
			//virtual int totalStep() = 0;
			//// 返回具体的路径
			//virtual const MazePath& path() = 0;
			// 搜索器的名称
			virtual std::string searcherName() const = 0;
		};
	}
}
#endif
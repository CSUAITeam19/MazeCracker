#ifndef MAZE_PATH_H
#define MAZE_PATH_H
#include "IMaze.h"
#include <vector>
#include <functional>

namespace MazeCracker
{
	namespace Maze
	{
		// 迷宫路径
		class MazePath
		{
			const IMaze& maze;
			std::vector<Vector2D> path;
			long cost;
		public:
			MazePath(const IMaze& maze);
			// 把新的点放进路径
			void push(const Vector2D& pos);
			// 尝试把新的点放进路径, 失败则false
			bool tryPush(const Vector2D& pos);
			// 把最新的点移除
			Vector2D pop();
			// 最新点
			Vector2D peek() const;
			//// 路径倒置
			//void reverse();
			
			// 总代价
			long totalCost() const;
			// 步数
			int step() const;
			// 遍历每个路径点(不包含代价)
			void traverse(const std::function<void(const Vector2D&)>& func) const;
			// 遍历每个路径点(不包含代价)
			void traverse(const std::function<void(Vector2D&)>& func);
		};

	}
}

#endif
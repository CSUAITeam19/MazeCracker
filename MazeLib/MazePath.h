#ifndef MAZE_PATH_H
#define MAZE_PATH_H
#include "IMaze.h"
#include <vector>
#include <functional>
#include <iostream>

namespace MazeCracker
{
	namespace Maze
	{
		// 迷宫路径
		class MazePath
		{
		protected:
			const IMaze& maze;
			std::vector<Vector2D> path;
			long cost;
		public:
			MazePath(const IMaze& maze);
			// 把新的点放进路径
			virtual void push(const Vector2D& pos);
			// 尝试把新的点放进路径, 失败则false
			virtual bool tryPush(const Vector2D& pos);
			// 把最新的点移除
			virtual Vector2D pop();
			// 最新点
			virtual Vector2D peek() const;
			//// 路径倒置
			//void reverse();
			
			// 总代价
			virtual long totalCost() const;
			// 步数
			virtual int step() const;
			// 遍历每个路径点(不包含代价)
			virtual void traverse(const std::function<void(const Vector2D&)>& func) const;
			// 遍历每个路径点(不包含代价)
			virtual void traverse(const std::function<void(Vector2D&)>& func);
			virtual void toStream(std::ostream& ostr) const;
		};
		std::ostream& operator<<(std::ostream& ostr, const MazePath& path);
		
		struct Operation
		{
			Vector2D pos;
			bool isPush;
			long cost;
			Operation(Vector2D pos, bool isPush, long cost):pos(pos),isPush(isPush), cost(cost)
			{
				
			}
		};
		std::ostream& operator<<(std::ostream& ostr, const Operation& oper);
		
		class MemorablePath : public MazePath
		{
			std::vector<Operation> historyOper;
		public:
			
			explicit MemorablePath(const IMaze& maze);
			void push(const Vector2D& pos) override;
			bool tryPush(const Vector2D& pos) override;
			Vector2D pop() override;
			void toStream(std::ostream& ostr) const override;
		};
	}
}

#endif
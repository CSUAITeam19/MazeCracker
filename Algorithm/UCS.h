#pragma once
#include "Maze.h"
#include <iostream>
#include <queue>

namespace MazeCracker
{
	namespace Maze
	{
		class UCS:virtual public IMazeSearcher
		{
			const IMaze& maze;//迷宫地图数据
			std::vector<std::vector<int>> vis;//是否访问过和能否访问
			std::vector<std::vector<int>> cost;//耗费 
			std::queue<Vector2D> openList;//访问表
			Vector2D entrancePos;
			std::ostream& out;

			bool isFinished;
			/// <summary>
			/// 内部实现
			/// </summary>
			void UCSImplement();
		public:
			UCS(const IMaze& maze, std::ostream& out);
			void run(Vector2D entrancePos) override;
			bool finished() override;
			std::string searcherName() const override;
		};
	}
}

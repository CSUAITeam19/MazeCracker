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
			const IMaze& maze;//�Թ���ͼ����
			std::vector<std::vector<int>> vis;//�Ƿ���ʹ����ܷ����
			std::vector<std::vector<int>> cost;//�ķ� 
			std::queue<Vector2D> openList;//���ʱ�
			Vector2D entrancePos;
			std::ostream& out;

			bool isFinished;
			/// <summary>
			/// �ڲ�ʵ��
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

#ifndef MAZE_PATH_H
#define MAZE_PATH_H
#include "IMaze.h"
#include <vector>
#include <functional>

namespace MazeCracker
{
	namespace Maze
	{
		// �Թ�·��
		class MazePath
		{
			const IMaze& maze;
			std::vector<Vector2D> path;
			long cost;
		public:
			MazePath(const IMaze& maze);
			// ���µĵ�Ž�·��
			void push(const Vector2D& pos);
			// ���԰��µĵ�Ž�·��, ʧ����false
			bool tryPush(const Vector2D& pos);
			// �����µĵ��Ƴ�
			Vector2D pop();
			// ���µ�
			Vector2D peek() const;
			//// ·������
			//void reverse();
			
			// �ܴ���
			long totalCost() const;
			// ����
			int step() const;
			// ����ÿ��·����(����������)
			void traverse(const std::function<void(const Vector2D&)>& func) const;
			// ����ÿ��·����(����������)
			void traverse(const std::function<void(Vector2D&)>& func);
		};

	}
}

#endif
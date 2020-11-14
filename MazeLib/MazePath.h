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
		// �Թ�·��
		class MazePath
		{
		protected:
			const IMaze& maze;
			std::vector<Vector2D> path;
			long cost;
		public:
			MazePath(const IMaze& maze);
			// ���µĵ�Ž�·��
			virtual void push(const Vector2D& pos);
			// ���԰��µĵ�Ž�·��, ʧ����false
			virtual bool tryPush(const Vector2D& pos);
			// �����µĵ��Ƴ�
			virtual Vector2D pop();
			// ���µ�
			virtual Vector2D peek() const;
			//// ·������
			//void reverse();
			
			// �ܴ���
			virtual long totalCost() const;
			// ����
			virtual int step() const;
			// ����ÿ��·����(����������)
			virtual void traverse(const std::function<void(const Vector2D&)>& func) const;
			// ����ÿ��·����(����������)
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
#ifndef IMAZE_H
#define IMAZE_H
#include "Vector2D.h"
//#include "ICell.h" // �²�ΪʲôҪע����һ��? ��Ҳ��֪��.

namespace MazeCracker
{
	namespace Maze
	{
		class ICell;
		// �Թ���Ԫ��״̬
		enum class MazeState
		{
			// ÿһ��λ����һ��״̬, ��ͬʱ�Ƚ϶���״̬������¿�������
			Wall = 0x1,
			Route = 0x2,
			Entry = 0x4,
			Exit = 0x8,
			// Visited = 0x10
		};
		class IMaze
		{
		public:
			// ��ȡ���
			virtual int getWidth() const = 0;
			// ��ȡ�߶�
			virtual int getHeight() const = 0;
			// ����Թ�Ϊȫ��ǽ��״̬
			virtual void clear() = 0;
			// ��ȡһ����Ԫ
			virtual ICell* getCell(const int& row, const int& col) const = 0;
			// ��ȡһ����Ԫ
			virtual ICell* getCell(const Vector2D& pos) const = 0;
			// ����һ����Ԫ
			virtual void setCell(const int& row, const int& col, const MazeState& newState) = 0;
			// ����һ����Ԫ
			virtual void setCell(const Vector2D& pos, const MazeState& newState) = 0;
			// ����Ч�Թ�
			virtual bool isValid() const = 0;
		};
	}
}

#endif // !IMAZE_H
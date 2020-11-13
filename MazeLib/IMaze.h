#ifndef IMAZE_H
#define IMAZE_H
#include <functional>

#include "Vector2D.h"
#include "MazeState.h"
//#include "ICell.h" // �²�ΪʲôҪע����һ��? ��Ҳ��֪��.

namespace MazeCracker
{
	namespace Maze
	{
		class ICell;
		class RowVisitor;
		
		class IMaze
		{
		public:
			virtual ~IMaze() = default;
			// ��ȡ���
			virtual int getWidth() const = 0;
			// ��ȡ�߶�
			virtual int getHeight() const = 0;
			// ����Թ�Ϊȫ��ǽ��״̬
			virtual void clear() = 0;
			// �����Թ�
			virtual void resize(const int& row, const int& col) = 0;
			// �����Թ�, ���뺯���ĵڶ�������Ϊtrue, ��ǰ����λ��Ϊ�Թ���ĩ
			virtual void traverse(std::function<void(ICell&, bool)> func) = 0;
			// �����Թ�, ���뺯���ĵڶ�������Ϊtrue, ��ǰ����λ��Ϊ�Թ���ĩ
			virtual void traverse(std::function<void(const ICell&, bool)> func) const = 0;
			// ��Ч����
			virtual bool validPos(const Vector2D& pos) const = 0;
			// ��Ч����
			virtual bool validPos(const int& row, const int& col) = 0;
			// ��ȡһ����Ԫ
			virtual const ICell& getCell(const int& row, const int& col) const = 0;
			// ��ȡһ����Ԫ
			virtual ICell& getCell(const int& row, const int& col) = 0;
			// ��ȡһ����Ԫ
			virtual const ICell& getCell(const Vector2D& pos) const = 0;
			// ��ȡһ����Ԫ
			virtual ICell& getCell(const Vector2D& pos) = 0;
			// ����һ����Ԫ
			virtual void setCell(const int& row, const int& col, const MazeState& newState) = 0;
			// ����һ����Ԫ
			virtual void setCell(const Vector2D& pos, const MazeState& newState) = 0;
			// ��ȡ�Թ��з�����
			virtual RowVisitor operator[](int row) = 0;
			// ��ȡ�Թ��з�����
			virtual RowVisitor operator[](int row) const = 0;
			// ����Ч�Թ�
			virtual bool isValid() const = 0;
		};
	}
}

#endif // !IMAZE_H
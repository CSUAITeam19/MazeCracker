#ifndef BASICROW_H
#define BASICROW_H

#include "IMaze.h"
//#include "ICell.h"

namespace MazeCracker
{
	namespace Maze
	{
		// �������Թ���(�ƺ�����Ҫ����չ��?)
		// class ICell;
		// class IMaze;
		class RowVisitor
		{
			IMaze* implementer;
			int row;
		public:
			// ֱ�Ӵ���һ���Թ���ʵ��
			RowVisitor(IMaze* implementer, int row) noexcept;
			const ICell& operator[](const int& index) const;
			ICell& operator[](const int& index);
		};
	}
}

#endif



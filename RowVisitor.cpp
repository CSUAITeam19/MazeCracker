#include "IMaze.h"
#include "RowVisitor.h"

namespace MazeCracker
{
	namespace Maze
	{
		RowVisitor::RowVisitor(IMaze* implementer, int row) noexcept :implementer(implementer), row(row)
		{
			// ��ָ����кŷŽ�ȥ����
		}
		
		const ICell& RowVisitor::operator[](const size_t& index) const
		{
			return (*const_cast<IMaze const*>(implementer))[row][index];
		}
		ICell& RowVisitor::operator[](const size_t& index)
		{
			return implementer->getCell(row, index);
		}

	}
}

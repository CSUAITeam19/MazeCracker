#include "IMaze.h"
#include "RowVisitor.h"

namespace MazeCracker
{
	namespace Maze
	{
		RowVisitor::RowVisitor(IMaze* implementer, int row) noexcept :implementer(implementer), row(row)
		{
			// 把指针和行号放进去即可
		}
		
		const ICell& RowVisitor::operator[](const int& index) const
		{
			return (*const_cast<IMaze const*>(implementer))[row][index];
		}
		ICell& RowVisitor::operator[](const int& index)
		{
			return implementer->getCell(row, index);
		}

	}
}

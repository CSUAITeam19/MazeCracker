#ifndef ICELL_H
#define ICELL_H
#include "IMaze.h"

namespace MazeCracker
{
	namespace Maze
	{
		class IMaze;
		// �Թ���Ԫ
		class ICell
		{
		public:
			virtual ~ICell() = default;
			// ��ȡ��Ԫ��״̬
			virtual MazeState getState() const = 0;
			// ���õ�Ԫ��״̬
			virtual void setState(const MazeState& newState) = 0;
			// ��ʽת��ΪMazeState
			virtual operator MazeState() const = 0;
			virtual ICell& operator=(const MazeState& state) = 0;
			virtual IMaze* getContainer() const = 0;
		};
	}
}

#endif // !ICELL_H


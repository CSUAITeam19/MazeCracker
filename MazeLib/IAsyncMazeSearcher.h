#ifndef IASYNC_MAZE_SEARCHER_H
#define IASYNC_MAZE_SEARCHER_H
#include "IMazeSearcher.h"

namespace MazeCracker
{
	namespace Maze
	{
		// �첽��������, �������������㷨����
		// TODO[Optional]: �첽����������ѡ������, ��һ��Ҫʵ��
		class IAsyncMazeSearcher :virtual public IMazeSearcher
		{
		public:

			// ��ʼ����
			virtual void begin() = 0;
			// ִ����һ������
			virtual void next() = 0;
			void run(Vector2D entrancePos = Vector2D(1, 1)) override;
		};

		inline void IAsyncMazeSearcher::run(Vector2D entrancePos)
		{
			// do everything in one for loop
			for (begin(); !finished(); next());
		}
	}
}
#endif

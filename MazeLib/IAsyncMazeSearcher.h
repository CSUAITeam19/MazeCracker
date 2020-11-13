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
			void run() override;
			// ��ʼ����
			virtual void begin() = 0;
			// ִ����һ������
			virtual void next() = 0;
		};

		inline void IAsyncMazeSearcher::run()
		{
			// do everything in one for loop
			for (begin(); !finished(); next());
		}
	}
}
#endif

#ifndef IMAZESEARCHER_H
#define IMAZESEARCHER_H
#include "IMaze.h"

namespace MazeCracker
{
	namespace Maze
	{
		// �Թ��������ӿ�, ���������������
		class IMazeSearcher
		{
		public:
			// ��ʼ�������㷨
			virtual void init(IMaze& maze) = 0;
			// �����㷨
			virtual void run() = 0;
			// �Ƿ����
			virtual bool finished() = 0;
			// ��ȡ���·�����ܴ���
			virtual int totalCost() = 0;
			virtual int totalStep() = 0;
			// ������������
			virtual std::string searcherName() = 0;
		};
	}
}
#endif
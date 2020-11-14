#ifndef IMAZESEARCHER_H
#define IMAZESEARCHER_H
#include "IMaze.h"
#include "MazePath.h"

namespace MazeCracker
{
	namespace Maze
	{
		// �Թ��������ӿ�, ���������������
		class IMazeSearcher
		{
		public:
			// �����㷨
			virtual void run(Vector2D entrancePos = Vector2D(1,1)) = 0;
			// �Ƿ����
			virtual bool finished() = 0;
			// ��ȡ���·�����ܴ���
			virtual int totalCost() = 0;
			// ���·���Ĳ���
			virtual int totalStep() = 0;
			// ���ؾ����·��
			virtual const MazePath& path() = 0;
			// ������������
			virtual std::string searcherName() const = 0;
		};
	}
}
#endif
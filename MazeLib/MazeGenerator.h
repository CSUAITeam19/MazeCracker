#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H

#include <iostream>
#include <vector>
#include <time.h>
#include "IMaze.h"

//using namespace std;

// static const int N = 16;

namespace MazeCracker
{
	namespace Maze
	{
		void dig(IMaze& maze, const int& x, const  int& y);

		// �����Թ���ά����
		IMaze& generateMaze(IMaze& maze, const int& row, const int& col, bool initRand = false);

		// ����ά�����ӡ��ָ�������
		void printToStream(std::ostream& str, const IMaze& maze);
		
		// �����Ԫ��־��Ӧ���ַ���
		std::string cellToString(const MazeState& cellState);
	}
}


#endif // MAZEGENERATOR_H

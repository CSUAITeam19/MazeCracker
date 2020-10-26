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
		void dig(std::vector<std::vector<int>>& maze, const int& x, const  int& y);

		// �����Թ���ά����
		std::vector<std::vector<int> > generateMaze(std::vector<std::vector<int> >& result, const int& row, const int& column, bool initRand = false);

		// ����ά�����ӡ��ָ�������
		void printToStream(std::ostream& str, const std::vector<std::vector<int>>& maze);
		
		// �����Ԫ��־��Ӧ���ַ���
		std::string cellToString(const MazeState& cellState);
	}
}


#endif // MAZEGENERATOR_H

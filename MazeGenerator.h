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

		// 生成迷宫二维数组
		std::vector<std::vector<int> > generateMaze(std::vector<std::vector<int> >& result, const int& row, const int& column, bool initRand = false);

		// 将二维数组打印到指定输出流
		void printToStream(std::ostream& str, const std::vector<std::vector<int>>& maze);
		
		// 输出单元标志对应的字符串
		std::string cellToString(const MazeState& cellState);
	}
}


#endif // MAZEGENERATOR_H

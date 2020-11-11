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

		// 生成迷宫二维数组
		IMaze& generateMaze(IMaze& maze, const int& row, const int& col, bool initRand = false);

		// 将二维数组打印到指定输出流
		void printToStream(std::ostream& str, const IMaze& maze);
		
		// 输出单元标志对应的字符串
		std::string cellToString(const MazeState& cellState);
	}
}


#endif // MAZEGENERATOR_H

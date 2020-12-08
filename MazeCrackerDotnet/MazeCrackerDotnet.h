#pragma once
#include "Maze.h"
using namespace System;

namespace MazeCrackerDotnet {
	public ref class Maze
	{
		/// <summary>
		/// 迷宫的内部实现
		/// </summary>
		MazeCracker::Maze::BasicMaze& mazeImpl;
	public:
		/// <summary>
		/// 创建一个迷宫
		/// </summary>
		/// <param name="row"></param>
		/// <param name="col"></param>
		Maze(int row, int col);
		/// <summary>
		/// 从文件读取一个迷宫
		/// </summary>
		/// <param name="path"></param>
		Maze(String^ path);
		/// <summary>
		/// 产生排版好的, 易于阅读的字符串
		/// </summary>
		/// <returns></returns>
		String^ ToString() override;
		/// <summary>
		/// 产生用于数据交换的字符串
		/// </summary>
		/// <returns></returns>
		String^ ToDataString(bool nosize);
		/// <summary>
		/// 用内置算法随机生成一个迷宫
		/// </summary>
		void RandomGenerate();
		~Maze();
		!Maze();
	};
}

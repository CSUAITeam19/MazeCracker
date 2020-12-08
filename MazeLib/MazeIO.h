#ifndef MAZE_IO_H
#define MAZE_IO_H
#include "Maze.h"
#include <string>

namespace MazeCracker
{
	namespace IO
	{
		/// <summary>
		/// ���ļ��ж�ȡ
		/// </summary>
		/// <param name="maze"></param>
		/// <param name="path"></param>
		void readFromFile(Maze::IMaze& maze, const std::string& path);
		/// <summary>
		/// ����������
		/// </summary>
		/// <param name="maze"></param>
		/// <param name="ostr"></param>
		/// <param name="nosize"></param>
		void saveToOStream(const Maze::IMaze& maze, std::ostream& ostr, bool nosize);
		/// <summary>
		/// ���浽�ļ�
		/// </summary>
		/// <param name="maze"></param>
		/// <param name="path"></param>
		/// <param name="nosize"></param>
		void saveToFile(const Maze::IMaze& maze, const std::string& path, bool nosize = false);
	}
}


#endif

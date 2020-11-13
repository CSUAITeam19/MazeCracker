#ifndef  MAZESTATE_H
#define MAZESTATE_H
#include <string>
namespace MazeCracker
{
	namespace Maze
	{
		// �Թ���Ԫ��״̬
		enum class MazeState
		{
			// ÿһ��λ����һ��״̬, ��ͬʱ�Ƚ϶���״̬������¿�������
			Wall = 0x1,
			Route = 0x2,
			Entry = 0x4,
			Exit = 0x8
			// Visited = 0x10
		};

		std::wstring ToString(MazeState state);
		
		inline int operator|(const MazeState& a, const MazeState& b)
		{
			return static_cast<int>(a) | static_cast<int>(b);
		}

		inline int operator|(const int& a, const MazeState& b)
		{
			return a | static_cast<int>(b);
		}

		inline int operator|(const MazeState& a, const int& b)
		{
			return static_cast<int>(a) | b;
		}
	}
}
#endif

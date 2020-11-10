#include "MazeState.h"
#include <string>

namespace MazeCracker
{
	namespace Maze
	{
		std::wstring ToString(MazeState state)
		{
			switch (state)
			{
			case MazeState::Wall:	return L"Wall";
			case MazeState::Route:	return L"Route";
			case MazeState::Entry:	return L"Entry";
			case MazeState::Exit:	return L"Exit";
			default:				return std::to_wstring(static_cast<int>(state));
			}
		}
	}
}

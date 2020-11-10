#include "pch.h"
#include "CppUnitTest.h"
#include "BasicMaze.h"
#include "RowVisitor.h"
#include "Vector2D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace MazeCracker::Maze;
using namespace MazeCracker;

namespace UnitTest
{
	TEST_CLASS(Test_Maze)
	{
	public:
		TEST_METHOD(getSet)
		{
			auto _maze = new BasicMaze(1, 1);
			IMaze& maze = *_maze;
			maze[0][0].setState(MazeState::Exit);
			Assert::AreEqual(MazeState::Exit, maze[0][0].getState());

			maze.getCell(Vector2D(0, 0)).setState(MazeState::Entry);
			Assert::AreEqual(MazeState::Entry, maze.getCell(Vector2D(0, 0)).getState());

			maze.getCell(0, 0).setState(MazeState::Route);
			Assert::AreEqual(MazeState::Route, maze.getCell(0, 0).getState());

			delete _maze;
		}
		TEST_METHOD(initMaze)
		{
			BasicMaze maze(16, 16);
			IMaze& maze_interface = maze;
			Assert::AreEqual(16, maze_interface.getWidth());
			Assert::AreEqual(16, maze_interface.getHeight());
			for (int i = 0; i < 16; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					if (MazeState::Wall != maze_interface[i][j])
					{
						Assert::Fail(L"This position has wrong init value!");
					}
				}
			}
		}
	};
}

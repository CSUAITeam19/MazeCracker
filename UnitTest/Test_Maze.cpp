#include "pch.h"
#include "CppUnitTest.h"
#include "Maze.h"

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

			maze.getCell(Vector2D(0, 0)) = MazeState::Entry;
			Assert::AreEqual(MazeState::Entry, maze.getCell(Vector2D(0, 0)).getState());

			maze.getCell(0, 0) = MazeState::Route;
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
		TEST_METHOD(resizeMaze)
		{
			auto _maze = BasicMaze(1, 1);
			IMaze& maze = _maze;
			maze.resize(16, 16);
			Assert::AreEqual(16, maze.getWidth());
			Assert::AreEqual(16, maze.getHeight());
			for (int i = 0; i < 16; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					if (MazeState::Wall != maze[i][j])
					{
						Assert::Fail(L"This position has wrong init value!");
					}
				}
			}
			maze.resize(20, 20);
			Assert::AreEqual(20, maze.getWidth());
			Assert::AreEqual(20, maze.getHeight());
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					if (MazeState::Wall != maze[i][j])
					{
						Assert::Fail(L"This position has wrong init value!");
					}
				}
			}
		}
		TEST_METHOD(generateMaze)
		{
			auto _maze = BasicMaze(1, 1);
			IMaze& maze = _maze;
			int failCount = 0;
			for (int i = 0; i < 100; i++)
			{
				Maze::generateMaze(maze, 16, 16, true);
				if(!maze.isValid()) failCount++;
			}
			Assert::IsTrue(failCount <= 2, L"Too many fail generate!");
		}
		TEST_METHOD(searcher)
		{
			auto _maze = BasicMaze(1, 1);
			IMaze& maze = _maze;
			Maze::generateMaze(maze, 16, 16, true);
			DFSSearcher _s = DFSSearcher(maze);
			IMazeSearcher& searcher = _s;
			searcher.run();
			Assert::IsTrue(searcher.finished(), L"can't find available path!");
		}
	};
}

#include "MazeGenerator.h"
#include <unordered_map>
#include <stack>
#include "Maze.h"

using std::vector;
using std::unordered_map;

namespace MazeCracker
{
	namespace Maze
	{
		// 四个方向上最多一格标记为Route
		inline bool oneRouteIn4Dir(const IMaze& maze, Vector2D pos)
		{
			int counter = 0;
			for (auto dir : Vector2D::fourDirections)
			{
				auto tempPos = pos + dir;
				if (!maze.validPos(tempPos))
				{
					counter++;
				}else
				{
					if (maze.getCell(tempPos) == MazeState::Route) counter++;
				}
			}
			return counter <= 1;
		}

		inline void randomizeArray(int* arr, int size)
		{
			for (int i = size - 1; i >= 0; i--)
			{
				int r = rand() % (i + 1);
				std::swap(arr[r], arr[i]);
			}
		}
		
		void dig(IMaze& maze, const int& inX, const int& inY)
		{
			std::stack<Vector2D> stepPosStack{};
			std::stack<int*> digListStack{};
			std::stack<int> dirIndexStack{};
			stepPosStack.push({ inX,inY });
			digListStack.push(new int[4]{0,1,2,3});
			randomizeArray(digListStack.top(), 4);
			dirIndexStack.push(0);
			while (!stepPosStack.empty())
			{
				auto x = stepPosStack.top().x;
				auto y = stepPosStack.top().y;

				// printToStream(cout, maze);
				if(maze[x][y] == MazeState::Route)
				{
					// 切换到已开启位置的下一个方向
					auto i = dirIndexStack.top();
					dirIndexStack.pop();
					dirIndexStack.push(i + 1);
					if (i >= 3)
					{
						// 该点4个方向已经开完
						stepPosStack.pop();
						delete digListStack.top();
						digListStack.pop();
						dirIndexStack.pop();
						continue;
					}
					auto delta = Vector2D::fourDirections[digListStack.top()[dirIndexStack.top()]];
					x += delta.x; y += delta.y;
				}
				if (!maze.validPos({ x,y }) || maze[x][y] != MazeState::Wall || !oneRouteIn4Dir(maze, { x,y }))
				{
					continue;
				}
				
				maze[x][y] = MazeState::Route;
				
				// 添加新开启的点, 进入下一个开路操作
				stepPosStack.push({x,y});
				digListStack.push(new int[4]{ 0,1,2,3 });
				randomizeArray(digListStack.top(), 4);
				dirIndexStack.push(-1);
			}
		}

		IMaze& generateMaze(IMaze& maze, const int& row, const int& col, bool initRand)
		{
			if (initRand) srand(static_cast<unsigned>(time(NULL)));

			// init 
			maze.clear();
			maze.resize(row, col);
			maze[1][1] = MazeState::Entry;
			maze[row - 2][col - 2] = MazeState::Exit;
			dig(maze, 1, 2);
			

			return maze;
		}

		void printToStream(std::ostream& str, const IMaze& maze)
		{
			maze.traverse([&str](const ICell& cell, bool lineEnd)
			{
				str << cellToString(cell);
				if (lineEnd) str << '\n';
			});
		}

		std::string cellToString(const MazeState& cellState)
		{
			unordered_map<MazeState, std::string> map = unordered_map<MazeState, std::string>
			{
				{MazeState::Route, "  "},
				{MazeState::Wall, "█"},
				{MazeState::Entry, "--"},
				{MazeState::Exit, "++"}
			};
			//if(cellState==MazeState::Exit)
			//{
			//	
			//}
			//if (map[cellState] == "++")
			//{
			//	// wtf?
			//}
			return map[cellState];
		}
	}
}

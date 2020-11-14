#ifndef GENERIC_MAZE_H
#define GENERIC_MAZE_H
#include "BasicMaze.h"
#include "ICell.h"

namespace MazeCracker
{
	namespace Maze
	{
		template<class TCell>
		class GenericMaze : public virtual BasicMaze
		{
		protected:
			void dataInit(std::vector<ICell*>& data, long long size) override;
		public:
			GenericMaze();
			GenericMaze(const int& row, const int& col);
		};
		template <class TCell>
		void GenericMaze<TCell>::dataInit(std::vector<ICell*>& data, long long size)
		{
			static_assert(std::is_base_of<ICell, TCell>::value, "TCell must inherit from ICell");
			if (data.size() < size)
			{
				// set all Wall
				for (int i = 0; i < data.size(); i++)
				{
					(*data[i]) = MazeState::Wall;
				}
				// create new
				for (int i = data.size(); i < size; i++)
				{
					data.emplace_back(new TCell{ static_cast<int>(MazeState::Wall), this });
				}
			}
			else if (data.size() > size)
			{
				// erase all elements that exceed the range of size
				for (int i = data.size() - 1; i >= size; i--)
				{
					delete data[i];
					data.erase(data.begin() + i);
				}
				// set all wall
				for (ICell* cell : data) (*cell) = MazeState::Wall;
			}
			else
			{
				// set all wall
				for (ICell* cell : data) (*cell) = MazeState::Wall;
			}
		}

		template <class TCell>
		GenericMaze<TCell>::GenericMaze(): BasicMaze()
		{
		}

		template <class TCell>
		GenericMaze<TCell>::GenericMaze(const int& row, const int& col): BasicMaze(row,col)
		{
		}
	}
}
#endif

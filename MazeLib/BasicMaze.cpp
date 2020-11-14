#include "BasicMaze.h"
#include "RowVisitor.h"
#include <stdexcept>
#include "MazeUtility.h"
using std::vector;

namespace MazeCracker
{
	namespace Maze
	{
		void BasicMaze::dataInit(std::vector<ICell*>& data, long long size)
		{
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
					data.emplace_back(new BasicCell{ (int)MazeState::Wall, this });
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

		BasicMaze::BasicMaze() :data{}, size({ 0,0 })
		{

		}

		BasicMaze::BasicMaze(const int& row, const int& col)
		{
			if (row < 1 || col < 1)
			{
				throw std::bad_array_new_length();
			}
			// 数据初始化
			dataInit(data, 1ll * row * col);
			// 记下尺寸
			size = Vector2D(row, col);
		}
		int BasicMaze::getWidth() const
		{
			return size.x;
		}
		int BasicMaze::getHeight() const
		{
			return size.y;
		}
		void BasicMaze::clear()
		{
			for (auto cell : data) delete cell;
			data.clear();
			size = Vector2D();
		}

		void BasicMaze::resize(const int& row, const int& col)
		{
			clear();
			dataInit(data, row * col);
			size = Vector2D(row, col);
		}

		void BasicMaze::traverse(std::function<void(ICell&, bool)> func)
		{
			for (int row = 0; row < size.x; row++)
			{
				for (int col = 0; col < size.y - 1; col++)
				{
					func(*data[1ll * row * size.x + col], false);
				}
				func(*data[1ll * row * size.x + (1ll * size.y - 1)], true);
			}
		}

		void BasicMaze::traverse(std::function<void(const ICell&, bool)> func) const
		{
			for (int row = 0; row < size.x; row++)
			{
				for (int col = 0; col < size.y - 1; col++)
				{
					func(*data[1ll * row * size.x + col], false);
				}
				func(*data[1ll * row * size.x + (1ll * size.y - 1)], true);
			}
		}

		bool BasicMaze::validPos(const Vector2D& pos) const
		{
			return pos.x >= 0 && pos.x < size.x&& pos.y >= 0 && pos.y < size.y;
		}

		bool BasicMaze::validPos(const int& row, const int& col)
		{
			return row >= 0 && row < size.x&& col >= 0 && col < size.y;
		}

		const ICell& BasicMaze::getCell(const int& row, const int& col) const
		{
			return *data[1ll * row * size.x + col];
		}

		ICell& BasicMaze::getCell(const int& row, const int& col)
		{
			return *data[1ll * row * size.x + col];
		}

		const ICell& BasicMaze::getCell(const Vector2D& pos) const
		{
			return *data[1ll * pos.x * size.x + pos.y];
		}

		ICell& BasicMaze::getCell(const Vector2D& pos)
		{
			return *data[1ll * pos.x * size.x + pos.y];
		}
		void BasicMaze::setCell(const int& row, const int& col, const MazeState& newState)
		{
			(*this)[row][col].setState(newState);
		}
		void BasicMaze::setCell(const Vector2D& pos, const MazeState& newState)
		{
			(*this)[pos.x][pos.y].setState(newState);
		}

		bool BasicMaze::walkable(const Vector2D& from, const Vector2D& to, int* cost) const
		{
			// not out of the maze
			if (!validPos(to)) return false;
			// no wall
			if (getCell(to) == MazeState::Wall) return false;
			// four directions
			const auto delta = to - from;
			if (delta.lengthManhattan() <= 1)
			{
				if (cost) *cost = 10;
				return true;
			}
			// too far
			if (abs(delta.x) > 1 || abs(delta.y) > 1) return false;
			// either beside path has
			if (getCell(from + Vector2D(delta.x, 0)) != MazeState::Wall ||
				getCell(from + Vector2D(0, delta.y)) != MazeState::Wall)
			{
				if (cost) *cost = 14;
				return true;
			}

			return false;
		}

		bool BasicMaze::isValid() const
		{
			return Maze::isValid(*this);
		}

		RowVisitor BasicMaze::operator[](int row)
		{
			return const_cast<BasicMaze const*>(this)->operator[](row);
		}

		RowVisitor BasicMaze::operator[](int row) const
		{
			//return const_cast<IMazeRow const*>((*const_cast<BasicMaze const*>(this))[row]);
			if (row >= size.x)
			{
				throw std::out_of_range("row should be less than size.x!");
			}
			if (row < 0)
			{
				throw std::out_of_range("row should be greater than 0!");
			}
			return RowVisitor{ (IMaze*)this, row };
		}

		const ICell& BasicMaze::operator[](Vector2D pos) const
		{
			return getCell(pos);
		}

		ICell& BasicMaze::operator[](Vector2D pos)
		{
			return getCell(pos);
		}

		BasicMaze::~BasicMaze()
		{
			for (auto cell : data) delete cell;
		}
	}
}


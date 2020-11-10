#include "BasicMaze.h"
#include "RowVisitor.h"
#include <stdexcept>
using std::vector;

namespace MazeCracker
{
    namespace Maze
    {
	    void BasicMaze::dataInit(std::vector<ICell*>& data, long long size)
	    {
			for (long long i = 0; i < size; i++)
	    	{
                data.push_back(new BasicCell(static_cast<int>(MazeState::Wall), this));
	    	}
	    }

        BasicMaze::BasicMaze(const int& row, const int& col)
        {
			if (row < 1 || col < 1)
        	{
                throw std::bad_array_new_length();
        	}
            // ���ݳ�ʼ��
            dataInit(data, 1ll * row * col);
            // ���³ߴ�
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
            for (auto cell : data) delete& cell;
	    	data.clear();
            size = Vector2D();
        }

	    const ICell& BasicMaze::getCell(const int& row, const int& col) const
	    {
            return *data[1ll * row + col];
	    }

	    ICell& BasicMaze::getCell(const int& row, const int& col)
        {
            return *data[1ll * row + col];
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
        bool BasicMaze::isValid() const
        {
            //TODO
            return true;
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

	    BasicMaze::~BasicMaze()
	    {
            for (auto cell : data) delete cell;
	    }
    }
}


#include "BasicMaze.h"

using std::vector;

namespace MazeCracker
{
    namespace Maze
    {
        BasicMaze::BasicMaze(const int& row, const int& col)
        {
            // 全部是墙
            data = vector<vector<BasicCell>>(row, vector<BasicCell>(col, BasicCell((int)MazeState::Wall, this)));
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
            data.clear();
            size = Vector2D();
        }
        ICell* BasicMaze::getCell(const int& row, const int& col) const
        {
            return (ICell*)&data[row][col];
        }
        ICell* BasicMaze::getCell(const Vector2D& pos) const
        {
            return getCell(pos.x, pos.y);
        }
        void BasicMaze::setCell(const int& row, const int& col, const MazeState& newState)
        {
            data[row][col].setState(newState);
        }
        void BasicMaze::setCell(const Vector2D& pos, const MazeState& newState)
        {
            data[pos.x][pos.y].setState(newState);
        }
        bool BasicMaze::isValid() const
        {
            //TODO
            return true;
        }
    }
}


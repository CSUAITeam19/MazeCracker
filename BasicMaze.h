#pragma once
#include <vector>
#include "IMaze.h"
#include "BasicCell.h"

namespace MazeCracker
{
    namespace Maze
    {
        // �����Թ�
		class BasicMaze : virtual public IMaze
        {
        protected:
            std::vector<std::vector<BasicCell>> data;
            Vector2D size;
        public:
            BasicMaze(const int& row = 1, const int& col = 1);

            // ͨ�� IMaze �̳�
            virtual int getWidth() const override;
            virtual int getHeight() const override;
            virtual void clear() override;
            virtual ICell* getCell(const int& row, const int& col) const override;
            virtual ICell* getCell(const Vector2D& pos) const override;
            virtual void setCell(const int& row, const int& col, const MazeState& newState) override;
            virtual void setCell(const Vector2D& pos, const MazeState& newState) override;
            virtual bool isValid() const override;
        };
    }
}


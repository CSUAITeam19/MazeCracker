#pragma once
#include <vector>
#include "IMaze.h"
//#include "ICell.h"
#include "BasicCell.h"

namespace MazeCracker
{
    namespace Maze
    {
        // �����Թ�
		class BasicMaze : virtual public IMaze
        {
        protected:
            std::vector<ICell*> data;
            Vector2D size;
            virtual void dataInit(std::vector<ICell*>& data,long long size);
        public:
            BasicMaze(const int& row = 1, const int& col = 1);

            // ͨ�� IMaze �̳�
            int getWidth() const override;
            int getHeight() const override;
            void clear() override;
            ICell const* getCell(const Vector2D& pos) const override;
            ICell* getCell(const Vector2D& pos) override;
            void setCell(const int& row, const int& col, const MazeState& newState) override;
            void setCell(const Vector2D& pos, const MazeState& newState) override;
            bool isValid() const override;
            RowVisitor operator[](int row) override;
            RowVisitor operator[](int row) const override;

            ~BasicMaze() override;
        };
    }
}


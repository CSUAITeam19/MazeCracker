#ifndef BASICCELL_H
#define BASICCELL_H
#include "ICell.h"

namespace MazeCracker
{
    namespace Maze
    {
        class BasicCell : virtual public ICell
        {
        protected:
            int state;
            IMaze* container;
        public:
            BasicCell(const int& state, IMaze* container);
            // Í¨¹ý ICell ¼Ì³Ð
            virtual MazeState getState() const override;

            virtual void setState(const MazeState& newState) override;

            virtual IMaze* getContainer() const override;

            virtual operator MazeState() const override;

        };
    }
}
#endif // !BASICCELL_H

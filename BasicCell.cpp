#include "BasicCell.h"
namespace MazeCracker
{
    namespace Maze
    {
        BasicCell::BasicCell(const int& state, IMaze* container)
        {
            this->state = state;
            this->container = container;
        }
        MazeState BasicCell::getState() const
        {
            return (MazeState)state;
        }
        void BasicCell::setState(const MazeState& newState)
        {
            state = (int)newState;
        }
        IMaze* BasicCell::getContainer() const
        {
            return container;
        }
        BasicCell::operator MazeState() const
        {
            return (MazeState)state;
        }
    }
}
#include "BasicCell.h"
//#include <iostream>
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
            return static_cast<MazeState>(state);
        }
        void BasicCell::setState(const MazeState& newState)
        {
            state = static_cast<int>(newState);
        }
        IMaze* BasicCell::getContainer() const
        {
            return container;
        }
        BasicCell::operator MazeState() const
        {
            return static_cast<MazeState>(state);
        }

        BasicCell& BasicCell::operator=(const MazeState& state)
        {
        	// debug
            //std::cout << "Got an " << static_cast<char>(ToString(state)[1]) << std::endl;
            this->state = static_cast<int>(state);
            return *this;
        }
    }
}
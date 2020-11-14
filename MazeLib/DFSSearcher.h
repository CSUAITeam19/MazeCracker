#ifndef DFS_SEARCHER_H
#define DFS_SEARCHER_H
#include "IMazeSearcher.h"
#include "MazePath.h"

namespace MazeCracker
{
	namespace Maze
	{
		class DFSSearcher : public IMazeSearcher
		{
		private:
			IMaze& maze;
			MemorablePath mazePath;
			bool search(Vector2D from, Vector2D pos, std::vector<std::vector<bool>>& visitMap);
		public:
			explicit DFSSearcher(IMaze& maze);
			
			bool finished() override;
			void run(Vector2D entrancePos = Vector2D(1, 1)) override;
			int totalCost() override;
			int totalStep() override;
			const MazePath& path() override;
			
			std::string searcherName() const override;

			
		};
	}
}

#endif


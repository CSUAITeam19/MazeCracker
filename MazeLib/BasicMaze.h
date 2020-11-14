#pragma once
#include <vector>
#include "IMaze.h"
//#include "ICell.h"
#include "BasicCell.h"

namespace MazeCracker
{
	namespace Maze
	{
		// »ù±¾ÃÔ¹¬
		class BasicMaze : virtual public IMaze
		{
		protected:
			std::vector<ICell*> data;
			Vector2D size;
			virtual void dataInit(std::vector<ICell*>& data, long long size);
		public:
			BasicMaze();
			BasicMaze(const int& row, const int& col);

			int getWidth() const override;
			int getHeight() const override;
			void clear() override;
			void resize(const int& row, const int& col) override;
			void traverse(std::function<void(ICell&, bool)> func) override;
			void traverse(std::function<void(const ICell&, bool)> func) const override;
			bool validPos(const Vector2D& pos) const override;
			bool validPos(const int& row, const int& col) override;
			const ICell& getCell(const int& row, const int& col) const override;
			ICell& getCell(const int& row, const int& col) override;
			const ICell& getCell(const Vector2D& pos) const override;
			ICell& getCell(const Vector2D& pos) override;
			void setCell(const int& row, const int& col, const MazeState& newState) override;
			void setCell(const Vector2D& pos, const MazeState& newState) override;
			bool walkable(const Vector2D& from, const Vector2D& to, int* cost) const override;
			bool isValid() const override;
			RowVisitor operator[](int row) override;
			RowVisitor operator[](int row) const override;
			const ICell& operator[](Vector2D pos) const override;
			ICell& operator[](Vector2D pos) override;
			~BasicMaze() override;


		};
	}
}


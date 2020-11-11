#ifndef VECTOR2D_H
#define VECTOR2D_H

namespace MazeCracker
{
	class Vector2D
	{
	public:
		// 表示四个方向的数组
		static const Vector2D fourDirections[4];
		int x, y;
		Vector2D(int x = 0, int y = 0);
		Vector2D operator+(const Vector2D& b) const;
		Vector2D operator-(const Vector2D& b) const;
		bool operator==(const Vector2D& b) const;
		bool operator!=(const Vector2D& b) const;
		// 欧式距离, 浮点型
		float lengthFloat() const;
		// 欧式距离, 整型
		int lengthInt() const;
		// 曼哈顿距离
		int lengthManhattan() const;
	};
}

#endif // !VECTOR2D_H



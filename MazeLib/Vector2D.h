#ifndef VECTOR2D_H
#define VECTOR2D_H

namespace MazeCracker
{
	class Vector2D
	{
	public:
		/// <summary>
		/// 表示四个垂直/水平方向的数组
		/// </summary>
		static const Vector2D fourDirections[4];
		/// <summary>
		/// 表示四个对角方向的数组
		/// </summary>
		static const Vector2D diagonalDirection[4];
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



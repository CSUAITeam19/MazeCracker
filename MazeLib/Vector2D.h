#ifndef VECTOR2D_H
#define VECTOR2D_H

namespace MazeCracker
{
	class Vector2D
	{
	public:
		// ��ʾ�ĸ����������
		static const Vector2D fourDirections[4];
		int x, y;
		Vector2D(int x = 0, int y = 0);
		Vector2D operator+(const Vector2D& b) const;
		Vector2D operator-(const Vector2D& b) const;
		bool operator==(const Vector2D& b) const;
		bool operator!=(const Vector2D& b) const;
		// ŷʽ����, ������
		float lengthFloat() const;
		// ŷʽ����, ����
		int lengthInt() const;
		// �����پ���
		int lengthManhattan() const;
	};
}

#endif // !VECTOR2D_H



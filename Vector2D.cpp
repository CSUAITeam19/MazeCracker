#include "Vector2D.h"
#include "qmath.h"
namespace MazeCracker
{
	Vector2D::Vector2D(int x, int y) :x(x), y(y)
	{
	}
	Vector2D Vector2D::operator+(const Vector2D& b) const
	{
		return Vector2D(x + b.x, y + b.y);
	}
	Vector2D Vector2D::operator-(const Vector2D& b) const
	{
		return Vector2D(x - b.x, y - b.y);
	}
	bool Vector2D::operator==(const Vector2D& b) const
	{
		return x == b.x && y == b.y;
	}
	float Vector2D::lengthFloat() const
	{
		return qSqrt(x * x + y * y);
	}
	int Vector2D::lengthInt() const
	{
		return lengthFloat();
	}
	int Vector2D::lengthManhattan() const
	{
		return qAbs(x)+qAbs(y);
	}
}

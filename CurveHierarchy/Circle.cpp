#include "Circle.h"

Circle::Circle(double radius)
{
	_radius = radius;
}

Vec3 Circle::GetValue(double t) const
{
	return
	{
		_radius * cos(t),
		_radius * sin(t),
		0.0
	};
}

void Circle::WriteTo(std::ostream& out) const
{
	out << "{\n\tType: Circle, \n\tRadius: " << _radius << "\n}";
}
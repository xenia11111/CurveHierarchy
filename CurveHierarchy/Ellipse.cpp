#include "Ellipse.h"

Ellipse::Ellipse(double radiusX, double radiusY)
{
	_radiusX = radiusX;
	_radiusY = radiusY;
}

Vec3 Ellipse::GetValue(double t) const 
{
	return
	{
		cos(t) * _radiusX,
		sin(t) * _radiusY,
		0.0
	};
}

void Ellipse::WriteTo(std::ostream& out) const 
{
	out << "{\n\tType: Ellipse,\n\tRadiusX: " << _radiusX << ",\n\tRadiusY: " << _radiusY << "\n}";
}
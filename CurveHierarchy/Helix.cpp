#include "Helix.h"

Helix::Helix(double radius, double step)
{
	_radius = radius;
	_step = step;
}

Vec3 Helix::GetValue(double t) const
{
	return
	{
		cos(t) * _radius,
		sin(t) * _radius,
		_step,
	};
}

void Helix::WriteTo(std::ostream& out) const 
{
	out << "{\n\tType: Helix,\n\tRadius: " << _radius << ",\n\tStep: " << _step << "\n}";
}
#include "Vec3.h"

Vec3 Vec3::operator -(Vec3 const& other) const
{
	return
	{
		x - other.x,
		y - other.y,
		z - other.z
	};
}

Vec3 Vec3::operator / (double coeff) const
{
	return
	{
		x / coeff,
		y / coeff,
		z / coeff
	};
}
void Vec3::WriteTo(std::ostream& out) const 
{
	out << "{ " << x << ", " << y << ", " << z << " }";
}

std::ostream& operator << (std::ostream& out, const Vec3& vec)
{
	vec.WriteTo(out);
	return out;
}
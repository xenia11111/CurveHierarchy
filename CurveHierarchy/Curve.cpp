#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

Vec3 Curve::GetDerivative(double t, double epsilon) const
{
	double t0 = t;
	double t1 = t + epsilon;
	return (GetValue(t1) - GetValue(t0)) / (t1 - t0);
}

std::ostream& operator << (std::ostream& out, std::shared_ptr<Curve> const& curve)
{
	curve->WriteTo(out);
	return out;
}
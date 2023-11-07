#pragma once
#include "Curve.h"

class Helix : public Curve
{
private:
	double _radius;
	double _step;
public:
	Helix(double radius, double step);
	virtual Vec3 GetValue(double t) const override;
	virtual void WriteTo(std::ostream& out) const override;
};
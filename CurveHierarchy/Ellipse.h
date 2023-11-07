#pragma once
#include <ostream>
#include "Curve.h"

class Ellipse : public Curve
{
private:
	double _radiusX;
	double _radiusY;
public:
	~Ellipse() = default;
	Ellipse(double radiusX, double radiusY);
	virtual Vec3 GetValue(double t) const override;
	virtual void WriteTo(std::ostream& out) const override;
};

#pragma once
#include "Curve.h"

#ifdef CURVEHIERARCHY_EXPORTS
#define CURVEHIERARCHY_API __declspec(dllexport)
#else
#define CURVEHIERARCHY_API __declspec(dllimport)
#endif

class Circle : public Curve
{
private:
	double _radius;
public:
	Circle(double);
	virtual Vec3 GetValue(double t) const override;
	CURVEHIERARCHY_API double getRadius() { return _radius; }
	virtual void WriteTo(std::ostream& out) const override;
};

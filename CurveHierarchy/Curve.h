#pragma once
#include <iostream>
#include "Vec3.h"
#include <random>
#include <map>
#include <string>

#ifdef CURVEHIERARCHY_EXPORTS
#define CURVEHIERARCHY_API __declspec(dllexport)
#else
#define CURVEHIERARCHY_API __declspec(dllimport)
#endif

class Curve
{
public:
	CURVEHIERARCHY_API virtual ~Curve() = default;
	CURVEHIERARCHY_API virtual Vec3 GetValue(double t) const = 0;
	CURVEHIERARCHY_API virtual void WriteTo(std::ostream& out) const = 0;
	CURVEHIERARCHY_API virtual Vec3 GetDerivative(double t, double epsilon) const;
};

CURVEHIERARCHY_API std::ostream& operator << (std::ostream& out, std::shared_ptr<Curve> const& curve);
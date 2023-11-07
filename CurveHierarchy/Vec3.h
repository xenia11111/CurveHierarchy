#pragma once
#include <ostream>
#ifdef CURVEHIERARCHY_EXPORTS
#define CURVEHIERARCHY_API __declspec(dllexport)
#else
#define CURVEHIERARCHY_API __declspec(dllimport)
#endif

struct Vec3
{
	double x;
	double y;
	double z;

	Vec3 operator -(const Vec3& other) const;

	Vec3 operator / (double coeff) const;

	void WriteTo(std::ostream& out) const;
};

CURVEHIERARCHY_API std::ostream& operator << (std::ostream& out, const Vec3& vec);
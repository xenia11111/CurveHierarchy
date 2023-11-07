#pragma once
#include <random>
#include "Curve.h"

#ifdef CURVEHIERARCHY_EXPORTS
#define CURVEHIERARCHY_API __declspec(dllexport)
#else
#define CURVEHIERARCHY_API __declspec(dllimport)
#endif

class CurveFactory
{
private:
	std::uniform_real_distribution<double> _radiusDistribution;
	std::uniform_real_distribution<double> _stepDistribution;
	std::mt19937& _mersenneGenerator;

public:

	enum class CurveType
	{
		Circle,
		Elipse,
		Helix
	};

	static inline std::uniform_int_distribution<int> typeDistribution_ =
		std::uniform_int_distribution<int>((int)CurveType::Circle,
										   (int)CurveType::Helix);


	CURVEHIERARCHY_API std::shared_ptr<Curve> CreateRandom();


	CurveFactory(double radiusLowerBound, 
				 double radiusUpperBound,
				 double stepLowerBound,
				 double stepUpperBound, 
				 std::mt19937& mersenneGenerator):
		 _mersenneGenerator(mersenneGenerator),
		_radiusDistribution(radiusLowerBound, radiusUpperBound),
		_stepDistribution(stepLowerBound, stepUpperBound)
	{
	}


};
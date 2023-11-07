#include "CurveFactory.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

std::shared_ptr<Curve> CurveFactory::CreateRandom()
{
	auto curveType = static_cast<CurveType>(typeDistribution_(_mersenneGenerator));
	switch (curveType)
	{
	case CurveType::Circle:
		return std::make_shared<Circle>(_radiusDistribution(_mersenneGenerator));
	case CurveType::Elipse:
		return std::make_shared<Ellipse>(_radiusDistribution(_mersenneGenerator),
										 _radiusDistribution(_mersenneGenerator)
										);
	case CurveType::Helix:
		return std::make_shared<Helix>(_radiusDistribution(_mersenneGenerator),
									   _stepDistribution(_mersenneGenerator));
	default:
		throw std::runtime_error("Curve type " + std::to_string((int)curveType) + "is not supported");
	}
}
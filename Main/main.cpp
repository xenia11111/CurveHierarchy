
#include "CurveHierarchy/CurveFactory.h"
#include "CurveHierarchy/Circle.h"
#include <execution>
#include <ranges>
#include <iostream>
#include <iomanip>

const double Pi = 3.14159265359;

constexpr double derivativeEpsilon = std::numeric_limits<double>::epsilon();
const double tValue = Pi * 0.25;
const uint8_t precision = 7;


const size_t CurvesNum = 16;
constexpr double radiusLowerBoundary = std::numeric_limits<double>::epsilon();
const double paramUpperBoundary = 2048;
const double stepLowerBoundary = -1024.0;
const double stepUpperBoundary = 1024.0;



int main()
{
	std::random_device rd;
	std::mt19937 generator(rd());



	CurveFactory curveFactory(radiusLowerBoundary, 
								paramUpperBoundary, 
								stepLowerBoundary, 
								stepUpperBoundary, 
								generator);

	std::vector<std::shared_ptr<Curve>> curves(CurvesNum);
	std::ranges::generate(curves, [&]() { return curveFactory.CreateRandom();});
	for (auto const& curve : curves)
	{
		std::cout << std::setprecision(precision) << "CurveParameters:\n" << curve  << "\n"
			<< "Value at t = " << tValue << " is " << curve->GetValue(tValue) << '\n'
			<< "Derivative at t = " << tValue << " is " << curve->GetDerivative(tValue, derivativeEpsilon) << "\n\n";
	}

	auto castCurveToCircle = [](auto&& curvePtr) { return std::dynamic_pointer_cast<Circle>(curvePtr);};
	auto isNotNull = [](auto&& circlePtr) { return circlePtr != nullptr;};

	std::vector<std::shared_ptr<Circle>> circles;
	std::ranges::copy(curves | std::views::transform(castCurveToCircle)
		| std::views::filter(isNotNull),
		std::back_inserter(circles));

	auto getRadius = [](auto&& circle) { return circle->getRadius(); };

	std::ranges::sort(circles, {}, getRadius);
	auto radii = circles | std::views::transform(getRadius);

	auto sum = std::reduce(std::execution::par_unseq,
		radii.begin(),
		radii.end(),
		0.0);

	std::cout << "Sum of radii = " << sum << '\n';
}
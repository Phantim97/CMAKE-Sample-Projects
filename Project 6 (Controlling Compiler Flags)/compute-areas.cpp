#include "geometry_circle.h"
#include "geometry_polygon.h"
#include "geometry_rhombus.h"
#include "geometry_square.h"

#include <cstdlib>
#include <iostream>

int main()
{
	double radius = 2.5293;
	double A_circle = geometry::area::circle(radius);
	std::cout << "A circle of radius: " << radius << " has an area of: " << A_circle << '\n';

	double nSides = 19;
	double side = 1.29312;
	double A_Polygon = geometry::area::polygon(nSides, side);
	std::cout << "A regular polygon with " << nSides << " sides of length " << side << " has an area of " << A_Polygon << '\n';

	double d1 = 5.0;
	double d2 = 7.8912;
	double A_rhombus = geometry::area::rhombus(d1, d2);
	std::cout << "A rhombus with a major diagonal of " << d1 << " and a minor diagonal of " << d2 << " has an area of " << A_rhombus << '\n';

	double l = 1.0;
	double A_square = geometry::area::square(l);
	std::cout << "A square with side length: " << l << " has an area of " << A_square << '\n';

	return 0;
}
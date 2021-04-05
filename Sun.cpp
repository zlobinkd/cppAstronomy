#include <Sun.h>
#include <cmath>

using std::cos;
using std::sin;
using std::acos;
using std::asin;
using std::atan;

void CSun::update()
{
	updateGeneral();
	SolarCoordinates = CVector( -cos( 2 * Pi * t / EarthYear ), -sin( 2 * Pi * t / EarthYear ), 0 );
}

CSun::CSun()
{
	t = getCurrentTime();
	update();
}

CVector CSun::findAzimutCoordinates() const
{
	return solarToAzimut( SolarCoordinates );
}

CVector CSun::findEqCoordinates() const
{
	return solarToEq( SolarCoordinates );
}

CVector CSun::findSolarCoordinates() const
{
	return SolarCoordinates;
}
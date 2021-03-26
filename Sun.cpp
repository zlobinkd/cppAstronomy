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

void CSun::changeTime( double step )
{
	t += step;
	update();
}

CVector CSun::findAzimutCoordinates()
{
	return solarToAzimut( SolarCoordinates );
}

CVector CSun::findEqCoordinates()
{
	return azimutToEq( solarToAzimut( SolarCoordinates ) );
}

CVector CSun::findSolarCoordinates()
{
	return SolarCoordinates;
}
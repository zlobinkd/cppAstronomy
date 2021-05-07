#include <Planet.h>
#include <cmath>

using std::sin;
using std::cos;

void CPlanet::update()
{
	updateGeneral();
	CTime tSun;
	tSun.day = 21;
	tSun.hour = 0;
	tSun.minute = 40;
	tSun.month = 5;
	tSun.year = 2018;
	double timeDiff = timeDifference( confrontation, tSun );
	double phase = 2 * Pi * timeDiff * ( 1 / EarthYear - 1 / planetYear );
	solarCoordinates = orbitRadius * CVector( cos( 2 * Pi * t / planetYear + phase ), sin( 2 * Pi * t / planetYear + phase ), 0 );
	solarCoordinates -= CVector( cos( 2 * Pi * t / EarthYear ), sin( 2 * Pi * t / EarthYear ), 0 );
	solarCoordinates /= abs( solarCoordinates );
 }

CVector CPlanet::findSolarCoordinates() const
{
	return solarCoordinates;
}

CVector CPlanet::findAzimutCoordinates() const
{
	return solarToAzimut( solarCoordinates );
}

CVector CPlanet::findEqCoordinates() const
{
	return solarToEq( solarCoordinates );
}
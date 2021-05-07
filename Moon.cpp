#include <Moon.h>
#include <cmath>

using std::cos;
using std::sin;
using std::acos;
using std::asin;
using std::atan;

void CMoon::update()
{
	updateGeneral();
	double cl1 = cos( l1 - 2 * Pi * t / MoonPrecessionPeriod );
	double sl1 = sin (l1 - 2 * Pi * t / MoonPrecessionPeriod );
	double cl0 = cos( l0 + 2 * Pi * t / MoonPrecessionPeriod );
	double sl0 = sin( l0 + 2 * Pi * t / MoonPrecessionPeriod );
	CMatrix U1 = CMatrix( CVector( cl1, -sl1, 0 ),
						CVector( sl1, cl1, 0 ),
						CVector( 0, 0, 1 ) );
	CMatrix U3 = CMatrix( CVector( cl0, -sl0, 0 ),
						CVector( sl0, cl0, 0 ),
						CVector( 0, 0, 1 ) );
	MoonTransformationMatrix = U3 * ( U2 * U1 );
	transpose( MoonTransformationMatrix );
	LunarCoordinates = CVector( cos( 2 * Pi * t / MoonYear ), sin( 2 * Pi * t / MoonYear ), 0 );
}

CMoon::CMoon()
{
	U2 = CMatrix( CVector( cos( l ), 0, sin( l ) ),
				CVector( 0, 1, 0 ),
				CVector( -sin( l ), 0, cos( l ) ) );
	t = getCurrentTime();
	update();
}

CVector CMoon::findSolarCoordinates() const
{
	return lunarToSolar();
}

CVector CMoon::findEqCoordinates() const
{
	return solarToEq( lunarToSolar() );
}

CVector CMoon::lunarToSolar() const
{
	return MoonTransformationMatrix * LunarCoordinates;
}

CVector CMoon::findAzimutCoordinates() const
{
	return solarToAzimut( lunarToSolar() );
}
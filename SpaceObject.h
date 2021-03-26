#pragma once

#include <cmath>
#include <Matrix.h>

using std::cos;
using std::sin;
using std::acos;
using std::asin;
using std::atan;

class CSpaceObject {
public:
	CSpaceObject();
	virtual CVector findAzimutCoordinates() = 0;
	virtual CVector findEqCoordinates() = 0;
	virtual CVector findSolarCoordinates() = 0;
	virtual void changeTime( double step ) = 0;

protected:
	// anywhere
	const double Pi = 3.14159265358979;
	const double Eclipse = 23 * Pi / 180;
	const double EarthRotationPeriod = 24;
	const double EarthYear = 365.25 * EarthRotationPeriod;

	// concrete location (to concern in constructor)
	double latitude = 55.5 * Pi / 180;
	double longtitude = 37.6 * Pi / 180;
	double timeZone = 3;
	double t;

	// planets
	const double VenusYear = 224.7 * EarthRotationPeriod;
	const double JupyterYear = 4332.6 * EarthRotationPeriod;
	const double SaturnYear = 10759 * EarthRotationPeriod;
	const double MarsYear = 686.98 * EarthRotationPeriod;

	// transforms
	CVector solarToAzimut( CVector decartCoordinates ) const;
	CVector azimutToSolar( CVector decartCoordinates ) const;
	CVector eqToAzimut( CVector hourCoordinates ) const;
	CVector azimutToEq( CVector decartCoordinates ) const;
	double getCurrentTime();
	void updateGeneral();

private:
	// other transforms
	CVector sphericalToDecart( CVector sphericalCoordinates ) const;
	CVector decartToSpherical( CVector decartCoordinates ) const;

	// other constants
	CMatrix EarthRotationTransferMatrix;
	CMatrix EarthYearTransferMatrix;
	const CMatrix EclipseTransferMatrix = CMatrix( CVector( cos( Eclipse ), 0, -sin( Eclipse ) ),
											CVector( 0, 1, 0 ),
											CVector( sin( Eclipse ), 0, cos( Eclipse ) ) );
	const CMatrix LatitudeTransferMatrix = CMatrix( CVector( 1, 0, 0 ),
											CVector( 0, sin( latitude ), -cos( latitude ) ),
											CVector( 0, cos( latitude ), sin( latitude ) ) );
};
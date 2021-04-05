#pragma once

#include <Matrix.h>

class CSpaceObject {
public:
	CSpaceObject();
	virtual CVector findAzimutCoordinates() const = 0;
	virtual CVector findEqCoordinates() const = 0;
	virtual CVector findSolarCoordinates() const = 0;
	void changeTime( double step );

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

	// transforms
	CVector solarToAzimut( CVector decartCoordinates ) const;
	CVector azimutToSolar( CVector decartCoordinates ) const;
	CVector eqToAzimut( CVector hourCoordinates ) const;
	CVector azimutToEq( CVector decartCoordinates ) const;
	CVector eqToSolar( CVector hourCoordinates ) const;
	CVector solarToEq( CVector decartCoordinates ) const;
	double getCurrentTime();
	void updateGeneral();
	virtual void update() = 0;

private:
	// other transforms
	CVector sphericalToDecart( CVector sphericalCoordinates ) const;
	CVector decartToSpherical( CVector decartCoordinates ) const;

	// other constants
	CMatrix EarthRotationTransformationMatrix;
	CMatrix EarthYearTransformationMatrix;
	CMatrix EclipseTransformationMatrix;
	CMatrix LatitudeTransformationMatrix;
};
#pragma once

#include "Matrix.h"

class CAstronomicalObject {
public:
	CAstronomicalObject();
	virtual CVector findAzimuthCoordinates() const = 0;
	virtual CVector findEqCoordinates() const = 0;
	virtual CVector findSolarCoordinates() const = 0;
	void changeTime(double step);

protected:
	// anywhere
	const double m_pi = 3.14159265358979;
	const double m_eclipse = 23.0 * m_pi / 180;
	const double m_earthRotationPeriod = 24.0;
	const double m_earthOrbitPeriod = 365.25 * m_earthRotationPeriod;

	// location
	double m_latitude = 50.8 * m_pi / 180;
	double m_longtitude = 6.07 * m_pi / 180;
	int m_timezone = 1;

	// current physical time, calculated as 
	// the time difference in hours
	// between the current timestamp and
	// the astronomical midnight of
	// 2018 summer solstice
	double m_t = 0.0;

	// transforms
	// azimuth:		local azimuth coordinates
	// 
	// solar:		date-invariant XYZ-coordinates 
	//				with the Earth as the origin 
	//				(XY-plane is the ecliptic plane) 
	//
	// eq:			local equatorial coordinates
	//				(date-variant)
	CVector solarToAzimuth(CVector decartCoordinates) const;
	CVector azimuthToSolar(CVector decartCoordinates) const;
	CVector eqToAzimuth(CVector hourCoordinates) const;
	CVector azimuthToEq(CVector decartCoordinates) const;
	CVector eqToSolar(CVector hourCoordinates) const;
	CVector solarToEq(CVector decartCoordinates) const;
	double getCurrentTime();
	void updateGeneral();
	virtual void update() = 0;

private:
	// other transforms
	CVector sphericalToDecart(CVector sphericalCoordinates) const;
	CVector decartToSpherical(CVector decartCoordinates) const;

	// other constants
	CMatrix m_earthRotationTransformationMatrix;
	CMatrix m_earthOrbitTransformationMatrix;
	CMatrix m_eclipseTransformationMatrix;
	CMatrix m_latitudeTransformationMatrix;
};
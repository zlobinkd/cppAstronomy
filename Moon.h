#pragma once

#include <SpaceObject.h>

class CMoon : public CSpaceObject {
public:
	CMoon();
	CVector findAzimutCoordinates() const;
	CVector findEqCoordinates() const;
	CVector findSolarCoordinates() const;
private:
	void update();
	const double l = 5.14 * Pi / 180;
	const double l0 = 160 * Pi / 180;
	const double l1 = 122 * Pi / 180;
	const double MoonYear = 27.321661 * EarthRotationPeriod;
	const double MoonPrecessionPeriod = 18.5996 * EarthYear;
	CVector lunarToSolar() const;
	CVector LunarCoordinates;
	CMatrix U2;
	CMatrix MoonTransformationMatrix;
};
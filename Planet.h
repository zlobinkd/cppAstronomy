#pragma once

#include <SpaceObject.h>
#include <myTime.h>

class CPlanet : public CSpaceObject {
public:
	CVector findAzimutCoordinates() const;
	CVector findEqCoordinates() const;
	CVector findSolarCoordinates() const;
protected:
	void update();
	CTime confrontation;
	double planetYear;
	double orbitRadius;
	CVector solarCoordinates;
};
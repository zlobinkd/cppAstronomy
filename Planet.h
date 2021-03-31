#pragma once

#include <SpaceObject.h>
#include <myTime.h>

class CPlanet : public CSpaceObject {
public:
	CVector findAzimutCoordinates();
	CVector findEqCoordinates();
	CVector findSolarCoordinates();
	void changeTime( double step );
protected:
	void update();
	CTime confrontation;
	double planetYear;
	double orbitRadius;
	CVector solarCoordinates;
};
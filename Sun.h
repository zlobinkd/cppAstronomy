#pragma once

#include <SpaceObject.h>

class CSun : public CSpaceObject {
public:
	CSun();
	CVector findAzimutCoordinates();
	CVector findEqCoordinates();
	CVector findSolarCoordinates();
	void changeTime( double step );
private:
	void update();
	CVector SolarCoordinates;
};
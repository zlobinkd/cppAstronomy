#pragma once

#include <SpaceObject.h>

class CSun : public CSpaceObject {
public:
	CSun();
	CVector findAzimutCoordinates() const;
	CVector findEqCoordinates() const;
	CVector findSolarCoordinates() const;
private:
	void update();
	CVector SolarCoordinates;
};
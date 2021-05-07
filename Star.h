#pragma once

#include <SpaceObject.h>

class CStar : public CSpaceObject {
public:
	CStar();
	CStar( CVector _eqCoordinates );
	CVector findAzimutCoordinates() const;
	CVector findEqCoordinates() const;
	CVector findSolarCoordinates() const;
protected:
	void update();
	CVector eqCoordinates;
};
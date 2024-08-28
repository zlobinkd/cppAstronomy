#pragma once

#include "AstronomicalObject.h"

class CStar : public CAstronomicalObject {
public:
	CStar(CVector eqCoordinates);
	virtual CVector findAzimutCoordinates() const override;
	virtual CVector findEqCoordinates() const override;
	virtual CVector findSolarCoordinates() const override;
private:
	virtual void update() override;
	CVector m_eqCoordinates;
};
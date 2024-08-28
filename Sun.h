#pragma once

#include "AstronomicalObject.h"

class CSun : public CAstronomicalObject {
public:
	CSun();
	virtual CVector findAzimuthCoordinates() const override;
	virtual CVector findEqCoordinates() const override;
	virtual CVector findSolarCoordinates() const override;
private:
	virtual void update() override;
	CVector m_solarCoordinates;
};
#pragma once

#include "AstronomicalObject.h"
#include <ctime>

class CPlanet : public CAstronomicalObject {
public:
	CPlanet(std::tm confrontation, double orbitPeriod, double orbitRadius);
	virtual CVector findAzimutCoordinates() const override;
	virtual CVector findEqCoordinates() const override;
	virtual CVector findSolarCoordinates() const override;
private:
	virtual void update() override;

	// local confrontation datetime
	std::tm m_confrontation;

	// orbit period in hours
	double m_orbitPeriod;

	// orbit radius in astronomical units
	double m_orbitRadius;

	CVector m_solarCoordinates;
};
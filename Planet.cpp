#include "Planet.h"
#include <cmath>
#include <stdexcept>

using std::sin;
using std::cos;

CPlanet::CPlanet(std::tm confrontation, double orbitPeriod, double orbitRadius) {
	m_confrontation = confrontation;
	m_orbitPeriod = orbitPeriod;
	m_orbitRadius = orbitRadius;
	if (m_orbitPeriod == 0.0) {
		throw new std::invalid_argument("Attempted to create a planet with a zero orbital rotation period");
	}
	if (m_orbitRadius <= 0.0) {
		throw new std::invalid_argument("Attempted to create a planet with an invalid orbital radius");
	}
	update();
}

void CPlanet::update()
{
	updateGeneral();
	// initialize solstice
	std::tm solstice2018{};
	solstice2018.tm_year = 2018 - 1900;
	solstice2018.tm_mday = 22;
	solstice2018.tm_hour = 0;
	solstice2018.tm_min = 0;
	solstice2018.tm_mon = 5;

	// get solstice for current location
	time_t localSolstice2018seconds = mktime(&solstice2018) +
		(time_t)((m_timezone * 15 * m_pi / 180 - m_longtitude) * (3600 * 24) / (2 * m_pi));
	std::tm localSolstice2018{};
	localtime_s(&localSolstice2018, &localSolstice2018seconds);

	double timeDiff = (mktime(&m_confrontation) - mktime(&localSolstice2018)) / 3600.0;
	double phase = 2 * m_pi * timeDiff * (1 / m_earthOrbitPeriod - 1 / m_orbitPeriod);
	m_solarCoordinates = m_orbitRadius * CVector(cos(2 * m_pi * m_t / m_orbitPeriod + phase), 
											sin(2 * m_pi * m_t / m_orbitPeriod + phase), 0);

	m_solarCoordinates -= CVector(cos(2 * m_pi * m_t / m_earthOrbitPeriod), sin(2 * m_pi * m_t / m_earthOrbitPeriod), 0);

	if (abs(m_solarCoordinates) == 0.0) {
		throw new std::exception("A planet has crashed into the Earth!");
	}

	m_solarCoordinates /= abs(m_solarCoordinates);
}

CVector CPlanet::findSolarCoordinates() const
{
	return m_solarCoordinates;
}

CVector CPlanet::findAzimutCoordinates() const
{
	return solarToAzimut(m_solarCoordinates);
}

CVector CPlanet::findEqCoordinates() const
{
	return solarToEq(m_solarCoordinates);
}
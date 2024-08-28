#include "Sun.h"
#include <cmath>

using std::cos;
using std::sin;
using std::acos;
using std::asin;
using std::atan;

void CSun::update()
{
	updateGeneral();
	m_solarCoordinates = CVector(-cos(2 * m_pi * m_t / m_earthOrbitPeriod), -sin(2 * m_pi * m_t / m_earthOrbitPeriod), 0);
}

CSun::CSun()
{
	m_t = getCurrentTime();
	update();
}

CVector CSun::findAzimuthCoordinates() const
{
	return solarToAzimuth(m_solarCoordinates);
}

CVector CSun::findEqCoordinates() const
{
	return solarToEq(m_solarCoordinates);
}

CVector CSun::findSolarCoordinates() const
{
	return m_solarCoordinates;
}
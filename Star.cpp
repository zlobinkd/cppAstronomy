#include "Star.h"

void CStar::update()
{
	updateGeneral();
}

CStar::CStar(CVector eqCoordinates)
{
	m_eqCoordinates = eqCoordinates;
	m_t = getCurrentTime();
	update();
}

CVector CStar::findAzimuthCoordinates() const
{
	return eqToAzimuth(m_eqCoordinates);
}

CVector CStar::findEqCoordinates() const
{
	return m_eqCoordinates;
}

CVector CStar::findSolarCoordinates() const
{
	return eqToSolar(m_eqCoordinates);
}
#include <Star.h>

void CStar::update()
{
	updateGeneral();
}

CStar::CStar()
{
	t = getCurrentTime();
	update();
}

CVector CStar::findAzimutCoordinates() const
{
	return eqToAzimut( eqCoordinates );
}

CVector CStar::findEqCoordinates() const
{
	return eqCoordinates;
}

CVector CStar::findSolarCoordinates() const
{
	return eqToSolar( eqCoordinates );
}
#include <Jupyter.h>

CJupyter::CJupyter()
{
	orbitRadius = 5.2;
	planetYear = 4332.6 * EarthRotationPeriod;
	confrontation = CTime();
	confrontation.year = 2020;
	confrontation.month = 6;
	confrontation.day = 13;
	confrontation.hour = 0;
	confrontation.minute = 0;
	update();
}
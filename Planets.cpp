#include <Planets.h>

CMars::CMars()
{
	orbitRadius = 0.723;
	planetYear = 224.7 * EarthRotationPeriod;
	confrontation = CTime();
	confrontation.year = 2020;
	confrontation.month = 5;
	confrontation.day = 2;
	confrontation.hour = 20;
	confrontation.minute = 5;
	update();
}

CSaturn::CSaturn()
{
	orbitRadius = 0.723;
	planetYear = 224.7 * EarthRotationPeriod;
	confrontation = CTime();
	confrontation.year = 2020;
	confrontation.month = 5;
	confrontation.day = 2;
	confrontation.hour = 20;
	confrontation.minute = 5;
	update();
}

CVenus::CVenus()
{
	orbitRadius = 0.723;
	planetYear = 224.7 * EarthRotationPeriod;
	confrontation = CTime();
	confrontation.year = 2020;
	confrontation.month = 5;
	confrontation.day = 2;
	confrontation.hour = 20;
	confrontation.minute = 5;
	update();
}

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
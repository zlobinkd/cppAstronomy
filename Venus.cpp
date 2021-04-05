#include <Venus.h>

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
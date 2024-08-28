#include "AstronomicalObject.h"
#include <ctime>
#include <cmath>
#include <stdexcept>

using std::cos;
using std::sin;
using std::acos;
using std::asin;
using std::atan;

double CAstronomicalObject::getCurrentTime()
{
	// system: get current time in seconds
	std::time_t currentTime = std::time(0);

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

	// calculate the time difference in hours
	int timeDifference = int(currentTime) - int(mktime(&localSolstice2018));
	return double(timeDifference) / 3600;
}

void CAstronomicalObject::updateGeneral()
{
	double cw = cos(2 * m_pi * m_t / m_earthRotationPeriod);
	double sw = sin(2 * m_pi * m_t / m_earthRotationPeriod);
	m_earthRotationTransformationMatrix = CMatrix(CVector(-sw, -cw, 0),
												  CVector(cw,  -sw, 0),
												  CVector(0,    0,  1));
	double cv = cos(2 * m_pi * m_t / m_earthOrbitPeriod);
	double sv = sin(2 * m_pi * m_t / m_earthOrbitPeriod);
	m_earthOrbitTransformationMatrix = CMatrix(CVector(cv, -sv, 0),
											   CVector(sv, cv,  0),
											   CVector(0,   0,  1));
}

CAstronomicalObject::CAstronomicalObject()
{
	// set the matrices and the time
	m_eclipseTransformationMatrix = CMatrix(CVector(cos(m_eclipse), 0, -sin(m_eclipse)),
										    CVector(       0,       1,        0),
										    CVector(sin(m_eclipse), 0, cos(m_eclipse)));

	m_latitudeTransformationMatrix = CMatrix(CVector(1,        0,               0),
										     CVector(0, sin(m_latitude), -cos(m_latitude)),
										     CVector(0, cos(m_latitude), sin(m_latitude)));
	m_t = getCurrentTime();
	updateGeneral();
}

// transforms
CVector CAstronomicalObject::sphericalToDecart(CVector sphericalCoordinates) const
{
	sphericalCoordinates = sphericalCoordinates * (m_pi / 180);
	double phi = sphericalCoordinates.m_value[0];
	double theta = sphericalCoordinates.m_value[1];
	double x = sin(phi) * cos(theta);
	double y = cos(phi) * cos(theta);
	double z = sin(theta);
	return CVector(x, y, z);
}

CVector CAstronomicalObject::decartToSpherical(CVector decartCoordinates) const
{
	if (abs(decartCoordinates) == 0.0) {
		throw new std::invalid_argument("Coordinates conversion encountered vector of zeros");
	}

	decartCoordinates /= abs(decartCoordinates);

	double x = decartCoordinates.m_value[0];
	double y = decartCoordinates.m_value[1];
	double z = decartCoordinates.m_value[2];
	double theta = asin(z);
	double phi;
	if (cos(theta) != 0.0) {
		double sinf = x / cos(theta);
		double cosf = y / cos(theta);
		if (sinf > 0) {
			phi = acos(cosf);
		}
		else if (cosf > 0) {
			phi = 2 * m_pi + asin(sinf);
		}
		else {
			phi = 2 * m_pi - acos(cosf);
		}
	}
	else {
		phi = 0;
	}
	return CVector(phi * 180 / m_pi, theta * 180 / m_pi, 0);
}

CVector CAstronomicalObject::solarToAzimut(CVector decartCoordinates) const
{
	return decartToSpherical(m_latitudeTransformationMatrix * 
						m_earthRotationTransformationMatrix * 
						m_earthOrbitTransformationMatrix * 
						m_eclipseTransformationMatrix * decartCoordinates);
}

CVector CAstronomicalObject::azimutToSolar(CVector decartCoordinates) const
{
	CMatrix transformationMatrix = m_latitudeTransformationMatrix * 
								m_earthRotationTransformationMatrix * 
								m_earthOrbitTransformationMatrix * 
								m_eclipseTransformationMatrix;

	// unitary inverse
	transpose(transformationMatrix);
	return transformationMatrix * sphericalToDecart(decartCoordinates);
}

CVector CAstronomicalObject::eqToAzimut(CVector hourCoordinates) const
{
	hourCoordinates.m_value[0] *= -15;
	CVector decartCoordinates = sphericalToDecart(hourCoordinates);
	CMatrix transformationMatrix = m_eclipseTransformationMatrix;

	// unitary inverse
	transpose(transformationMatrix);
	return solarToAzimut(transformationMatrix * decartCoordinates);
}

CVector CAstronomicalObject::azimutToEq(CVector decartCoordinates) const
{
	CVector r = m_eclipseTransformationMatrix * azimutToSolar(decartCoordinates);
	CVector angles = decartToSpherical(r);
	angles.m_value[0] /= -15;
	if (angles.m_value[0] >= 24 || angles.m_value[0] < 0) {
		angles.m_value[0] = angles.m_value[0] + 24 * round((12 - angles.m_value[0]) / 24);
	}
	return angles;
}

void CAstronomicalObject::changeTime(double step)
{
	m_t += step;
	update();
}

CVector CAstronomicalObject::eqToSolar(CVector hourCoordinates) const
{
	hourCoordinates.m_value[0] *= -15;
	CVector decartCoordinates = sphericalToDecart(hourCoordinates);
	CMatrix transformationMatrix = m_eclipseTransformationMatrix;
	transpose(transformationMatrix);
	return transformationMatrix * decartCoordinates;
}

CVector CAstronomicalObject::solarToEq(CVector decartCoordinates) const
{
	CVector r = m_eclipseTransformationMatrix * decartCoordinates;
	CVector angles = decartToSpherical(r);
	angles.m_value[0] /= -15;
	if (angles.m_value[0] >= 24 || angles.m_value[0] < 0) {
		angles.m_value[0] = angles.m_value[0] + 24 * round((12 - angles.m_value[0]) / 24);
	}
	return angles;
}
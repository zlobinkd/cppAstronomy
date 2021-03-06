#include <SpaceObject.h>
#include <ctime>
#include <cmath>

using std::cos;
using std::sin;
using std::acos;
using std::asin;
using std::atan;

double CSpaceObject::getCurrentTime()
{
	std::time_t currentTime = std::time( 0 );
	std::tm tSun{};
	tSun.tm_year = 118;
	tSun.tm_mday = 22;
	tSun.tm_hour = 0;
	tSun.tm_min = 40;
	tSun.tm_mon = 5;
	int timeDifference = int( currentTime ) - int( mktime( &tSun ) );
	return double( timeDifference ) / 3600;
}

void CSpaceObject::updateGeneral()
{
	double cw = cos( 2 * Pi * t / EarthRotationPeriod );
	double sw = sin( 2 * Pi * t / EarthRotationPeriod );
	EarthRotationTransformationMatrix = CMatrix( CVector( -sw, -cw, 0 ),
										CVector( cw, -sw, 0 ),
										CVector( 0, 0, 1 ) );
	double cv = cos( 2 * Pi * t / EarthYear );
	double sv = sin( 2 * Pi * t / EarthYear );
	EarthYearTransformationMatrix = CMatrix( CVector( cv, -sv, 0 ),
									CVector( sv, cv, 0 ),
									CVector( 0, 0, 1 ) );
}

CSpaceObject::CSpaceObject()
{
	// установить часы и положение по умолчанию
	EclipseTransformationMatrix = CMatrix( CVector( cos( Eclipse ), 0, -sin( Eclipse ) ),
									CVector( 0, 1, 0 ),
									CVector( sin( Eclipse ), 0, cos( Eclipse ) ) );
	LatitudeTransformationMatrix = CMatrix( CVector( 1, 0, 0 ),
									CVector( 0, sin( latitude ), -cos( latitude ) ),
									CVector( 0, cos( latitude ), sin( latitude ) ) );
	t = getCurrentTime();
	updateGeneral();
}

// transforms
CVector CSpaceObject::sphericalToDecart( CVector sphericalCoordinates ) const
{
	sphericalCoordinates = sphericalCoordinates * (Pi / 180);
	double phi = sphericalCoordinates.value[0];
	double theta = sphericalCoordinates.value[1];
	double x = sin( phi ) * cos( theta );
	double y = cos( phi ) * cos( theta );
	double z = sin( theta );
	return CVector( x, y, z );
}

CVector CSpaceObject::decartToSpherical( CVector decartCoordinates ) const
{
	double x = decartCoordinates.value[0];
	double y = decartCoordinates.value[1];
	double z = decartCoordinates.value[2];
	double theta = asin( z );
	double phi;
	if( abs( z ) < 1 ) {
		double sinf = x / cos( theta );
		double cosf = y / cos( theta );
		if( sinf > 0 ) {
			phi = acos( cosf );
		} else if( cosf > 0 ) {
			phi = 2 * Pi + asin( sinf );
		} else {
			phi = 2 * Pi - acos( cosf );
		}
	} else {
		phi = 0;
	}
	return CVector( phi * 180 / Pi, theta * 180 / Pi, 0 );
}

CVector CSpaceObject::solarToAzimut( CVector decartCoordinates ) const
{
	return decartToSpherical( LatitudeTransformationMatrix * EarthRotationTransformationMatrix * EarthYearTransformationMatrix * EclipseTransformationMatrix * decartCoordinates );
}

CVector CSpaceObject::azimutToSolar( CVector decartCoordinates ) const
{
	CMatrix TransformationMatrix = LatitudeTransformationMatrix * EarthRotationTransformationMatrix * EarthYearTransformationMatrix * EclipseTransformationMatrix;
	transpose( TransformationMatrix );
	return TransformationMatrix * sphericalToDecart( decartCoordinates );
}

CVector CSpaceObject::eqToAzimut( CVector hourCoordinates ) const
{
	hourCoordinates.value[0] *= -15;
	CVector decartCoordinates = sphericalToDecart( hourCoordinates );
	CMatrix transformationMatrix = EclipseTransformationMatrix;
	transpose( transformationMatrix );
	return solarToAzimut( transformationMatrix * decartCoordinates );
}

CVector CSpaceObject::azimutToEq( CVector decartCoordinates ) const
{
	CVector r = EclipseTransformationMatrix * azimutToSolar( decartCoordinates );
	CVector angles = decartToSpherical( r );
	angles.value[0] /= -15;
	if( angles.value[0] >= 24 || angles.value[0] < 0 ) {
		angles.value[0] = angles.value[0] + 24 * round( ( 12 - angles.value[0] ) / 24 );
	}
	return angles;
}

void CSpaceObject::changeTime( double step )
{
	t += step;
	update();
}

CVector CSpaceObject::eqToSolar( CVector hourCoordinates ) const
{
	hourCoordinates.value[0] *= -15;
	CVector decartCoordinates = sphericalToDecart( hourCoordinates );
	CMatrix transformationMatrix = EclipseTransformationMatrix;
	transpose( transformationMatrix );
	return transformationMatrix * decartCoordinates;
}

CVector CSpaceObject::solarToEq( CVector decartCoordinates ) const
{
	CVector r = EclipseTransformationMatrix * decartCoordinates;
	CVector angles = decartToSpherical( r );
	angles.value[0] /= -15;
	if( angles.value[0] >= 24 || angles.value[0] < 0 ) {
		angles.value[0] = angles.value[0] + 24 * round( ( 12 - angles.value[0] ) / 24 );
	}
	return angles;
}
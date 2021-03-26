#include <Vector.h>

CVector::CVector()
{
	value[0] = 0;
	value[1] = 0;
	value[2] = 0;
}

CVector::CVector( double _value[3] )
{
	value[0] = _value[0];
	value[1] = _value[1];
	value[2] = _value[2];
}

CVector::CVector( double v1, double v2, double v3 )
{
	value[0] = v1;
	value[1] = v2;
	value[2] = v3;
}

CVector operator*( double d, CVector v )
{
	CVector v0 = CVector();
	int i = 0;
	for( ; i < 3; ++i ) {
		v0.value[i] = v.value[i] * d;
	}
	return v0;
}

CVector operator*( CVector v, double d )
{
	CVector v0 = CVector();
	int i = 0;
	for( ; i < 3; ++i ) {
		v0.value[i] = v.value[i] * d;
	}
	return v0;
}
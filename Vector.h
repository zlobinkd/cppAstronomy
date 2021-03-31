#pragma once

struct CVector {
	CVector();
	CVector( double _value[3] );
	CVector( double v1, double v2, double v3 );
	double value[3];
};

CVector operator*( double d, CVector v );
CVector operator*( CVector v, double d );
CVector operator+( CVector v1, CVector v2 );
CVector operator-( CVector v1, CVector v2 );
double abs( CVector v );
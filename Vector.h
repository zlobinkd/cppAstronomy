#pragma once

#include <array>

struct CVector {
	CVector();
	CVector( std::array<double, 3> _value );
	CVector( double v1, double v2, double v3 );
	std::array<double, 3> m_value;
};

CVector operator*( double d, CVector v );
CVector operator*( CVector v, double d );
CVector operator+( CVector v1, CVector v2 );
CVector operator-( CVector v1, CVector v2 );
double abs( CVector v );
CVector operator*=( CVector& v, double d );
CVector operator-=( CVector& v1, CVector v2 );
CVector operator/=( CVector& v1, double d );
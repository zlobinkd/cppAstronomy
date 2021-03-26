#pragma once

#include <Vector.h>

struct CMatrix {
	CMatrix();
	CMatrix( CVector v1, CVector v2, CVector v3 );
	double value[3][3];
};

void transpose( CMatrix& matr );
CVector operator*( CMatrix m, CVector v );
CMatrix operator*( CMatrix m1, CMatrix m2 );
CMatrix operator*( double d, CMatrix m );
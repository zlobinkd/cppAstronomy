﻿#include <Matrix.h>

CMatrix::CMatrix()
{
	for ( int i = 0; i < 3; ++i ) {
		for ( int j = 0; j < 3; ++j ) {
			value[i][j] = 0;
		}
	}
}

CMatrix::CMatrix( CVector v1, CVector v2, CVector v3 )
{
	for( int i = 0; i < 3; ++i ) {
		value[i][0] = v1.value[i];
	}
	for( int i = 0; i < 3; ++i ) {
		value[i][1] = v2.value[i];
	}
	for( int i = 0; i < 3; ++i ) {
		value[i][2] = v3.value[i];
	}
}

void transpose( CMatrix& matr )
{
	double temp;
	for( int i = 0; i < 2; ++i ) {
		for( int j = i + 1; j < 3; ++j ) {
			temp = matr.value[i][j];
			matr.value[i][j] = matr.value[j][i];
			matr.value[j][i] = temp;
		}
	}
}

CVector operator*( CMatrix m, CVector v )
{
	CVector v0 = CVector();
	for( int i = 0; i < 3; ++i ) {
		for( int j = 0; j < 3; ++j ) {
			v0.value[i] += m.value[i][j] * v.value[j];
		}
	}
	return v0;
}

CMatrix operator*( CMatrix m1, CMatrix m2 )
{
	CMatrix m = CMatrix();
	for( int i = 0; i < 3; ++i ) {
		for( int j = 0; j < 3; ++j ) {
			for( int k = 0; k < 3; ++k ) {
				m.value[i][j] += m1.value[i][k] * m2.value[k][j];
			}
		}
	}
	return m;
}

CMatrix operator*( double d, CMatrix m )
{
	CMatrix m0 = CMatrix();
	for( int i = 0; i < 3; ++i ) {
		for( int j = 0; j < 3; ++j ) {
			m0.value[i][j] = m.value[i][j] * d;
		}
	}
	return m0;
}

CMatrix operator*=( CMatrix& m1, CMatrix m2 )
{
	CMatrix m = CMatrix();
	for( int i = 0; i < 3; ++i ) {
		for( int j = 0; j < 3; ++j ) {
			for( int k = 0; k < 3; ++k ) {
				m.value[i][j] += m1.value[i][k] * m2.value[k][j];
			}
		}
	}
	return m;
}

CMatrix operator*=( CMatrix& m, double d )
{
	for( int i = 0; i < 3; ++i ) {
		for( int j = 0; j < 3; ++j ) {
			m.value[i][j] *= d;
		}
	}
	return m;
}
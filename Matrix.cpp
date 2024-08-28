#include "Matrix.h"

CMatrix::CMatrix()
{
	for (int i = 0; i < 3; ++i ) {
		for (int j = 0; j < 3; ++j ) {
			m_value[i][j] = 0;
		}
	}
}

CMatrix::CMatrix( CVector v1, CVector v2, CVector v3 )
{
	for(int i = 0; i < 3; ++i ) {
		m_value[i][0] = v1.m_value[i];
	}
	
	for(int i = 0; i < 3; ++i ) {
		m_value[i][1] = v2.m_value[i];
	}
	
	for(int i = 0; i < 3; ++i ) {
		m_value[i][2] = v3.m_value[i];
	}
}

void transpose( CMatrix& matr )
{
	double temp;
	for(int i = 0; i < 2; ++i ) {
		for(int j = i + 1; j < 3; ++j ) {
			temp = matr.m_value[i][j];
			matr.m_value[i][j] = matr.m_value[j][i];
			matr.m_value[j][i] = temp;
		}
	}
}

CVector operator*( CMatrix m, CVector v )
{
	CVector v0 = CVector();
	for(int i = 0; i < 3; ++i ) {
		for(int j = 0; j < 3; ++j ) {
			v0.m_value[i] += m.m_value[i][j] * v.m_value[j];
		}
	}
	return v0;
}

CMatrix operator*( CMatrix m1, CMatrix m2 )
{
	CMatrix m = CMatrix();
	for(int i = 0; i < 3; ++i ) {
		for(int j = 0; j < 3; ++j ) {
			for(int k = 0; k < 3; ++k ) {
				m.m_value[i][j] += m1.m_value[i][k] * m2.m_value[k][j];
			}
		}
	}
	return m;
}

CMatrix operator*( double d, CMatrix m )
{
	CMatrix m0 = CMatrix();
	for(int i = 0; i < 3; ++i ) {
		for(int j = 0; j < 3; ++j ) {
			m0.m_value[i][j] = m.m_value[i][j] * d;
		}
	}
	return m0;
}

CMatrix operator*=( CMatrix& m1, CMatrix m2 )
{
	m1 = m1 * m2;
	return m1;
}

CMatrix operator*=( CMatrix& m, double d )
{
	m = d * m;
	return m;
}
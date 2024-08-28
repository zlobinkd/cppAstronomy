#include "Vector.h"
#include <cmath>
#include <stdexcept>

using std::pow;

CVector::CVector()
{
	m_value[0] = 0;
	m_value[1] = 0;
	m_value[2] = 0;
}

CVector::CVector(std::array<double, 3> _value)
{
	m_value[0] = _value[0];
	m_value[1] = _value[1];
	m_value[2] = _value[2];
}

CVector::CVector(double v1, double v2, double v3)
{
	m_value[0] = v1;
	m_value[1] = v2;
	m_value[2] = v3;
}

CVector operator*(double d, CVector v)
{
	CVector v0 = CVector();
	for (int i = 0; i < 3; ++i) {
		v0.m_value[i] = v.m_value[i] * d;
	}
	return v0;
}

CVector operator*(CVector v, double d)
{
	return d * v;
}

CVector operator+(CVector v1, CVector v2)
{
	CVector v0 = CVector();
	for (int i = 0; i < 3; ++i) {
		v0.m_value[i] = v1.m_value[i] + v2.m_value[i];
	}
	return v0;
}

CVector operator-(CVector v1, CVector v2)
{
	return v1 + (-1) * v2;
}

double abs(CVector v)
{
	double s = 0;
	for (int i = 0; i < 3; ++i) {
		s += pow(v.m_value[i], 2);
	}
	return pow(s, 0.5);
}

CVector operator*=(CVector& v, double d)
{
	v = d * v;
	return v;
}

CVector operator-=(CVector& v1, CVector v2)
{
	v1 = v1 - v2;
	return v1;
}

CVector operator/=(CVector& v, double d)
{
	if (d == 0) {
		throw new std::invalid_argument("CVector class encountered division by zero.");
	}
	
	v = v * (1 / d);
	return v;
}
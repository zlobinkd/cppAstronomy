#pragma once


struct CTime {
	int year;
	int month;
	int day;
	int hour;
	int minute;
};

double timeDifference( CTime t2, CTime t1 );
bool operator>( CTime t2, CTime t1 );
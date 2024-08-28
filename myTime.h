#pragma once


struct CTime {
	int year;
	int month;
	int day;
	int hour;
	int minute;
};

// get time difference in hours
double timeDifference( CTime t2, CTime t1 );

// check the timestamps sequence
bool operator>( CTime t2, CTime t1 );
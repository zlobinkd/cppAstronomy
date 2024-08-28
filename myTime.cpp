#include "myTime.h"

bool operator>( CTime t2, CTime t1 )
{
	if( t2.year > t1.year ) {
		return true;
	} else if( t2.year == t1.year && t2.month > t1.month ) {
		return true;
	} else if( t2.month == t1.month && t2.day > t1.day ) {
		return true;
	} else if( t2.day == t1.day && t2.minute > t1.minute ) {
		return true;
	}
	return false;
}



double timeDifference( CTime t2, CTime t1 )
{
	int months_n[12];
	int months_v[12];
	months_n[0] = 31;
	months_n[1] = 28;
	months_n[2] = 31;
	months_n[3] = 30;
	months_n[4] = 31;
	months_n[5] = 30;
	months_n[6] = 31;
	months_n[7] = 31;
	months_n[8] = 30;
	months_n[9] = 31;
	months_n[10] = 30;
	months_n[11] = 31;
	for(int i = 0; i < 12; ++i ) {
		months_v[i] = months_n[i];
	}
	months_v[1] = 29;
	if( t2 > t1 ) {
		double monthlyHours = static_cast<double>( t2.day - t1.day ) * 24 + static_cast<double>( t2.hour - t1.hour ) + static_cast<double>( t2.minute - t1.minute ) / 60;
		t1.day = 0;
		t2.day = 0;
		t1.hour = 0;
		t2.hour = 0;
		t1.minute = 0;
		t2.minute = 0;
		while( t2 > t1 ) {
			if( t2.month > 0 ) {
				t2.month -= 1;
				if( t2.year % 4 == 0 ) {
					monthlyHours += static_cast<double>( 24 * months_v[t2.month] );
				} else {
					monthlyHours += static_cast<double>( 24 * months_n[t2.month] );
				}
			} else {
				t2.month += 11;
				t2.year -= 1;
				monthlyHours += static_cast<double>( 24 * months_n[t2.month] );
			}
		}
		return monthlyHours;
	} else {
		return 0;
	}
}
#include <Astronomy.h>
#include <iostream>

namespace Astronomy {
	CSun* Sun = new CSun();
	CMoon* Moon = new CMoon();
	CMars* Mars = new CMars();
	CJupyter* Jupyter = new CJupyter();
	CSaturn* Saturn = new CSaturn();
	CVenus* Venus = new CVenus();
	CStar* Aldebaran = new CStar( CVector( 4.5833, 16.5, 0 ) );
	CStar* AlphaCentaurus = new CStar( CVector( 14.65, -60.83, 0 ) );
	CStar* Arctur = new CStar( CVector( 14.25, 19.167, 0 ) );
	CStar* Bellatrix = new CStar( CVector( 5.4167, 6.33, 0 ) );
	CStar* Betelgeuse = new CStar( CVector( 5.9167, 7.4, 0 ) );
	CStar* Vega = new CStar( CVector( 18.6, 38.7833, 0 ) );
	CStar* Sirius = new CStar( CVector( 6.75, -16.7, 0 ) );
	CStar* Plei = new CStar( CVector( 3.79, 24.1, 0 ) );
	CStar* Polar = new CStar( CVector( 2.5167, 89.25, 0 ) );
	CStar* Pollux = new CStar( CVector( 7.75, 28, 0 ) );
	CStar* Rigel = new CStar( CVector( 5.23, 32.45, 0 ) );
	CStar* Spika = new CStar( CVector( 13.42, -11.15, 0 ) );
	CStar* Orion = new CStar( CVector( 5.5833, -5.3833, 0 ) );
	CStar* Andromeda = new CStar( CVector( 0, 41.2666, 0 ) );
	CStar* Crab = new CStar( CVector( 5 + 17.0 / 30.0, 22, 0 ) );
	CSpaceObject* spaceObjects[] = {
		static_cast<CSpaceObject*>(Sun), 
		static_cast<CSpaceObject*>(Moon),
		static_cast<CSpaceObject*>(Mars), 
		static_cast<CSpaceObject*>(Jupyter), 
		static_cast<CSpaceObject*>(Saturn), 
		static_cast<CSpaceObject*>(Venus), 
		static_cast<CSpaceObject*>(Aldebaran), 
		static_cast<CSpaceObject*>(AlphaCentaurus), 
		static_cast<CSpaceObject*>(Arctur), 
		static_cast<CSpaceObject*>(Bellatrix), 
		static_cast<CSpaceObject*>(Betelgeuse), 
		static_cast<CSpaceObject*>(Vega), 
		static_cast<CSpaceObject*>(Sirius), 
		static_cast<CSpaceObject*>(Plei),
		static_cast<CSpaceObject*>(Polar), 
		static_cast<CSpaceObject*>(Pollux), 
		static_cast<CSpaceObject*>(Rigel), 
		static_cast<CSpaceObject*>(Spika), 
		static_cast<CSpaceObject*>(Orion), 
		static_cast<CSpaceObject*>(Andromeda), 
		static_cast<CSpaceObject*>(Crab)
	};
	const char* SO_names [ ] = {"Sun", "Moon", "Mars",
		"Jupyter", "Saturn", "Venus", "Aldebaran",
		"Alpha Centaurus", "Arctur", "Bellatrix",
		"Betelgeuse", "Vega", "Sirius", "Plei",
		"Polar", "Pollux", "Rigel", "Spika",
		"Orion", "Andromeda", "Crab"
	};
	void printCoordinates()
	{
		for( int i = 0; i < 21; ++i ) {
			CVector coordinates = spaceObjects[i]->findAzimutCoordinates();
			std::cout << SO_names[i] << '\n';
			for( int j = 0; j < 2; ++j ) {
				std::cout << coordinates.value[j] << ' ';
			}
			std::cout << '\n';
		}
	}
}
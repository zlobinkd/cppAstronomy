#include "Star.h"
#include "Sun.h"
#include "Planet.h"
#include <iostream>
#include <map>
#include <string>

int main() {
	std::map<std::string, CAstronomicalObject*> astronomicalObjects;

	// initialize stars
	try {
		astronomicalObjects["Aldebaran"] = new CStar(CVector(4.5833, 16.5, 0));
		astronomicalObjects["AlphaCentaura"] = new CStar(CVector(14.65, -60.83, 0));
		astronomicalObjects["Arctur"] = new CStar(CVector(14.25, 19.167, 0));
		astronomicalObjects["Bellatrix"] = new CStar(CVector(5.4167, 6.33, 0));
		astronomicalObjects["Betelguese"] = new CStar(CVector(5.9167, 7.4, 0));
		astronomicalObjects["Vega"] = new CStar(CVector(18.6, 38.7833, 0));
		astronomicalObjects["Sirius"] = new CStar(CVector(6.75, -16.7, 0));
		astronomicalObjects["Plei"] = new CStar(CVector(3.79, 24.1, 0));
		astronomicalObjects["Polar"] = new CStar(CVector(2.5167, 89.25, 0));
		astronomicalObjects["Pollux"] = new CStar(CVector(7.75, 28, 0));
		astronomicalObjects["Rigel"] = new CStar(CVector(5.23, 32.45, 0));
		astronomicalObjects["Spika"] = new CStar(CVector(13.42, -11.15, 0));
		astronomicalObjects["Orion"] = new CStar(CVector(5.5833, -5.3833, 0));
		astronomicalObjects["Andromeda"] = new CStar(CVector(0, 41.2666, 0));
		astronomicalObjects["Crab"] = new CStar(CVector(5 + 17.0 / 30.0, 22, 0));
	}
	catch (const std::exception& e) {
		std::cout << "Exception occured while creating stars: " << e.what() << std::endl;
	}
	
	// initialize Sun
	try {
		astronomicalObjects["Sun"] = new CSun();
	}
	catch (const std::exception& e) {
		std::cout << "Exception occured while creating Sun: " << e.what() << std::endl;
	}

	// initialize Mercury
	std::tm mercuryConfrontation{};
	mercuryConfrontation.tm_year = 2006 - 1900;
	mercuryConfrontation.tm_mon = 10;
	mercuryConfrontation.tm_mday = 8;
	mercuryConfrontation.tm_hour = 0;
	mercuryConfrontation.tm_min = 0;
	mercuryConfrontation.tm_sec = 0;
	try {
		astronomicalObjects["Mercury"] = new CPlanet(mercuryConfrontation, 87.97 * 24, 0.387);
	}
	catch (const std::exception& e) {
		std::cout << "Exception occured while creating Mercury: " << e.what() << std::endl;
	}

	// initialize Venus
	std::tm venusConfrontation{};
	venusConfrontation.tm_year = 2012 - 1900;
	venusConfrontation.tm_mon = 5;
	venusConfrontation.tm_mday = 6;
	venusConfrontation.tm_hour = 0;
	venusConfrontation.tm_min = 0;
	venusConfrontation.tm_sec = 0;
	try {
		astronomicalObjects["Venus"] = new CPlanet(venusConfrontation, 224.7 * 24, 0.723);
	}
	catch (const std::exception& e) {
		std::cout << "Exception occured while creating Venus: " << e.what() << std::endl;
	}

	// initialize Mars
	std::tm marsConfrontation{};
	marsConfrontation.tm_year = 2022 - 1900;
	marsConfrontation.tm_mon = 11;
	marsConfrontation.tm_mday = 8;
	marsConfrontation.tm_hour = 0;
	marsConfrontation.tm_min = 0;
	marsConfrontation.tm_sec = 0;
	try {
		astronomicalObjects["Mars"] = new CPlanet(marsConfrontation, 686.98 * 24, 1.524);
	}
	catch (const std::exception& e) {
		std::cout << "Exception occured while creating Mars: " << e.what() << std::endl;
	}

	// initialize Jupyter
	std::tm jupyterConfrontation{};
	jupyterConfrontation.tm_year = 2022 - 1900;
	jupyterConfrontation.tm_mon = 8;
	jupyterConfrontation.tm_mday = 26;
	jupyterConfrontation.tm_hour = 0;
	jupyterConfrontation.tm_min = 0;
	jupyterConfrontation.tm_sec = 0;
	try {
		astronomicalObjects["Jupyter"] = new CPlanet(jupyterConfrontation, 4332.59 * 24, 5.204);
	}
	catch (const std::exception& e) {
		std::cout << "Exception occured while creating Jupyter: " << e.what() << std::endl;
	}

	// initialize Saturn
	std::tm saturnConfrontation{};
	saturnConfrontation.tm_year = 2031 - 1900;
	saturnConfrontation.tm_mon = 11;
	saturnConfrontation.tm_mday = 11;
	saturnConfrontation.tm_hour = 0;
	saturnConfrontation.tm_min = 0;
	saturnConfrontation.tm_sec = 0;
	try {
		astronomicalObjects["Saturn"] = new CPlanet(saturnConfrontation, 10759.22 * 24, 9.5);
	}
	catch (const std::exception& e) {
		std::cout << "Exception occured while creating Saturn: " << e.what() << std::endl;
	}

	// initialize Uranus
	std::tm uranusConfrontation{};
	uranusConfrontation.tm_year = 2048 - 1900;
	uranusConfrontation.tm_mon = 1;
	uranusConfrontation.tm_mday = 28;
	uranusConfrontation.tm_hour = 0;
	uranusConfrontation.tm_min = 0;
	uranusConfrontation.tm_sec = 0;
	try {
		astronomicalObjects["Uranus"] = new CPlanet(uranusConfrontation, 30685.4 * 24, 19.23);
	}
	catch (const std::exception& e) {
		std::cout << "Exception occured while creating Uranus: " << e.what() << std::endl;
	}

	// initialize Neptune
	std::tm neptuneConfrontation{};
	neptuneConfrontation.tm_year = 2022 - 1900;
	neptuneConfrontation.tm_mon = 8;
	neptuneConfrontation.tm_mday = 17;
	neptuneConfrontation.tm_hour = 0;
	neptuneConfrontation.tm_min = 0;
	neptuneConfrontation.tm_sec = 0;
	try {
		astronomicalObjects["Neptune"] = new CPlanet(neptuneConfrontation, 60190.03 * 24, 30.1);
	}
	catch (const std::exception& e) {
		std::cout << "Exception occured while creating Uranus: " << e.what() << std::endl;
	}

	// log the azimutal coordinates of all objects
	for (auto pair : astronomicalObjects) {
		std::string name = pair.first;
		CAstronomicalObject* p_spaceObject = pair.second;
		CVector coordinates;

		try {
			coordinates = p_spaceObject->findAzimutCoordinates();
		}
		catch (const std::exception& e) {
			std::cout << "Exception occured while getting coordinates of " << name << ": " << e.what() << std::endl;
		}

		std::cout << name << std::endl;
		std::cout << coordinates.m_value[0] << " " << coordinates.m_value[1] << std::endl;
		std::cout << std::endl;
	}
	return 0;
}
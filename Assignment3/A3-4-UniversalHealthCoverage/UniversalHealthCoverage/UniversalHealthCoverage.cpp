/* File: UniversalHealthCoverage.cpp
 *
 * A program that determines whether or not it is possible to provide
 * coverage to everyone using a fixed number of hospitals.
 */
#include <iostream>
#include <string>
#include "set.h"
#include "vector.h"
#include "console.h"
using namespace std;

/* Function: canOfferUniversalCoverage(Set<string>& cities,
 *                                     Vector< Set<string> >& locations,
 *                                     int numHospitals,
 *                                     Vector< Set<string> >& result);
 * Usage: if (canOfferUniversalCoverage(cities, locations, 4, result)
 * ==================================================================
 * Given a set of cities, a list of what cities various hospitals can
 * cover, and a number of hospitals, returns whether or not it's
 * possible to provide coverage to all cities with the given number of
 * hospitals.  If so, one specific way to do this is handed back in the
 * result parameter.
 */
bool canOfferUniversalCoverage(Set<string> cities,
                               Vector< Set<string> > locations,
                               int numHospitals,
                               Vector< Set<string> >& result);


int main() {
	Set<string> cities;
	cities.add("a");
	cities.add("b");
	cities.add("c");
	cities.add("d");

	Vector< Set<string> > locations;
	Set<string> hospital1;
	hospital1.add("a");
	//hospital1.add("b");
	//hospital1.add("c");
	Set<string> hospital2;
	hospital2.add("d");
	locations.add(hospital1);
	locations.add(hospital2);

	Vector< Set<string> > result;

	cout << canOfferUniversalCoverage(cities, locations, 3, result);
	
	return 0;
}

bool canOfferUniversalCoverage(Set<string> cities,
                               Vector< Set<string> > locations,
                               int numHospitals,
                               Vector< Set<string> >& result) {
	if (locations.isEmpty()) {
		if (cities.isEmpty() && numHospitals >= 0) return true;
		else return false;
	}

	Set<string> temp = locations[0];

	
	locations.removeAt(0);
	if (canOfferUniversalCoverage(cities, locations, numHospitals, result)) return true;

	foreach(string city in temp) {
		cities.remove(city);
		//result[0].add(city);
	}
	
	if (canOfferUniversalCoverage(cities, locations, numHospitals--, result)) return true;

	
}



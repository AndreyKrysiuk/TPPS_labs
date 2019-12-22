#pragma once
#include "City.h"
#include <vector>
#include <string.h>

class Country
{
private: 
	std::vector<City*> cities;
	std::string name;
	int _rows;
	int _columns;

public:
	bool IsAllCoinsCollected(int countriesCount);
	bool IsIsolated(City*** europe);
	bool BuildCountry(int xl, int yl, int xh, int yh, City*** europe, int rows, int columns);

	void SendCoins(City*** europe);
	void EndDay();

	std::string GetCountryName(){ return name; }
	Country(std::string name);
	~Country();
};


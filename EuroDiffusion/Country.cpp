#include "pch.h"
#include "Country.h"

bool Country::IsAllCoinsCollected(int CountriesCount)
{
	for (auto city : this->cities)
	{
		if (!city->IsAllCoinsCollected(CountriesCount)) return false;
	}
	return true;
}

void Country::SendCoins(City *** europe)
{
	for (auto city : this->cities)
	{
		city->SendCoins(europe);
	}
}

bool Country::IsIsolated(City *** map)
{
	for (auto city : this->cities)
	{
		if (city->HasForeignNeighbours(map))
		{
			return false;
		}
	}
	return true;
}

bool Country::BuildCountry(int xl, int yl, int xh, int yh, City *** europe)
{
	if ((xl < 1 || xl > 10) || (yl < 1 || yl > 10) || (xh < 1 || xh > 10) || (yh < 1 || yh > 10))
	{
		return false;
	}
	for (int i = xl; i < xh + 1; i++)
	{
		for (int j = yl; j < yh + 1; j++)
		{
			europe[i][j] = new City(this->name, i, j);
			cities.push_back(europe[i][j]);
		}
	}
	return true;
}

void Country::EndDay()
{
	for (auto city : this->cities)
	{
		city->EndDay();
	}
}

Country::Country(std::string country)
{
	this->name = country;
}


Country::~Country()
{}

#include "pch.h"
#include "EuroDiffusionLogic.h"


void deleteMemory(City*** europe, int x, int y)
{
	for (int i = 0; i < x + 1; i++)
	{
		for (int j = 0; j < y + 1; j++)
		{
			delete europe[i][j];
			europe[i][j] = nullptr;
		}
	}
}
void printMap(City*** europe, int rows, int columns)
{
	for (int i = 0; i < rows + 1; i++)
	{
		for (int j = 0; j < columns + 1; j++)
		{
			std::cout << std::setw(8);
			if (europe[i][j] != nullptr)
			{
				std::cout << europe[i][j]->_balance["France"] << " ";
			}
			else
			{
				std::cout << "null" << " ";
			}
		}
		std::cout << std::endl;
	}
}

void coinCycle(City*** europe, std::vector<Country*> countries)
{
	if (countries.size() == 1)
	{
		std::cout << countries[0]->GetCountryName() << " 0" << std::endl;
		return;
	}

	int checkedCountriesCounter = 0;
	int days = 0;
	std::map<std::string, int> checkedCountries;

	while (checkedCountriesCounter < countries.size())
	{
		for (auto country : countries)
		{
			country->SendCoins(europe);
		}
		days++;
		for (auto country : countries)
		{
			country->EndDay();
		}
		for (auto country : countries)
		{
			if (country->IsAllCoinsCollected(countries.size()))
			{
				if (checkedCountries.find(country->GetCountryName()) == checkedCountries.end())
				{
					checkedCountries[country->GetCountryName()] = days;
					checkedCountriesCounter++;
				}
			}
		}
	}
	for (auto country : checkedCountries)
	{
		std::cout << country.first << " " << country.second << std::endl;
	}
}

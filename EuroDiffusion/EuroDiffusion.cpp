#include "pch.h"
#include <iostream>
#include "City.h"
#include <map>
#include <iomanip>
//returns count of cities
int buildCountry(std::string country, int xl, int yl, int xh, int yh, City*** europe)
{
	for (int i = xl; i < xh + 1; i++)
	{
		for (int j = yl; j < yh + 1; j++)
		{
			europe[i][j] = new City(country, i, j);
		}
	}
	return (xh - xl + 1) * (yh - yl + 1);
}

void printMap(City*** europe, int rows, int columns)
{
	for (int i = 0; i < rows + 1; i++)
	{
		for (int j = 0; j < columns + 1; j++)
		{
			std::cout << std::setw(5);
			if (europe[i][j] != nullptr)
			{
				for (auto it = europe[i][j]->_balance.begin(); it != europe[i][j]->_balance.end(); it++)
					std::cout << (it->second != 0) << " ";
			}
			else
			{
				std::cout  << "null" << " ";
			}
		}
		std::cout << std::endl;
	}
}

void coinCycle(City*** europe, int rows, int columns, int countries, std::map<std::string, int> cities_num)
{
	if (countries == 1)
	{
		std::cout << cities_num.begin()->first << " 0"<< std::endl;
		return;
	}

	int checkedCountriesCounter = 0;
	int days = 0;
	std::map<std::string, int> checkedCitiesCounts;
	std::map<std::string, bool> checkedCountries;

	while (checkedCountriesCounter < countries)
	{
		for (int i = 0; i < rows + 1; i++)
		{
			for (int j = 0; j < columns + 1; j++)
			{
				if (europe[i][j] != nullptr)
				{
					europe[i][j]->sendCoins(europe, rows, columns);
				}
			}
		}
		days++;
		for (int i = 0; i < rows + 1; i++)
		{
			for (int j = 0; j < columns + 1; j++)
			{
				if (europe[i][j] != nullptr)
				{
					europe[i][j]->endDay();
					if (!europe[i][j]->getIsChecked() && europe[i][j]->isAllCoinsCollected(countries))
					{
						std::string country = europe[i][j]->getCountry();
						if (checkedCitiesCounts.find(country) != checkedCitiesCounts.end())
						{
							checkedCitiesCounts[country]++;
						}
						else
						{
							checkedCitiesCounts[country] = 1;
						}
						europe[i][j]->setChecked(true);
					}
				}
			}
		}

		for (std::map<std::string, int>::iterator it = checkedCitiesCounts.begin(); it != checkedCitiesCounts.end(); ++it)
		{
			if (it->second == cities_num[it->first])
			{
				if (checkedCountries.find(it->first) == checkedCountries.end())
				{
					std::cout << it->first << " " << days << std::endl;
					checkedCountriesCounter++;
					checkedCountries[it->first] = true;
				}
			}
		}		
		//system("cls");
		//printMap(europe, rows, columns);
		//std::cout << days << std::endl;
	}
}

void deleteMemory(City*** europe, int x, int y)
{
	for (int i = 0; i < x + 1; i++)
	{
		europe[i] = new City *[y + 1];
		for (int j = 0; j < y + 1; j++)
		{
			europe[i][j] = nullptr;
		}
	}
}

void test1()
{
	int c = 3;
	int x = 6;
	int y = 6;
	City*** europe = new City **[x + 1];
	for (int i = 0; i < x + 1; i++)
	{
		europe[i] = new City *[y + 1];
		for (int j = 0; j < y + 1; j++)
		{
			europe[i][j] = nullptr;
		}
	}
	std::map<std::string, int> cities_num;
	cities_num["France"] = buildCountry("France", 1, 4, 4, 6, europe);
	cities_num["Spain"] = buildCountry("Spain", 3, 1, 6, 3, europe);
	cities_num["Portugal"] = buildCountry("Portugal", 1, 1, 2, 2, europe);
	std::cout << "Case Number 1" << std::endl;
	coinCycle(europe, x, y, c, cities_num);

	deleteMemory(europe, x, y);
}

void test2()
{
	int c = 1;
	int x = 3;
	int y = 3;
	City*** europe = new City **[x + 1];
	for (int i = 0; i < x + 1; i++)
	{
		europe[i] = new City *[y + 1];
		for (int j = 0; j < y + 1; j++)
		{
			europe[i][j] = nullptr;
		}
	}
	std::map<std::string, int> cities_num;
	cities_num["Luxembourg"] = buildCountry("Luxembourg", 1, 1, 1, 1, europe);
	std::cout << "Case Number 2" << std::endl;
	coinCycle(europe, x, y, c, cities_num);

	deleteMemory(europe, x, y);
}

void test3()
{
	int c = 2;
	int x = 5;
	int y = 5;
	City*** europe = new City **[x + 1];
	for (int i = 0; i < x + 1; i++)
	{
		europe[i] = new City *[y + 1];
		for (int j = 0; j < y + 1; j++)
		{
			europe[i][j] = nullptr;
		}
	}
	std::map<std::string, int> cities_num;
	cities_num["Netherlands"] = buildCountry("Netherlands", 1, 3, 2, 4, europe);
	cities_num["Belgium"] = buildCountry("Belgium", 1, 1, 2, 2, europe);
	std::cout << "Case Number 3" << std::endl;
	coinCycle(europe, x, y, c, cities_num);

	deleteMemory(europe, x, y);
}
int main()
{
	test1();
	test2();
	test3();
}


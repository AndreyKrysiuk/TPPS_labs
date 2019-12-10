#include "pch.h"
#include "Test.h"

void LaunchDiffusion(City*** europe, std::vector<Country*> countries)
{
	bool IsInvalidCase = false;
	for (auto country : countries)
	{
		if (country->IsIsolated(europe))
		{
			IsInvalidCase = true;
			break;
		}
	}
	if (countries.size() != 1 && IsInvalidCase)
	{
		std::cout << "One of country is isolated" << std::endl;
		return;
	}
	coinCycle(europe, countries);
}

City *** BuildEurope(int x, int y)
{
	City*** europe = new City **[x + 1];
	for (int i = 0; i < x + 1; i++)
	{
		europe[i] = new City *[y + 1];
		for (int j = 0; j < y + 1; j++)
		{
			europe[i][j] = nullptr;
		}
	}
	return europe;
}

void Test1()
{
	int x = 7;
	int y = 7;

	City*** europe = BuildEurope(x, y);

	std::cout << "Case Number 1" << std::endl;
	std::vector<Country*> countries;

	countries.push_back(new Country("France"));
	countries.push_back(new Country("Spain"));
	countries.push_back(new Country("Portugal"));

	if (countries[0]->BuildCountry(1, 4, 4, 6, europe) &&
		countries[1]->BuildCountry(3, 1, 6, 3, europe) &&
		countries[2]->BuildCountry(1, 1, 2, 2, europe))
	{
		LaunchDiffusion(europe, countries);
	}
	else
	{
		std::cout << "Invalid input data" << std::endl;
	}
	std::cout << std::endl;
	deleteMemory(europe, x, y);
}

void Test2()
{
	int x = 3;
	int y = 3;

	City*** europe = BuildEurope(x, y);

	std::cout << "Case Number 2" << std::endl;
	std::vector<Country*> countries;

	countries.push_back(new Country("Luxembourg"));

	if (countries[0]->BuildCountry(1, 1, 1, 1, europe))
	{
		LaunchDiffusion(europe, countries);
	}
	else
	{
		std::cout << "Invalid input data" << std::endl;
	}
	std::cout << std::endl;
	deleteMemory(europe, x, y);
}

void Test3()
{
	int x = 5;
	int y = 5;

	City*** europe = BuildEurope(x, y);

	std::cout << "Case Number 3" << std::endl;
	std::vector<Country*> countries;

	countries.push_back(new Country("Netherlands"));
	countries.push_back(new Country("Belgium"));

	if (countries[0]->BuildCountry(1, 3, 2, 4, europe) &&
		countries[1]->BuildCountry(1, 1, 2, 2, europe))
	{
		LaunchDiffusion(europe, countries);
	}
	std::cout << std::endl;
	deleteMemory(europe, x, y);
}

void Test4()
{
	int x = 6;
	int y = 6;

	City*** europe = BuildEurope(x, y);

	std::cout << "Case Number 4" << std::endl;
	std::vector<Country*> countries;

	countries.push_back(new Country("Luxembourg"));
	countries.push_back(new Country("Monaco"));

	if (countries[0]->BuildCountry(1, 1, 1, 1, europe) && countries[1]->BuildCountry(4, 4, 4, 4, europe))
	{
		LaunchDiffusion(europe, countries);
	}
	else
	{
		std::cout << "Invalid input data" << std::endl;
	}
	std::cout << std::endl;
	deleteMemory(europe, x, y);
}

void Test5()
{
	int c = 2;
	int x = 6;
	int y = 6;

	City*** europe = BuildEurope(x, y);

	std::cout << "Case Number 5" << std::endl;
	std::vector<Country*> countries;

	countries.push_back(new Country("Luxembourg"));
	countries.push_back(new Country("Monaco"));

	if (countries[0]->BuildCountry(0, 1, 1, 1, europe) && countries[1]->BuildCountry(-4, 4, 4, 4, europe))
	{
		LaunchDiffusion(europe, countries);
	}
	else
	{
		std::cout << "Invalid input data" << std::endl;
	}
	std::cout << std::endl;
	deleteMemory(europe, x, y);
}
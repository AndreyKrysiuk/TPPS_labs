#include "pch.h"
#include "City.h"


City::City(std::string country, int x, int y)
{
	_country = country;
	_x = x;
	_y = y;
	_balance[_country] = 1000000;
}

void City::RecieveCoins(std::string country, int coins)
{
	if (_tempBalance.find(country) != _tempBalance.end())
	{
		_tempBalance[country] += coins;
	}
	else
	{
		_tempBalance[country] = coins;
	}
}

void City::EndDay()
{
	for (auto it = _tempBalance.begin(); it != _tempBalance.end(); it++)
	{
		if (_balance.find(it->first) != _balance.end())
		{
			_balance[it->first] += it->second;
		}
		else
		{
			_balance[it->first] = it->second;
		}
		it->second = 0;
	}
}

bool City::IsAllCoinsCollected(int countOfTypes)
{
	int count = 0;
	for (std::map<std::string, int>::iterator it = _balance.begin(); it != _balance.end(); ++it)
	{
		if (it->second != 0)
		{
			count++;
		}
	}
	return count == countOfTypes;
}

void City::SendCoins(City*** europe)
{
	std::map<std::string, int> balanceToTransport = ÑalculateBalanceToTransport();
	if (europe[_x + 1][_y] != nullptr)
	{
		SendCoinsToCity(_x + 1, _y, europe, balanceToTransport);
	}
	if (europe[_x - 1][_y] != nullptr)
	{
		SendCoinsToCity(_x - 1, _y, europe, balanceToTransport);
	}
	if (europe[_x][_y + 1] != nullptr)
	{
		SendCoinsToCity(_x, _y + 1, europe, balanceToTransport);
	}
	if (europe[_x][_y - 1] != nullptr)
	{ 
		SendCoinsToCity(_x, _y - 1, europe, balanceToTransport);
	}
}

void City::SendCoinsToCity(int x, int y, City*** europe, std::map<std::string, int> balanceToTransport)
{
	for (auto it = _balance.begin(); it != _balance.end(); ++it)
	{
		europe[x][y]->RecieveCoins(it->first, balanceToTransport[it->first]);
		it->second -= balanceToTransport[it->first];
	}
}

std::map<std::string, int> City::ÑalculateBalanceToTransport()
{
	std::map<std::string, int> balanceToTransport;
	for (auto it = _balance.begin(); it != _balance.end(); it++)
	{
		balanceToTransport[it->first] = (int) (it->second / 1000);
	}
	return balanceToTransport;
}

bool City::HasForeignNeighbours(City *** map)
{
	return ((map[_x + 1][_y] && map[_x + 1][_y]->_country != _country) ||
		(map[_x - 1][_y] && map[_x - 1][_y]->_country != _country) ||
		(map[_x][_y + 1] && map[_x][_y + 1]->_country != _country) ||
		(map[_x][_y - 1] && map[_x][_y - 1]->_country != _country));
}
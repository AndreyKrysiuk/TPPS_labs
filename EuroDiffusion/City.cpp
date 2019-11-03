#include "pch.h"
#include "City.h"


City::City(std::string country, int x, int y)
{
	_country = country;
	_x = x;
	_y = y;
	_balance[_country] = 1000000;
}

void City::recieveCoins(std::string country, int coins)
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

void City::endDay()
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

bool City::isAllCoinsCollected(int countOfTypes)
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

void City::setChecked(bool value)
{
	_isChecked = value;
}

std::string City::getCountry()
{
	return _country;
}

void City::sendCoins(City*** europe, int rows, int columns)
{
	std::map<std::string, int> balanceToTransport = calculateBalanceToTransport();
	if (_x < rows && europe[_x + 1][_y] != nullptr)
	{
		for (auto it = _balance.begin(); it != _balance.end(); ++it)
		{
			europe[_x + 1][_y]->recieveCoins(it->first, balanceToTransport[it->first]);
			it->second -= balanceToTransport[it->first];
		}
		
	}
	if (_x > 0 && europe[_x - 1][_y] != nullptr)
	{
		for (auto it = _balance.begin(); it != _balance.end(); ++it)
		{
			europe[_x - 1][_y]->recieveCoins(it->first, balanceToTransport[it->first]);
			it->second -= balanceToTransport[it->first];
		}
	}
	if (_y < columns && europe[_x][_y + 1] != nullptr)
	{
		for (auto it = _balance.begin(); it != _balance.end(); ++it)
		{
			europe[_x][_y + 1]->recieveCoins(it->first, balanceToTransport[it->first]);
			it->second -= balanceToTransport[it->first];
		}
	}
	if (_y > 0 && europe[_x][_y - 1] != nullptr)
	{ 
		for (auto it = _balance.begin(); it != _balance.end(); ++it)
		{
			europe[_x][_y - 1]->recieveCoins(it->first, balanceToTransport[it->first]);
			it->second -= balanceToTransport[it->first];
		}
	}
}

std::map<std::string, int> City::calculateBalanceToTransport()
{
	std::map<std::string, int> balanceToTransport;
	for (auto it = _balance.begin(); it != _balance.end(); it++)
	{
		balanceToTransport[it->first] = (int) (it->second / 1000);
	}
	return balanceToTransport;
}


bool City::getIsChecked()
{
	return _isChecked;
}

City::~City()
{}

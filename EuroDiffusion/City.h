#pragma once
#include <string>
#include <map>
class City
{
public:	
	int _x, _y;
	std::string _country;
	std::map<std::string, int> _balance;
	std::map<std::string, int> _tempBalance;

private:
	std::map<std::string, int> ÑalculateBalanceToTransport();

public:
	City(std::string country, int x, int y);

	void SendCoins(City*** europe);
	void SendCoinsToCity(int x, int y, City *** europe, std::map<std::string, int> balanceToTransport);
	void RecieveCoins(std::string country, int coins);
	void EndDay();

	bool IsAllCoinsCollected(int countOfTypes);
	bool HasForeignNeighbours(City *** map);
};


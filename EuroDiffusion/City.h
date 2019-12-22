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
	static const int START_BALANCE = 1000000;
	static const int AMOUNT_TO_SEND_ONE_COIN = 1000;


private:
	std::map<std::string, int> СalculateBalanceToTransport();

public:
	City(std::string country, int x, int y);

	void SendCoins(City*** europe, const int& rows, const int& columns);
	void SendCoinsToCity(int x, int y, City *** europe, std::map<std::string, int> balanceToTransport);
	void RecieveCoins(const std::string & country, int coins);
	void EndDay();

	bool IsAllCoinsCollected(int countOfTypes);
	bool HasForeignNeighbours(City *** map);
};


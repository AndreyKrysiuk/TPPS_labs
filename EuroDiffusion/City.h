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
	bool _isChecked = false;
	std::map<std::string, int> calculateBalanceToTransport();
public:
	City() {};	
	~City();
	City(std::string country, int x, int y);

	void sendCoins(City*** europe, int rows, int columns);
	void recieveCoins(std::string country, int coins);

	void endDay();

	bool isAllCoinsCollected(int countOfTypes);

	std::string getCountry();	

	void setChecked(bool value);
	bool getIsChecked();

};


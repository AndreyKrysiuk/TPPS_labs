#pragma once

#include "City.h"
#include "Country.h"
#include <iostream>
#include <iomanip>
#include <vector>

void deleteMemory(City*** europe, int x, int y);
void printMap(City*** europe, int rows, int columns);
void coinCycle(City*** europe, std::vector<Country*> countries);

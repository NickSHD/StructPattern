#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "AbstractFactory.h"
#include "UNIT.h"
#include "TYPE.h"

class Player {

private:

	static ObjectFactory< UNIT, Type::type > RealFactory;
	std::vector< UNIT* > army;
	std::map < Type::type, int > stat;
	void print_pair(std::pair < std::string, int >);

public:

	explicit Player(int);
	void take_statistic();
	int take_index(std::string);
	void take_units(std::string, int);

};
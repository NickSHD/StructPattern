#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Initial_Values.h"
#include "AbstractFactory.h"
#include "UNIT.h"
#include "TYPE.h"

class CompositeUnit : public UNIT {
public:
	std::string info();
	bool isComposite();
	void addUnit(UNIT* rep);
	~CompositeUnit();
	std::vector<UNIT*>& getDetachment();
private:
	std::vector<UNIT*> _units;
};

class CreatorComposite {
public:
	CreatorComposite(std::vector<UNIT*>& rep) :
		_inp_units(rep) {};
	CompositeUnit* CreateComposite();
private:
	std::vector<UNIT*> _inp_units;
};
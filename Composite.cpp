#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Initial_Values.h"
#include "AbstractFactory.h"
#include "UNIT.h"
#include "TYPE.h"
#include "Composite.h"

void CompositeUnit::addUnit(UNIT* rep) {
	this->_units.push_back(rep);
}

std::string CompositeUnit::info() {
	std::string result = "List of Units:";
	for (int i = 0; i < this->_units.size(); i++) {
		result += " " + this->_units[i]->info();
	}
	return result;
}

CompositeUnit::~CompositeUnit() {
	for (int i = 0; i < this->_units.size(); i++) {
		delete this->_units[i];
	}
}

bool CompositeUnit::isComposite() {
	return false;
}

std::vector<UNIT*>& CompositeUnit::getDetachment() {
	return this->_units;
}

CompositeUnit* CreatorComposite::CreateComposite() {
	CompositeUnit* result = new CompositeUnit;
	for (int i = 0; i < this->_inp_units.size(); i++) {
		result->addUnit(this->_inp_units[i]);
	}
	return result;		
};
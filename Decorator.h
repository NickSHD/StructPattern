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

class AbstructArmyDecorator: public UNIT {
public:
	UNIT* _decoratee;
	virtual void add_prop() = 0;
};

class HealthRegeneration : public AbstructArmyDecorator {
public:
	HealthRegeneration(UNIT* decoratee, int regeneration) :
		_regeneration(regeneration) {
		this->_decoratee = decoratee;
	};

	void add_prop();
	void take_move() { return; }
private:
	int _regeneration;

};


class DamageIncreasing : public AbstructArmyDecorator {
public:
	DamageIncreasing(UNIT* decoratee, int increase) :
		_increase(increase) {
		this->_decoratee = decoratee;
	};

	void add_prop();
	void take_move();

private:
	int _increase;;

};

class MilitaryDevelop : public AbstructArmyDecorator {
public:
	MilitaryDevelop(UNIT* decoratee) {
		this->_decoratee = decoratee;
	};

	MilitaryDevelop(AbstructArmyDecorator* decoratee) {
		this->_decoratee = decoratee->_decoratee;
	};
	void take_move();
};


#pragma once
#include <iostream>
#include <map>
#include <string>

#include "Initial_Values.h"
#include "AbstractFactory.h"
#include "UNIT.h"
#include "TYPE.h"

class ConcreteFactory {

public:

	static ObjectFactory < UNIT, Type::type >* RealFactory;
	void update();

};
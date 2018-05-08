#include <iostream>
#include <map>
#include <string>

#include "Initial_Values.h"
#include "AbstractFactory.h"
#include "ConcreteFactory.h"
#include "UNIT.h"
#include "TYPE.h"

ObjectFactory < UNIT, Type::type >* ConcreteFactory::RealFactory = new ObjectFactory < UNIT, Type::type >();

void ConcreteFactory::update() {
	RealFactory->add < defender >(Type::type::defender);
	RealFactory->add < long_range_damage >(Type::type::long_range_damage);
	RealFactory->add < great_damage >(Type::type::great_damage);
}
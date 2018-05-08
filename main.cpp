#include <iostream>
#include <string>
#include <map>

#include "AbstractFactory.h"
#include "UNIT.h"
#include "Player.h"
#include "ConcreteFactory.h"

int main() {
	ConcreteFactory Begin;
	Begin.update();
	Player P(1000);
	P.take_units("defender", 10);
	P.take_statistic();
	system("pause");
}
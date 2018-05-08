#include <iostream>
#include <map>
#include <string>

#include "Initial_Values.h"
#include "Player.h"
#include "AbstractFactory.h"
#include "UNIT.h"
#include "ConcreteFactory.h"
#include "TYPE.h"

void Player::print_pair(std::pair < std::string, int > pair) {
	std::cout << pair.first << " = " << pair.second << std::endl;
}

Player::Player(int money) {
	stat[Type::type::defender] = 0;
	stat[Type::type::long_range_damage] = 0;
	stat[Type::type::great_damage] = 0;
	stat[Type::type::money] = money;
}
	

int Player::take_index(std::string index) {
	Type::type T;
	T = Type::from_string(index);
	return stat[T];
}

void Player::take_statistic() {
	for (auto it : stat) {
		std::string from_enum = Type::to_string(it.first);
		std::pair<std::string, int> pair_out= { from_enum, it.second };
		print_pair(pair_out);
	}
}

void Player::take_units(std::string type, int count) {
	Type::type T;
	T = Type::from_string(type);
	UNIT* soldier = ConcreteFactory::RealFactory->CreateUnit(T);
	if (soldier->cost * count > stat[Type::type::money])
		std::cout << "You don't have enough money" << std::endl;
	else {
		for (int i = 0; i < count; i++) {
			army.push_back(ConcreteFactory::RealFactory->CreateUnit(T));
			stat[T]++;
		}
		stat[Type::type::money] -= soldier->cost * count;
	}
}
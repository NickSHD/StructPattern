#include <iostream>
#include <string>

#include "AbstractFactory.h"
#include "UNIT.h"
#include "Initial_Values.h"


std::string defender::info() {
	return "defender";
}

defender::defender() {
	cost = begin_cost_defender;
	health = begin_health_defender;
	speed = begin_speed_defender;
	damage = begin_damage_defender;
	income = begin_income_defender;
	consuption = begin_consuption_defender;
}

std::string great_damage::info() {
	return "great_damage";
}

great_damage::great_damage() {
	cost = begin_cost_great_damage;
	health = begin_health_great_damage;
	speed = begin_speed_great_damage;
	damage = begin_damage_great_damage;
	income = begin_income_great_damage;
	consuption = begin_consuption_great_damage;
}

std::string long_range_damage::info() {
	return "long_range_damage";
}

long_range_damage::long_range_damage() {
	cost = begin_cost_long_range_damage;
	health = begin_health_long_range_damage;
	speed = begin_speed_long_range_damage;
	damage = begin_damage_long_range_damage;
	income = begin_income_long_range_damage;
	consuption = begin_consuption_long_range_damage;
}



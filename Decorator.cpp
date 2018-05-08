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
#include "Decorator.h"


void HealthRegeneration::add_prop() {
	if (!this->isComposite()) {
		this->health += this->_regeneration;
	}
	for (int i = 0; i < this->getDetachment().size(); i++) {
		(this->getDetachment())[i]->health += this->_regeneration;
	}
}

void HealthRegeneration::take_move() {
	this->add_prop();
	this->_decoratee->take_move();
}

void DamageIncreasing::add_prop() {
	if (!this->isComposite()) {
		this->damage += this->_increase;
	}
	for (int i = 0; i < this->getDetachment().size(); i++) {
		(this->getDetachment())[i]->damage += this->_increase;
	}
}

void DamageIncreasing::take_move() {
	this->add_prop();
	this->_decoratee->take_move();
}

void MilitaryDevelop::add_prop() {
	//какие-нибудь действия во время войны
}

void MilitaryDevelop::take_move() {
	this->add_prop();
	this->_decoratee->take_move();
}


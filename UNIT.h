#pragma once
#include <iostream>
#include <string>
#include <assert.h>
#include <vector>


class UNIT {
public:
	int cost;
	int health;
	int speed;
	int damage;
	int income;
	int	consuption;
	virtual std::string info() = 0;
	virtual void addUnit(UNIT* rep) {assert(false);}
	virtual bool isComposite() { return 0; }
	virtual void take_move() { return; }
	virtual std::vector<UNIT*>& getDetachment() = 0;
};

class defender : public UNIT {
public:
	UNIT* take_ptr() { return this; }
	std::string info();
	explicit defender();
	~defender()
	{}
};

class long_range_damage : public UNIT {
public:
	UNIT* take_ptr() { return this; }
	std::string info();
	explicit long_range_damage();
	~long_range_damage() {}
};

class great_damage : public UNIT {
public:
	UNIT* take_ptr() { return this; }
	std::string info();
	explicit great_damage();
	~great_damage() {}
};

#pragma once
#include <iostream>
#include <map>
#include <string>


template < class Base >
class AbstractCreator {
public:
	AbstractCreator() {}
	virtual ~AbstractCreator() {}
	virtual Base* Create() const = 0;
};

template < class HeirClass, class Base >
class Creator : public AbstractCreator < Base > {
public:
	Creator() {}
	virtual ~Creator() {}

	Base* Create() const {
		return new HeirClass();
	}
};


template < class Base, class Type >
class ObjectFactory {
protected:
	typedef AbstractCreator < Base > AbstractFactory;
	typedef std::map < Type, AbstractFactory* > FactoryMap;
	FactoryMap Factory;

	void RegisterClass(const Type& id, AbstractFactory* temp) {
		FactoryMap::iterator it = Factory.find(id);
		if (it == Factory.end()) {
			Factory[id] = temp;
		}
		else
			delete temp;
	}

public:
	ObjectFactory() {}
	virtual ~ObjectFactory() {};

	template < class HeirClass >
	void add(const Type& id) {
		RegisterClass(id, new Creator < HeirClass, Base >());
	}

	Base* CreateUnit(const Type& id) {
		FactoryMap::iterator it = Factory.find(id);
		if (it != Factory.end())
			return Factory[id]->Create();
		else
			return 0;
	}
};
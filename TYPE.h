#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

class Type {
public:
	enum type { defender, long_range_damage, great_damage, money };
	static const std::string& to_string(type enumVal) {
		static const std::map<type, std::string> enumStringsMap = _make_enum_strings_map();
		auto it = enumStringsMap.find(enumVal);
		static std::string emptyString;
		if (it == enumStringsMap.end())
			return emptyString;
		return it->second;
	}

	static type from_string(const std::string &value) {
		static const std::map<std::string, type> stringsEnumMap = _make_strings_enum_map();
		std::map<std::string, type>::const_iterator it = stringsEnumMap.find(value);
		if (it == stringsEnumMap.end())
			return (type)0;
		return it->second;
	}

private:

	static std::map<type, std::string> _make_enum_strings_map() {
		std::map<type, std::string> enumStringsMap;
		enumStringsMap.insert(std::make_pair(defender, "defender"));
		enumStringsMap.insert(std::make_pair(long_range_damage, "long_range_damage"));
		enumStringsMap.insert(std::make_pair(great_damage, "great_damage"));
		enumStringsMap.insert(std::make_pair(money, "money"));
		return enumStringsMap;
	}

	static std::map<std::string, type> _make_strings_enum_map() {
		std::map<std::string, type> stringsEnumMap;
		stringsEnumMap.insert(std::make_pair("defender", defender));
		stringsEnumMap.insert(std::make_pair("long_range_damage", long_range_damage));
		stringsEnumMap.insert(std::make_pair("great_damage", great_damage));
		stringsEnumMap.insert(std::make_pair("money", money));
		return stringsEnumMap;
	}
};
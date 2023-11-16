//
// Created by lolgetreKt on 11/15/2023.
//

#ifndef WEREGELD_PERSON_H
#define WEREGELD_PERSON_H

#include <iostream>
#include <string>
#include "Location.h"
#include "Stats.h"

namespace WG {

class Person {
public:
	Person(std::string name, Location *location);

	[[nodiscard]] std::string getName() const;

	[[nodiscard]] Location *getLocation() const;

	void setLocation(Location *location);

	Person(const Person &person);

	Person(Person &&person)  noexcept;

	Person &operator=(Person &&person)  noexcept;

	friend std::ostream &operator<<(std::ostream &stream, const Person &person);

private:
	std::string name;
	Location *location;
	Stats personStats;
};



}

#endif //WEREGELD_PERSON_H

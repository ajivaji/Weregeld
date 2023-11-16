#include "Location.h"
#include <ostream>
#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include "Person.h"
#include <random>

namespace WG {
	Person::Person(std::string name, Location *location) : name(name), location(location) {
		personStats.health = 100;
	}

	[[nodiscard]] std::string Person::getName() const {
		return name;
	}

	[[nodiscard]] Location *Person::getLocation() const {
		return location;
	}

	void Person::setLocation(Location *location) {
		this->location = location;
	}

	Person::Person(const Person &person) : name(person.name) {
		std::cout << "copy constructor" << std::endl;
		location = new Location(person.getLocation()->getName(), person.getLocation()->getDescription());
	}

	Person::Person(Person &&person)  noexcept {
	std::cout << "move constructor" << std::endl;
	name = person.name;
	location = person.getLocation();
	person.name = "";
	person.setLocation(nullptr);
}

Person & Person::operator=(Person &&person)  noexcept {
	if (this != &person) {
		std::cout << "move assignment" << std::endl;
		name = person.name;
		location = person.getLocation();
		person.name = "";
		person.setLocation(nullptr);
	}
}

std::ostream &operator<<(std::ostream &stream, const Person &person) {
	stream << person.getName() << " is at " << person.getLocation()->getName() << std::endl;
	return stream;
}


}

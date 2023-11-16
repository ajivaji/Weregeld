#include <vector>
#include <iostream>
#include "Location.h"

namespace WG {
	Location::Location(const std::string &name, const std::string &description) : name(name), description(description) {}

	void Location::addConnection(Connection* connection) {
		connections.push_back(connection);
	}

	std::string Location::getName() const {
		return name;
	}

	std::string Location::getDescription() const {
		return description;
	}

	std::vector<Connection*> Location::getConnections() const {
		return connections;
	}
}


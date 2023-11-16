//
// Created by lolgetreKt on 11/14/2023.
//

#ifndef WEREGELD_LOCATION_H
#define WEREGELD_LOCATION_H

#include <vector>
#include <string>
#include <memory>
#include "Connection.h"

//write a class for a physical location that has aescription, name, and a set of connections to other locations
namespace WG {
class Location {
public:
	Location(const std::string &name, const std::string &description);

	void addConnection(Connection* connection);

	[[nodiscard]] std::string getName() const;

	[[nodiscard]] std::string getDescription() const;

	[[nodiscard]] std::vector<Connection*> getConnections() const;

private:
	std::string name;
	std::string description;
	std::vector<Connection*> connections;
};

}

#endif //WEREGELD_LOCATION_H

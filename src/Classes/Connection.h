//
// Created by lolgetreKt on 11/15/2023.
//
#ifndef WEREGELD_CONNECTION_H
#define WEREGELD_CONNECTION_H


#include "Location.h"

namespace WG {
class Connection {
public:
	Connection() = default;

	Connection(Location *fromLocation, Location *toLocation, std::string description);

	[[nodiscard]] Location *getfromLocation() const;

	[[nodiscard]] Location *gettoLocation() const;

	[[nodiscard]] std::string getDescription() const;

private:
	Location *fromLocation;
	Location *toLocation;
	std::string description;
};

}

#endif //WEREGELD_CONNECTION_H

//
// Created by lolgetreKt on 11/15/2023.
//

#include <string>
#include "Connection.h"


namespace WG {
Connection::Connection(Location *fromLocation, Location *toLocation, std::string description) : fromLocation(
		fromLocation), toLocation(toLocation), description(description) {}

Location *Connection::getfromLocation() const {
	return fromLocation;
}

Location *Connection::gettoLocation() const {
	return toLocation;
}

std::string Connection::getDescription() const {
	return description;
}

}
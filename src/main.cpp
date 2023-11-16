#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <ostream>
#include "Classes/Location.h"
#include "Classes/Person.h"
#include "Classes/Connection.h"


int main() {
	return 0;
}

namespace WG {

void Game() {
	auto* location1 = new Location("Home", "You are at home");
	auto* location2 = new Location("Work", "You are at work");

	Connection connection(location1, location2, "Walk");

	Person person("John", location1);


}

}



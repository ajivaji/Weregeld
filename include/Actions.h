//
// Created by ajivaji on 11/16/2023.
//

#pragma once

#include <string>
#include "../Classes/Objects/Object.h"


namespace WG {

	struct gameData;
	void doGo(gameData *data, Object* object = nullptr, Object* indirectObject = nullptr);
	void doLook(gameData *data, Object* object = nullptr, Object* indirectObject = nullptr);
	void doTake(gameData *data, Object* object = nullptr, Object* indirectObject = nullptr);
	void doDrop(gameData *data, Object* object = nullptr, Object* indirectObject = nullptr);
	void doInventory(gameData *data, Object* object = nullptr, Object* indirectObject = nullptr);
}
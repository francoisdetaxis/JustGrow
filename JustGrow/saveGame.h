#pragma once
#include <iostream>
#include <fstream>
#include "Player.h"
#include "Gold.h"
#include "Stage.h"

void loadGame(Player& player, Gold& gold, Stage& stage);
void saveGame(const Player& player, const Gold& gold, const Stage& stage);
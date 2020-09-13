#pragma once
#include <iostream>
#include <fstream>
#include "Player.h"

void saveGame(const Player& player);
void loadGame(Player& player);
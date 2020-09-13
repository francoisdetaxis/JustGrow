#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <string>
#include <map>
#include <math.h>
#include <iostream>
#include <random>
#include <queue>
#include <thread>
#include <vector>

#include "BigNumber.h"
#include "Hit.h"
#include "Player.h"
#include "Mytexture.h"
#include "loadFonts.h"
#include "loadingScreen.h"
#include "loadSounds.h"
#include "loadTextures.h"
#include "Monster.h"
#include "Button.h"
#include "dragon.h"
#include "Menu.h"
#include "Stage.h"
#include "ScrollView.h"
#include "Gold.h"
#include "saveGame.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define MAX_PLATFORM_NB 9

enum class GameState {
	MENU, PLAY, QUIT
};

//------------------------------REMINDER-------------------------------------------
// TOP = y position of the top left corner
// LEFT = x position of the top left corner

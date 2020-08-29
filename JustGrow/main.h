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
#include <iostream>
#include <random>
#include <queue>
#include <thread>
#include <vector>

#include "Mytexture.h"
#include "loadFonts.h"
#include "loadingScreen.h"
#include "loadSounds.h"
#include "loadTextures.h"
#include "Monster.h"
#include "Button.h"
#include "dragon.h"
#include "Hit.h"
#include "Menu.h"
#include "Player.h"
#include "Stage.h"
#include "ScrollView.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define MAX_PLATFORM_NB 9

//------------------------------REMINDER-------------------------------------------
// TOP = y position of the top left corner
// LEFT = x position of the top left corner

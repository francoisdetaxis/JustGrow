#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <random>
#include <queue>
#include <thread>
#include <vector>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "ScrollView.h"
#include "Button.h"
#include "Menu.h"
#include "loadingScreen.h"
#include "Monster.h"
#include "Mytexture.h"
#include "Player.h"
#include "loadTextures.h"
#include "loadSounds.h"
#include "loadFonts.h"
#include "dragon.h"


#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080


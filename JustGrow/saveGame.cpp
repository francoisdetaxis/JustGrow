#include "saveGame.h"

void saveGame(const Player& player, const Gold& gold, const Stage& stage)
{
	std::ofstream saveFile("./saves/save1");
	if (saveFile)  //On teste si tout est OK
	{
		//Tout est OK, on peut utiliser le fichier
		//PLAYER
		saveFile << player._clickDmg._value << " " << player._clickDmg._exponent << std::endl;
		saveFile << player._globalMult._value << " " << player._globalMult._exponent << std::endl;
		saveFile << player._heroMult._value << " " << player._heroMult._exponent << std::endl;
		saveFile << player._critMultiplier._value << " " << player._critMultiplier._exponent << std::endl;
		saveFile << player._goldMultiplier._value << " " << player._goldMultiplier._exponent << std::endl;
		saveFile << player._clickUpgradeCost._value << " " << player._clickUpgradeCost._exponent << std::endl;
		//GOLD
		saveFile << gold._gold._value << " " << gold._gold._exponent << std::endl;
		saveFile << gold._goldGain._value << " " << gold._goldGain._exponent << std::endl;
		//STAGE
		saveFile << stage._currentStage << " " << stage._currentLevel << std::endl;

		saveFile.close();
		//PLAYER
		//BigNumber _clickDmg;
		//BigNumber _globalMult;
		//BigNumber _heroMult;
		//BigNumber _critMultiplier;
		//BigNumber _goldMultiplier;
		//BigNumber _clickUpgradeCost;
		//GOLD
		//BigNumber _goldGain;
		//BigNumber _gold;
		//STAGE
		//int _currentStage; //int _currentLevel;
	}
	else
	{
		std::cout << "ERREUR: Impossible d'ouvrir le fichier save1" << std::endl;
	}
}

void loadGame(Player& player, Gold& gold, Stage& stage)
{
	std::ifstream loadFile("./saves/save1");
	if (loadFile)  //On teste si tout est OK
	{
		//Tout est OK, on peut utiliser le fichier
		//PLAYER
		loadFile >> player._clickDmg._value >> player._clickDmg._exponent;
		loadFile >> player._globalMult._value >> player._globalMult._exponent;
		loadFile >> player._heroMult._value >> player._heroMult._exponent;
		loadFile >> player._critMultiplier._value >> player._critMultiplier._exponent;
		loadFile >> player._goldMultiplier._value >> player._goldMultiplier._exponent;
		loadFile >> player._clickUpgradeCost._value >> player._clickUpgradeCost._exponent;
		//GOLD
		loadFile >> gold._gold._value >> gold._gold._exponent;
		loadFile >> gold._goldGain._value >> gold._goldGain._exponent;
		//STAGE
		loadFile >> stage._currentStage >> stage._currentLevel;

		loadFile.close();
		//PLAYER
		//BigNumber _clickDmg;
		//BigNumber _globalMult;
		//BigNumber _heroMult;
		//BigNumber _critMultiplier;
		//BigNumber _goldMultiplier;
		//BigNumber _clickUpgradeCost;
		//GOLD
		//BigNumber _goldGain;
		//BigNumber _gold;
		//STAGE
		//int _currentStage;
		//int _currentLevel;
	}
	else
	{
		std::cout << "ERREUR: Impossible d'ouvrir le fichier save1" << std::endl;
	}
}
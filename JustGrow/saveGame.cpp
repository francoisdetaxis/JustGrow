#include "saveGame.h"

void saveGame()
{
	std::ofstream saveFile("./saves/save1");
	if (saveFile)  //On teste si tout est OK
	{
		//Tout est OK, on peut utiliser le fichier
	}
	else
	{
		std::cout << "ERREUR: Impossible d'ouvrir le fichier save1" << std::endl;
	}
}
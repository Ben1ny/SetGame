#pragma once
#include <stdio.h>
#include <cstdlib>
#include <array>
using namespace std;
//using std::string;

class Set_Card
{
public:
	Set_Card();
	Set_Card(int, std::string, std::string, std::string, int);
	int getCardAnzahl();
	std::string getCardForm();
	std::string getCardFarbe();
	std::string getCardFuellung();
	int getCardId();
	void delCard();
	void printCard();


private:
	int anzahl;
	int CardId;
	std::string form;
	std::string farbe;
	std::string fuellung;
};



class Set_Deck
{
public:
	Set_Deck();
	Set_Card getCardFromDeck();
	void Set_PrintDeck();
	int Set_getDeckRemainingCards();
	array <Set_Card, 12> Set_GetStartUpTheTwelve();
	array <Set_Card, 12> Set_GetTheTwelve();
	Set_Card Set_GetCardFromTwelve(int);
	//array <Set_Card, 12> Set_GetTheTwelve();
	void Set_SetTheTwelve(Set_Card, int);
protected:
	array <Set_Card, 81> Deck;
private:
	array <Set_Card, 12> TheTwelve;

};

/*class Set_TheTwelve
{
public:
	Set_TheTwelve();
	void Set_PrintTheTwelve();

private:

};*/


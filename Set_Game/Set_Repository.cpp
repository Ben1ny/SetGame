#include "stdafx.h"
#include "Set_Repository.h"
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <array>
#include <algorithm>
#include <chrono>
#include <random>


using namespace std;


Set_Card::Set_Card() // default constructor is not used elsewhere, just defined for completeness ( and because there were compiler problems w/o it)
{

}

Set_Card::Set_Card(int an, string fo, string fa, string fue, int IdNr) // in this constructor the value for the 4 different attributes as well as 
{
	anzahl = an;
	form = fo;
	farbe = fa;
	fuellung = fue;
	CardId = IdNr;
}

Set_Card::~Set_Card() // destructor also only defined for completeness
{

}

int Set_Card::getCardAnzahl() { return anzahl; }			// simple getter function used in CheckForSet algo
string Set_Card::getCardForm() { return form; }				// simple getter function used in CheckForSet algo
string Set_Card::getCardFarbe() { return farbe; }			// simple getter function used in CheckForSet algo
string Set_Card::getCardFuellung() { return fuellung; }		// simple getter function used in CheckForSet algo
int Set_Card::getCardId() { return CardId; }				// simple getter function used in CheckForSet algo
void Set_Card::delCard() { CardId = -CardId; }				// simple function to set CardId negative, this is used to mark a card as drawn from the stack

void Set_Card::printCard() // this function was only needed for debugging in the beginning when the whole repository part was only running on console
{
	cout << "Kartennr.: " << CardId << "\t" << " Form: " << form << "\t" << " Farbe: " << farbe << "\t" << " Fuellung: " << fuellung << "\t" << "Anzahl: " << anzahl << endl;
}

Set_Deck::Set_Deck()
{
	string farbe, form, fuellung;
	int counter = 0;
	for (int i = 0; i <= 2; i++){				// for-loop to switch colour
		switch (i)
		{
		case 0:
			farbe = "rot";
			break;
		case 1:
			farbe = "gruen";
			break;
		case 2:
			farbe = "blau";
			break;
		}
		for (int j = 0; j <= 2; j++){			// for-loop to switch shape
			switch (j)
			{
			case 0:
				form = "Kreis";
				break;
			case 1:
				form = "Dreieck";
				break;
			case 2:
				form = "Viereck";
				break;
			}
			for (int k = 0; k <= 2; k++){		// for-loop to switch filling
				switch (k)
				{
				case 0:
					fuellung = "keine";
					break;
				case 1:
					fuellung = "schraffiert";
					break;
				case 2:
					fuellung = "volle";
					break;
				}
				for (int l = 0; l <= 2; l++){	// for-loop to generate number of symbols on card
					Deck[counter] = Set_Card(l + 1, form, farbe, fuellung, counter + 1);	// generation of the deck as std::array
					counter++;
				}
			}
		}

	}
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(Deck.begin(), Deck.end(), std::default_random_engine(seed));

}

Set_Deck::~Set_Deck()
{

}

Set_Card Set_Deck::getCardFromDeck()
{

	for (int i = 0; i < 81; i++)
	{
		if (Deck[i].getCardId() > 0)
		{
			Set_Card temp = Deck[i];
			Deck[i].delCard();
			// cout << "getCardFromDeck CardId:" << Deck[i].getCardId() << endl; // debug-code
			return temp;

			break;
		}
	}

}

int Set_Deck::Set_getDeckRemainingCards()
{
	int count = 81;
	for (int i = 0; i < 81; i++)
	{
		if (Deck[i].getCardId() < 0)
		{
			count--;
		}
		else
		{
			return count;
		}
	}
}
void Set_Deck::Set_PrintDeck()
{
	cout << "Kartenstapel:" << endl;
	for (int i = 0; i < 81; i++)
	{
		cout << "Kartennr.: " << Deck[i].getCardId() << "\t" << " Form: " << Deck[i].getCardForm() << "\t" << " Farbe: " << Deck[i].getCardFarbe() << "\t" << " Fuellung: " << Deck[i].getCardFuellung() << "\t" << "Anzahl: " << Deck[i].getCardAnzahl() << endl;

	}
}

/*Set_TheTwelve::Set_TheTwelve()
{

}*/


array <Set_Card, 15> Set_Deck::Set_GetStartUpTheTwelve()
{
	//array <Set_Card, 12> TheTwelve;
	for (int i = 0; i <= 11; i++)
	{
			TheTwelve[i] = getCardFromDeck();
	}
	return TheTwelve;
}

array <Set_Card, 15> Set_Deck::Set_GetTheTwelve()
{
	return TheTwelve;
}

void Set_Deck::Set_SetTheTwelve(Set_Card card, int position)
{
	//TheTwelve[position] = getCardFromDeck();
	TheTwelve[position] = card;
}

Set_Card Set_Deck::Set_GetCardFromTwelve(int position)
{
	return (TheTwelve[position]);
}

/*void Set_TheTwelve::Set_PrintTheTwelve()
{
	array <Set_Card, 12> TheTwelve; //obsolete code...
	cout << "12 Karten:" << endl;
	for (int i = 0; i < 12; i++)
	{
		cout << "Kartennr.: " << TheTwelve[i].getCardId() << "\t" << " Form: " << TheTwelve[i].getCardForm() << "\t" << " Farbe: " << TheTwelve[i].getCardFarbe() << "\t" << " Fuellung: " << TheTwelve[i].getCardFuellung() << "\t" << "Anzahl: " << TheTwelve[i].getCardAnzahl() << endl;

	}
}*/





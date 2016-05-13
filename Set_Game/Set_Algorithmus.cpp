#include "stdafx.h"
#include "Set_Algorithmus.h"
#include "Set_Repository.h"
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <array>

using namespace std;

Set_Algorithmus::Set_Algorithmus() // ich bin ein com // vom 
{
	points = 0;
}


Set_Algorithmus::~Set_Algorithmus()
{
}

bool Set_Algorithmus::CheckForSet(Set_Card a, Set_Card b, Set_Card c)
{
	if (((a.getCardAnzahl() == b.getCardAnzahl()) || (a.getCardAnzahl() == c.getCardAnzahl()) || (b.getCardAnzahl() == c.getCardAnzahl())) &&
		((a.getCardAnzahl() != b.getCardAnzahl()) || (a.getCardAnzahl() != c.getCardAnzahl())))
	{
		return false;
	}
	if (((a.getCardForm() == b.getCardForm()) || (a.getCardForm() == c.getCardForm()) || (b.getCardForm() == c.getCardForm())) &&
		((a.getCardForm() != b.getCardForm()) || (a.getCardForm() != c.getCardForm())))
	{
		return false;
	}
	if (((a.getCardFarbe() == b.getCardFarbe()) || (a.getCardFarbe() == c.getCardFarbe()) || (b.getCardFarbe() == c.getCardFarbe())) &&
		((a.getCardFarbe() != b.getCardFarbe()) || (a.getCardFarbe() != c.getCardFarbe())))
	{
		return false;
	}
	if (((a.getCardFuellung() == b.getCardFuellung()) || (a.getCardFuellung() == c.getCardFuellung()) || (b.getCardFuellung() == c.getCardFuellung())) &&
		((a.getCardFuellung() != b.getCardFuellung()) || (a.getCardFuellung() != c.getCardFuellung())))
	{
		return false;
	}

	points++;
	return true;
}

bool Set_Algorithmus::CheckBuildUp(array <Set_Card, 12> CardsUp)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Set_Algorithmus::CheckForSet(CardsUp[i], CardsUp[j + 1], CardsUp[j + 2]) == true)
			{
				/*CardsUp[i].printCard();
				CardsUp[j+1].printCard();
				CardsUp[j+2].printCard();*/
				return true;
			}
		}
	}
	return false;
}

void ThreeButtonsSet()
{

}

int Set_Algorithmus::getPoints()
{
	return points;
}


#include "stdafx.h"

#include "Set_Algorithmus.h"
#include "Set_Repository.h"
#include "Set_GameDlg.h"
#include "Resource.h"
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <array>

using namespace std;

Set_Algorithmus::Set_Algorithmus() 
{
	points = new int[4];
}

Set_Algorithmus::Set_Algorithmus(int anzahl, string *spieler)
{
	points = new int[anzahl];
	spieler_name = new string[anzahl];
	for (int i = 0; i < anzahl; i++)
	{
		spieler_name[i] = *spieler;
	}
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
	return true;
}

bool Set_Algorithmus::CheckBuildUp(array <Set_Card, 12> CardsUp)
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			for (int k = 11; k > j; k--)
			{
				if (Set_Algorithmus::CheckForSet(CardsUp[i], CardsUp[j], CardsUp[k]) == true)
				{
					return true;
				}
			}
		}
	}
	return false;
}

void Set_Algorithmus::BuildtheDeck(array<Set_Card, 12> CardsUp, CSet_GameDlg *Dlg)
{
	for (int i = 0; i < 12; i++)
	{
		CBitmap bmp;
		bmp.LoadBitmap(CardsUp[i].getCardId());
		CButton* pButton = (CButton*)Dlg->GetDlgItem(buttons_array[i]);
		pButton->ModifyStyle(0, BS_BITMAP);
		pButton->SetBitmap(bmp);
	}
}

void Set_Algorithmus::BuildtheDeckThreeMore(Set_Card one, Set_Card two, Set_Card three, array <Set_Card, 12> CardsUp, CSet_GameDlg *Dlg)
{
	for (int i = 0; i < 12; i++)
	{
		CBitmap bmp;
		bmp.LoadBitmap(CardsUp[i].getCardId());
		CButton* pButton = (CButton*)Dlg->GetDlgItem(buttons_array[i]);
		pButton->ModifyStyle(0, BS_BITMAP);
		pButton->SetBitmap(bmp);
	}
	
	CBitmap bmp1;
	bmp1.LoadBitmap(one.getCardId());
	CButton* pButton1 = (CButton*)Dlg->GetDlgItem(buttons_array[12]);
	pButton1->ModifyStyle(0, BS_BITMAP);
	pButton1->SetBitmap(bmp1);
	
	CBitmap bmp2;
	bmp2.LoadBitmap(two.getCardId());
	CButton* pButton2 = (CButton*)Dlg->GetDlgItem(buttons_array[13]);
	pButton2->ModifyStyle(0, BS_BITMAP);
	pButton2->SetBitmap(bmp2);
	
	CBitmap bmp3;
	bmp3.LoadBitmap(three.getCardId());
	CButton* pButton3 = (CButton*)Dlg->GetDlgItem(buttons_array[14]);
	pButton3->ModifyStyle(0, BS_BITMAP);
	pButton3->SetBitmap(bmp3);
}

void ThreeButtonsSet()
{

}

int Set_Algorithmus::getPoints(int player)
{
	return points[player];
}

void Set_Algorithmus::setPoints(int player, int point)
{
	points[player] += point;
}

string Set_Algorithmus::getPlayer(int player)
{
	return spieler_name[player];
}


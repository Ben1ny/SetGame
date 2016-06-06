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
	buttons_array = new int[15]{ IDC_Karte0, IDC_Karte1, IDC_Karte2, IDC_Karte3, IDC_Karte4, IDC_Karte5, IDC_Karte6, IDC_Karte7, IDC_Karte8,
		IDC_Karte9, IDC_Karte10, IDC_Karte11, IDC_Karte12, IDC_Karte13, IDC_Karte14 };
	currentplayer = 4;
	//current_player_array = new int[4]{ IDC_Sp1_Punkte, IDC_Sp2_Punkte, IDC_Sp3_Punkte, IDC_Sp4_Punkte};
	auswahl_check = new Set_Card[3]{};
	threeforcheck = 0;
	zwischenspeicher = new int[3]{0};
	lastbutton = 15;
	threemoreflag = false;
	threeontop = new bool[3]{ false, false, false };
	points = new int[4]{ 0, 0, 0, 0 };
	spieler_name = new CString[4];
	numberofplayers = 0;
	/*for (int i = 0; i < 4; i++)
	{
		spieler_name[i] = ("Spieler"+i);
	}*/
}

Set_Algorithmus::Set_Algorithmus(int anzahl, string *spieler)
{
	/*points = new int[anzahl];
	spieler_name = new string[anzahl];
	for (int i = 0; i < anzahl; i++)
	{
		spieler_name[i] = *spieler;
	}*/
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

bool Set_Algorithmus::CheckBuildUp(array <Set_Card, 15> CardsUp)
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

void Set_Algorithmus::BuildtheDeck(array<Set_Card, 15> CardsUp, CSet_GameDlg *Dlg)
{
	for (int i = 0; i <= 11; i++)
	{
		CBitmap bmp;
		bmp.LoadBitmap((CardsUp[i].getCardId()));
		CButton* pButton = (CButton*)Dlg->GetDlgItem(buttons_array[i]);
		pButton->ModifyStyle(0, BS_BITMAP);
		pButton->SetBitmap(bmp);
	}

	for (int k = 0; k <= 11; k++)
	{
		CButton* pButton = (CButton*)Dlg->GetDlgItem(buttons_array[k]);
		pButton->EnableWindow(true);
	}
}

void Set_Algorithmus::BuildtheDeckThreeMore(array <Set_Card, 15> CardsUp, CSet_GameDlg *Dlg)
{
	for (int i = 0; i <= 14; i++)
	{
			CBitmap bmp;
			bmp.LoadBitmap(CardsUp[i].getCardId());
			CButton* pButton = (CButton*)Dlg->GetDlgItem(buttons_array[i]);
			pButton->ModifyStyle(0, BS_BITMAP);
			pButton->SetBitmap(bmp);
	}

	for (int k = 0; k <= 14; k++)
	{
		CButton* pButton = (CButton*)Dlg->GetDlgItem(buttons_array[k]);
		pButton->EnableWindow(true);
	}
}

void Set_Algorithmus::ThreeButtonsSet(Set_Deck &deck, array<Set_Card, 15> &CardsUp, Set_Card &checkCard, int player, int buttonnumber, CSet_GameDlg *Dlg)
{
	if (threeforcheck <= 2 && lastbutton != buttonnumber)
	{
		lastbutton = buttonnumber;
		auswahl_check[threeforcheck] = checkCard;
		zwischenspeicher[threeforcheck] = buttonnumber;
		threeforcheck++;
		CButton* pButton = (CButton*)Dlg->GetDlgItem(buttons_array[buttonnumber]);
		pButton->EnableWindow(false);
	}
	if(threeforcheck == 3)
	{
		currentplayer = 4;			// wird auf 4 gesetzt damit neue Auswahl nötig ist bei Kartenwahl
		lastbutton = 15;			// wird auf 15 gesetzt damit kein Konflikt mit den anderen Buttons am anfang besteht.
		threeforcheck = 0;
		if (Set_Algorithmus::CheckForSet(auswahl_check[0], auswahl_check[1], auswahl_check[2]) == true)
		{
			Set_Algorithmus::setPoints(player, 1);
			for (int i = 0; i <= 2; i++)
			{
				if(zwischenspeicher[i] < 12)
				{
					if (threemoreflag == true)
					{
						for (int j = 0; j <= 2; j++)
						{
							if (threeontop[j] == true)
							{
								deck.Set_SetTheTwelve(deck.Set_GetCardFromTwelve(j + 12), zwischenspeicher[i]);
								threeontop[j] = false;
								CButton* pButton = (CButton*)Dlg->GetDlgItem(buttons_array[j+12]);
								pButton->ModifyStyle(0, BS_BITMAP);
								pButton->SetBitmap(false);
								pButton->EnableWindow(false);
								break;
							}
						}
						
					}
					else
					{
						//deck.Set_SetTheTwelve(deck.getCardFromDeck(), zwischenspeicher[i]);
						deck.Set_SetTheTwelve(deck.getCardFromDeck(), zwischenspeicher[i]);
					}
					if ((threeontop[0] == false) && (threeontop[1] == false) && (threeontop[2] == false))
					{
						threemoreflag = false;
					}
				}
				else if(zwischenspeicher[i] >= 12)
				{
					CButton* pButton = (CButton*)Dlg->GetDlgItem(buttons_array[zwischenspeicher[i]]);
					pButton->ModifyStyle(0, BS_BITMAP);
					pButton->SetBitmap(false);
					pButton->EnableWindow(false);
					threeontop[(zwischenspeicher[i] - 12)] = false;
				}
			}
			//hier weiter machen
			//Set_Algorithmus::BuildtheDeck(deck.Set_GetStartUpTheTwelve(), Dlg);
			Set_Algorithmus::BuildtheDeck(deck.Set_GetTheTwelve(), Dlg);
		}
		for (int k = 0; k <= 2; k++)
		{
			if (zwischenspeicher[k] <= 11)
			{
				CButton* pButton = (CButton*)Dlg->GetDlgItem(buttons_array[zwischenspeicher[k]]);
				pButton->EnableWindow(true);
			}
		}
	}
	if ((threeontop[0] == false) && (threeontop[1] == false) && (threeontop[2] == false))
	{
		threemoreflag = false;
	}

}

void Set_Algorithmus::GetThreeMore(Set_Deck &deck, array <Set_Card, 15> &CardsUp)
{
	threemoreflag = true;
	for (int i = 12; i <= 14; i++)
	{
		deck.Set_SetTheTwelve(deck.getCardFromDeck(), i);
	}
	for (int i = 0; i <= 2; i++)
	{
		threeontop[i] = true;
	}
}

int Set_Algorithmus::getPoints(int player)
{
	return points[player];
}

void Set_Algorithmus::setPoints(int player, int point)
{
	points[player] += point;
}



CString Set_Algorithmus::getName(int player)
{
	return spieler_name[player];
}
void Set_Algorithmus::setName(int i, CString name)
{
	spieler_name[i] = name;
}

void Set_Algorithmus::displayPoints(CSet_GameDlg *Dlg)
{
	CString point_s = L"";
	point_s.Format(_T("%d"), (getPoints(0)));
	Dlg->GetDlgItem(IDC_Sp1_Punkte)->SetWindowTextW(point_s);
	point_s.Format(_T("%d"), (getPoints(1)));
	Dlg->GetDlgItem(IDC_Sp2_Punkte)->SetWindowTextW(point_s);
	point_s.Format(_T("%d"), (getPoints(2)));
	Dlg->GetDlgItem(IDC_Sp3_Punkte)->SetWindowTextW(point_s);
	point_s.Format(_T("%d"), (getPoints(3)));
	Dlg->GetDlgItem(IDC_Sp4_Punkte)->SetWindowTextW(point_s);
}

void Set_Algorithmus::setCurrentPlayer(int who)
{
	currentplayer = who;
}
int Set_Algorithmus::getCurrentPlayer()
{
	return currentplayer;
}

int Set_Algorithmus::getNumberOfPlayers()
{
	return numberofplayers;
}
void Set_Algorithmus::setNumberOfPlayers(int number)
{
	numberofplayers = number;
}
/*****************************************
** Benjamin Kastl	
** Matrikelnummer 367882
**
*****************************************/

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

//Constructor from class Set_Algorithmus
Set_Algorithmus::Set_Algorithmus() 
{
	buttons_array = new int[15]{ IDC_Karte0, IDC_Karte1, IDC_Karte2, IDC_Karte3, IDC_Karte4, IDC_Karte5, IDC_Karte6, IDC_Karte7, IDC_Karte8,
		IDC_Karte9, IDC_Karte10, IDC_Karte11, IDC_Karte12, IDC_Karte13, IDC_Karte14 };
	threeontop = new bool[3]{ false, false, false };
	auswahl_check = new Set_Card[3]{};
	zwischenspeicher = new int[3]{0};
	points = new int[4]{ 0, 0, 0, 0 };
	spieler_name = new CString[4];

	threeforcheck = 0;
	lastbutton = 15;
	currentplayer = 4;
	numberofplayers = 0;
	//Flaggs
	threemoreflag = false;
	endgame = false;
	threecardbuttonflag = true;
}

Set_Algorithmus::~Set_Algorithmus()
{
	
}

//Function to check the attributes from three Cards an a Set, if there is no Set return false else return true
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
//Function to check twelve Cards on a Set with the Function CheckForSet if there is minimum one Set return true else return false
bool Set_Algorithmus::CheckBuildUp(array <Set_Card, 15> CardsUp)
{
	for (int i = 0; i < 12; i++)			//three for-loops to check 12 cards for a set 
	{
		for (int j = 1; j < 11; j++)
		{
			for (int k = 11; k > j; k--)
			{
				if (Set_Algorithmus::CheckForSet(CardsUp[i], CardsUp[j], CardsUp[k]) == true)
				{
					return true;				//set
				}
			}
		}
	}
	return false;								//no set
}
//Function to place the twelve Bitmaps onto the 12 or 15 Buttons on the pitch and activate them
void Set_Algorithmus::BuildtheDeck(array<Set_Card, 15> CardsUp, CSet_GameDlg *Dlg, int anzahl)
{
	for (int i = 0; i <= anzahl; i++)				// for-loop to place the bitmaps on the buttons
	{
			CBitmap bmp;
			bmp.LoadBitmap((CardsUp[i].getCardId()));						
			CButton* pButton = (CButton*)Dlg->GetDlgItem(buttons_array[i]);		//create a pointer from type CButton to reference on a Dialog item id
			pButton->ModifyStyle(0, BS_BITMAP);
			pButton->SetBitmap(bmp);
			pButton->EnableWindow(true);
	}
	if (anzahl == 11)				//if 12 cards disable the buttons 12-14
	{
		for (int j = 12; j <= 14; j++)
		{
			CButton* pButton = (CButton*)Dlg->GetDlgItem(buttons_array[j]);
			pButton->ModifyStyle(0, BS_BITMAP);
			pButton->SetBitmap(false);
			pButton->EnableWindow(false);
		}
	}
}

//Function to catch three Buttons to check them on a Set and genarate three new Cards or switch the 13-15 Card with the empty place
void Set_Algorithmus::ThreeButtonsSet(Set_Deck &deck, array<Set_Card, 15> &CardsUp, Set_Card &checkCard, int player, int buttonnumber, CSet_GameDlg *Dlg)
{
	if (endgame == false)
	{
		if (threeforcheck <= 2 && lastbutton != buttonnumber)		//Check that the last pressed Button isnt the current pressed Button
		{
			lastbutton = buttonnumber;
			auswahl_check[threeforcheck] = checkCard;
			zwischenspeicher[threeforcheck] = buttonnumber;
			threeforcheck++;
			CButton* pButton = (CButton*)Dlg->GetDlgItem(buttons_array[buttonnumber]);
			pButton->EnableWindow(false);
		}
		if (threeforcheck == 3)										//activate if the player taken three cards
		{
			currentplayer = 4;			// wird auf 4 gesetzt damit neue Auswahl n�tig ist bei Kartenwahl
			lastbutton = 15;			// wird auf 15 gesetzt damit kein Konflikt mit den anderen Buttons am anfang besteht.
			threeforcheck = 0;			// reset the variable for a new player input
			if (Set_Algorithmus::CheckForSet(auswahl_check[0], auswahl_check[1], auswahl_check[2]) == true)		// check the input for a set
			{
				Set_Algorithmus::setPoints(player, 1);
				for (int i = 0; i <= 2; i++)
				{
					if (zwischenspeicher[i] < 12)			// check if the Buttonnumber are in the range of the normal 12 buttons
					{
						if (threemoreflag == true)			// if there are more then 12 cards on top swap the choosen cards with the cards from the buttons 13-15
						{
							for (int j = 0; j <= 2; j++)
							{
								if (threeontop[j] == true)
								{
									deck.Set_SetTheTwelve(deck.Set_GetCardFromTwelve(j + 12), zwischenspeicher[i]);
									threeontop[j] = false;
									CButton* pButton = (CButton*)Dlg->GetDlgItem(buttons_array[j + 12]);
									pButton->ModifyStyle(0, BS_BITMAP);
									pButton->SetBitmap(false);
									pButton->EnableWindow(false);
									break;
								}
							}

						}
						else//if there are only 12 cards
						{
							if (deck.Set_getDeckRemainingCards() > 0)		// if more then one card in the cardstack
							{
								deck.Set_SetTheTwelve(deck.getCardFromDeck(), zwischenspeicher[i]);//take one card from the stack and check if it was the last
								if (deck.Set_getDeckRemainingCards() == 0)
								{
									endgame = true;
								}
							}
							else//if there is no card in the cardstack set the endgameflag
							{
								endgame = true;
							}

						}
						if ((threeontop[0] == false) && (threeontop[1] == false) && (threeontop[2] == false))		//check if only 12 cards on table and clear the threemoreflag
						{

							threemoreflag = false;
						}
					}
					else if (zwischenspeicher[i] >= 12)				// if the button id is higher then 11 disable this button
					{
						CButton* pButton = (CButton*)Dlg->GetDlgItem(buttons_array[zwischenspeicher[i]]);
						pButton->ModifyStyle(0, BS_BITMAP);
						pButton->SetBitmap(false);
						pButton->EnableWindow(false);
						threeontop[(zwischenspeicher[i] - 12)] = false;
					}
				}
				if(endgame == false)		//if more then 0 cards in the stack build the deck 
				{
					Set_Algorithmus::BuildtheDeck(deck.Set_GetTheTwelve(), Dlg, 11); 
				}
				
			}
			else					//else case if there is no set and rea
			{
				for (int k = 0; k <= 2; k++)		//reactivate the three buttons 
				{
					CButton* pButton = (CButton*)Dlg->GetDlgItem(buttons_array[zwischenspeicher[k]]);
					pButton->EnableWindow(true);
				}
			}
			for (int k = 0; k <= 2; k++)			//reactivate the Buttons to play the next round
			{
				if (zwischenspeicher[k] <= 11)
				{
					CButton* pButton = (CButton*)Dlg->GetDlgItem(buttons_array[zwischenspeicher[k]]);
					pButton->EnableWindow(true);
				}
			}
		}
		if ((threeontop[0] == false) && (threeontop[1] == false) && (threeontop[2] == false))			//if only 12 cards on the table activate the button three more cards
		{
			threemoreflag = false;
			CButton* pButton1 = (CButton*)Dlg->GetDlgItem(IDC_ThreeCards);
			pButton1->EnableWindow(true);
		}
	}
	if(endgame == true)								//if case to check if its the end of the game
	{
		for(int l = 0; l <= 14; l++)				//for-loop to deactivate all of the buttons
		{
			CButton* pButton2 = (CButton*)Dlg->GetDlgItem(buttons_array[l]);
			pButton2->EnableWindow(false);
		}
		prime = 0;
		for (int m = 0; m <= 3; m++)				//loop to check who got the most points
		{
			for (int n = (m+1); n <= 3; n++)
			{
				if (points[m] < points[n])
				{
					prime = n;
				}
			}

		}
		CString winnerpoints;						// Display the messagebox with the winner
		CString winnername = L"Gewonnen hat: ";
		winnerpoints.Format(_T("Punkte: %d"), (points[prime]));
		winnername = winnername + spieler_name[prime];
		Dlg->MessageBox((winnerpoints), (winnername), MB_OK);
	}
}
//Function to generate three new Cards on the pitch
void Set_Algorithmus::GetThreeMore(Set_Deck &deck, array <Set_Card, 15> &CardsUp, CSet_GameDlg *Dlg)
{
	int help = 0;								// help variable to seht the threeontop array
	threemoreflag = true;						//Set the flag to show that there are 15 Cards on the table
	if (threecardbuttonflag == false)			//Flag to check which Three more Cards mode is activated
	{
		CButton* pButton1 = (CButton*)Dlg->GetDlgItem(IDC_ThreeCards);				//deactivate the Button ThreeMoreCards
		pButton1->EnableWindow(false);
	}
	

	for (int i = 12; i <= 14; i++)								// for-loop to generate three new Cards and 
	{
		deck.Set_SetTheTwelve(deck.getCardFromDeck(), i);
		threeontop[help] = true;
		help++;
	}
	/*for (int i = 0; i <= 2; i++)
	{
		threeontop[i] = true;
	}*/
}
//Functions to set and get the Points from the Player
int Set_Algorithmus::getPoints(int player)
{
	return points[player];
}
void Set_Algorithmus::setPoints(int player, int point)
{
	points[player] += point;
}
//Function to reset the Points after a Game
void Set_Algorithmus::resetPoints()
{
	for (int i = 0; i < 4; i++)
	{
		points[i] = 0;
	}
}
//Function to dispay the Points from all Players on the pitch
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
//Functions to set and get the Name from each Player
CString Set_Algorithmus::getName(int player)
{
	return spieler_name[player];
}
void Set_Algorithmus::setName(int i, CString name)
{
	spieler_name[i] = name;
}
//Functions to set and get the current Player
void Set_Algorithmus::setCurrentPlayer(int who)
{
	currentplayer = who;
}
int Set_Algorithmus::getCurrentPlayer()
{
	return currentplayer;
}
//Functions to set and get the number of the players
int Set_Algorithmus::getNumberOfPlayers()
{
	return numberofplayers;
}
void Set_Algorithmus::setNumberOfPlayers(int number)
{
	numberofplayers = number;
}
// Function to get an End of a Game
bool Set_Algorithmus::getEndGame()
{
	return endgame;
}
//Function to get the Flag that three more Cards are on the pitch
bool Set_Algorithmus::getThreeMoreFlag()
{
	return threemoreflag;
}

void Set_Algorithmus::setThreeButtonFlag(bool help)
{
	threecardbuttonflag = help;
}
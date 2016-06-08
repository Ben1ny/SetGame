/*****************************************
** Benjamin Kastl
** Matrikelnummer 367882
**
*****************************************/
#pragma once
#include <stdio.h>
#include <cstdlib>
#include "Set_Repository.h"
#include "Set_GameDlg.h"
#include "Resource.h"


class Set_Algorithmus
{
public:
	Set_Algorithmus();
	~Set_Algorithmus();

	bool CheckBuildUp(array <Set_Card, 15>);
	void BuildtheDeck(array <Set_Card, 15>, CSet_GameDlg *);
	void BuildtheDeckThreeMore(array <Set_Card, 15>, CSet_GameDlg *);
	bool CheckForSet(Set_Card, Set_Card, Set_Card);
	void ThreeButtonsSet(Set_Deck &, array <Set_Card, 15> &, Set_Card &, int, int, CSet_GameDlg *);
	void GetThreeMore(Set_Deck &, array <Set_Card, 15> &, CSet_GameDlg *);

	CString getName(int);
	void setName(int, CString);
	int getPoints(int);
	void setPoints(int, int);
	void displayPoints(CSet_GameDlg *);
	void setCurrentPlayer(int);
	int getCurrentPlayer();
	int getNumberOfPlayers();
	void setNumberOfPlayers(int);
	bool getEndGame();
	bool getThreeMoreFlag();
	void resetPoints();

private:

	bool *threeontop;
	int *points;
	int *result;
	int *zwischenspeicher;
	Set_Card *auswahl_check;
	CString *spieler_name;
	int *buttons_array;

	bool threemoreflag;
	bool endgame;
	int lastbutton;
	int threeforcheck;
	int currentplayer;
	int numberofplayers;
	int prime;
};



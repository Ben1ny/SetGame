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
	Set_Algorithmus(int, std::string*);
	~Set_Algorithmus();

	bool CheckBuildUp(array <Set_Card, 15>);
	void BuildtheDeck(array <Set_Card, 15>, CSet_GameDlg *);
	void BuildtheDeckThreeMore(array <Set_Card, 15>, CSet_GameDlg *);
	bool CheckForSet(Set_Card, Set_Card, Set_Card);
	void ThreeButtonsSet(Set_Deck &, array <Set_Card, 15> &, Set_Card &, int, int, CSet_GameDlg *);
	void GetThreeMore(Set_Deck &, array <Set_Card, 15> &);


	std::string getPlayer(int);
	int getPoints(int);
	void setPoints(int, int);

private:
	bool *threeontop;
	bool threemoreflag;
	int *points;
	int lastbutton;
	int threeforcheck;
	int *zwischenspeicher;
	Set_Card *auswahl_check;
	std::string *spieler_name;
	/*int buttons_array[15] = {IDC_Karte0, IDC_Karte1, IDC_Karte2, IDC_Karte3, IDC_Karte4, IDC_Karte5, IDC_Karte6, IDC_Karte7, IDC_Karte8,
							IDC_Karte9, IDC_Karte10, IDC_Karte11, IDC_Karte12, IDC_Karte13, IDC_Karte14};*/
	int *buttons_array;

};



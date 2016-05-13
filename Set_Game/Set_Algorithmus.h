#pragma once
#include <stdio.h>
#include <cstdlib>
#include "Set_Repository.h"
#include <array>

class Set_Algorithmus
{
public:
	Set_Algorithmus();
	~Set_Algorithmus();

	bool CheckBuildUp(array <Set_Card, 12>);
	bool CheckForSet(Set_Card, Set_Card, Set_Card);

	int getPoints();

private:
	int points;
};



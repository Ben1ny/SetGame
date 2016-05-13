#include "stdafx.h"
#include "Set_BuildUp.h"


Set_BuildUp::Set_BuildUp()
{
}

Set_BuildUp::Set_BuildUp(int anzahl)
{
	spielerAnzahl = new CString[anzahl];
}


Set_BuildUp::~Set_BuildUp()
{
}

void Set_BuildUp::setName(CString name)
{
	spielerAnzahl[0] = name;
}

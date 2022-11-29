/****************************************************************************
**
** Classe Agenda
** Date: 2021-10-25
** Based on previous material (2022-03-19)
** Leonard Pouliot (2150965) et Xavier Pinsonneault (2020487)
**
****************************************************************************/

#include <string>
#include "Agenda.h"

Agenda::Agenda(std::string name, std::string dateTime)
	: AbsDocument(name, dateTime)
{
}

Agenda* Agenda::clone(void) const
{
	return new Agenda(*this);
}
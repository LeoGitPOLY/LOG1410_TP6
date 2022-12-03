/****************************************************************************
**
** Classe Minutes
** Date: 2021-10-25
** Based on previous material (2022-03-19)
** Leonard Pouliot (2150965) et Xavier Pinsonneault (2020487)
**
****************************************************************************/

#include <string>
#include "Minutes.h"
#include "AddAnnotationVisitor.h"

Minutes::Minutes(std::string name, std::string dateTime)
	: AbsDocument(name, dateTime)
{
}

Minutes* Minutes::clone(void) const
{
	return new Minutes(*this);
}

AbsDirectoryComponent& Minutes::accept(AddAnnotationVisitor& v) const
{
	return v.processMinutes(*this);
}
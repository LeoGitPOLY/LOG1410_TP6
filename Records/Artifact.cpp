/****************************************************************************
**
** Classe Artifact
** Date: 2021-10-25
** Based on previous material (2022-03-19)
** Leonard Pouliot (2150965) et Xavier Pinsonneault (2020487)
**
****************************************************************************/

#include "Artifact.h"

Artifact::Artifact(std::string name, const AbsDirectoryComponent& document)
	: AbsInstanceComponent(name), m_document(document)
{
}

Artifact* Artifact::clone() const
{
	return new Artifact(*this);
}

const AbsDirectoryComponent& Artifact::getDocument() const
{
	return m_document;
}

std::ostream& Artifact::printToStream(std::ostream& o) const
{
	o << "Artifact: " << getName() << std::endl;
	
	indent(o);
	o << "    --> Document: " << getDocument().getName() << std::endl;

	return o;
}


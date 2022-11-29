/****************************************************************************
**
** Classe Directory
** Date: 2021-10-25
** Based on previous material (2022-03-19)
** Leonard Pouliot (2150965) et Xavier Pinsonneault (2020487)
**
****************************************************************************/

#include <string>
#include "Directory.h"
#include "AbsDocument.h"

int Directory::m_indent = 0;

Directory::Directory(std::string name)
	: AbsDirectoryComponent(name)
{
}

Directory::Directory(const Directory& mdd)
	: AbsDirectoryComponent(mdd.m_name)
{
	for (auto it = cbegin(); it != cend(); it++)
		addDirectoryComponent(*it);

}

Directory* Directory::clone(void) const
{
	return new Directory(*this);
}

AbsDirectoryComponent& Directory::addDirectoryComponent(const AbsDirectoryComponent& member)
{
	AbsDirectoryComponent* memberPtr = member.clone();
	m_documents.push_back(DirectoryComponentPtr(memberPtr));

	return *memberPtr;
}

DirectoryComponentIterator Directory::begin()
{
	return m_documents.begin();
}

DirectoryComponentIterator_const Directory::cbegin() const
{
	return m_documents.cbegin();
}

DirectoryComponentIterator_const Directory::cend() const
{
	return m_documents.cend();
}

DirectoryComponentIterator Directory::end()
{
	return m_documents.end();
}

void Directory::deleteDirectoryComponent(DirectoryComponentIterator_const child)
{
	m_documents.erase(child);
}

void Directory::deleteAllComponents(void)
{
	for (auto it = begin(); it != end(); it++)
		deleteDirectoryComponent(it);

}

const AbsDocument* Directory::findDocument(std::string productName) const
{
	const AbsDocument* foundDocument = nullptr;

	for (auto it = cbegin(); it != cend(); it++)
		if (it->getName() == productName)
			foundDocument = dynamic_cast<AbsDocument*>(it->clone());

	return foundDocument;
}

std::ostream& Directory::printToStream(std::ostream& o) const
{
	o << "Directory: " << getName() << std::endl;
	m_indent++;

	for (const DirectoryComponentPtr& dir : m_documents)
	{
		indent(o);
		o << *dir << std::endl;
	}

	m_indent--;
	return o;
}

std::ostream& Directory::indent(std::ostream& o) const
{
	for (int i = 0; i < m_indent; ++i)
		o << '\t';
	return o;
}

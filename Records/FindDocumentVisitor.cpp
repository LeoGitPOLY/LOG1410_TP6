///////////////////////////////////////////////////////////
//  FindDocumentVisitor.cpp
//  Date: 2022-11-15
//  Original author: francois
///////////////////////////////////////////////////////////

#include "FindDocumentVisitor.h"
#include "Instance.h"
#include "Artifact.h"

FindDocumentVisitor::FindDocumentVisitor(const char* documentName)
	: m_searchedName(documentName), m_currentIterator(nullptr)
{
}

void FindDocumentVisitor::processArtifact(Artifact& artifact)
{
	// À compléter: vérifier si le nom du document correspond au nom cherché
	//              si oui, ajouter l'itérateur sur ce document dans la liste des artéfacts trouvés
}

void FindDocumentVisitor::processInstance(Instance& instance)
{
	// À compléter: itérer sur tous les éléments de l'instance
	//                   - conserver un pointeur sur l'itérateur de élément
	//                   - appliquer le visiteur sur l'élément
}

FoundArtifactIterator FindDocumentVisitor::begin()
{
	return m_artifactsFound.begin();
}

FoundArtifactIterator_const FindDocumentVisitor::cbegin() const
{
	return m_artifactsFound.begin();
}

FoundArtifactIterator_const FindDocumentVisitor::cend() const
{
	return m_artifactsFound.cend();
}

FoundArtifactIterator FindDocumentVisitor::end()
{
	return m_artifactsFound.end();
}

void FindDocumentVisitor::reset()
{
	m_artifactsFound.clear();
}


///////////////////////////////////////////////////////////
//  CountArtifactsVisitor.cpp
//  Implementation of the Class CountArtifactsVisitor
//  Date: 2022-11-15
//  Based on previous material (2022-04-02)
///////////////////////////////////////////////////////////

#include "CountArtifactsVisitor.h"
#include "Instance.h"
#include "Artifact.h"


CountArtifactsVisitor::CountArtifactsVisitor()
	: m_nbArtifacts(0)
{
}

void CountArtifactsVisitor::processInstance(Instance& instance) 
{
	for (auto it = instance.begin(); it != instance.end(); ++it)
	{
		it->accept(*this);
	}
}

void CountArtifactsVisitor::processArtifact(Artifact& artiface) 
{
	m_nbArtifacts++;
}


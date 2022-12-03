/****************************************************************************
**
** Classe Instance
** Date: 2021-10-25
** Based on previous material (2022-03-19)
** Leonard Pouliot (2150965) et Xavier Pinsonneault (2020487)
**
****************************************************************************/

#include "Instance.h"
#include "AbsInstanceVisitor.h"

Instance::Instance(std::string name)
    : AbsInstanceComponent(name)
{
}

Instance::Instance(const Instance& mdd)
	: AbsInstanceComponent(mdd.getName())
{
	for (auto& element : mdd.m_instanceContainer)
		addInstanceComponent(*element);	
}

Instance* Instance::clone() const
{
	return new Instance(*this);
}


InstanceComponentIterator Instance::begin() {

	return m_instanceContainer.begin();
}


InstanceComponentIterator_const Instance::cbegin() const {

	return m_instanceContainer.cbegin();
}


InstanceComponentIterator_const Instance::cend() const
{
	return m_instanceContainer.cend();
}

InstanceComponentIterator Instance::end()
{
	return  m_instanceContainer.end();
}

AbsInstanceComponent& Instance::addInstanceComponent(const AbsInstanceComponent& member)
{
	AbsInstanceComponent* memberPtr = member.clone();
	m_instanceContainer.push_back(InstanceComponentPtr(memberPtr));

	return *memberPtr;
}

void Instance::deleteInstanceComponent(InstanceComponentIterator_const child)
{
	m_instanceContainer.erase(child);
}

void Instance::deleteAllComponents(void)
{
	for (auto it = begin(); it != end(); it++)
		deleteInstanceComponent(it);
}

std::ostream& Instance::printToStream(std::ostream& o) const
{
	o << getName() << std::endl;
	int index = 0;
	m_indent++;

	for (const InstanceComponentPtr& inst : m_instanceContainer)
	{
		index++;
		indent(o);
		o << index << " " << * inst;
	}

	m_indent--;
	return o;
}

void Instance::accept(AbsInstanceVisitor& v)
{
	v.processInstance(*this);
}

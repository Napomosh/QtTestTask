#include "DocumentEntity.h"

namespace Entities 
{
	DocumentEntity::DocumentEntity(const std::string& name, const std::string& type) :
		m_name(name), m_type(type)
	{
	}

	DocumentEntity::DocumentEntity(std::string&& name, std::string&& type) :
		m_name(std::move(name)), m_type(std::move(type))
	{
	}

	std::string DocumentEntity::GetName() const
	{
		return m_name;
	}

	void DocumentEntity::SetName(const std::string& value)
	{
		m_name = value;
	}

	std::string DocumentEntity::GetType() const
	{
		return m_type;
	}

	void DocumentEntity::SetType(const std::string& value)
	{
		m_type = value;
	}
}

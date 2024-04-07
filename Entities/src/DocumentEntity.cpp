#include "DocumentEntity.h"

namespace Entities 
{
	DocumentEntity::DocumentEntity(const std::string& name, const std::string& type, 
								const std::string& dateCreated) :
		m_name(name), m_type(type), m_dateCreated(dateCreated)
	{
	}

	DocumentEntity::DocumentEntity(std::string&& name, std::string&& type, std::string&& dateCreated) :
		m_name(std::move(name)), m_type(std::move(type)),
		m_dateCreated(std::move(dateCreated))
	{
	}

	bool DocumentEntity::isValid() const
	{
		return !m_name.empty() && !m_type.empty();
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

	std::string DocumentEntity::GetTimeCreated() const
	{
		return m_dateCreated;
	}
}

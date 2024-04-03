#ifndef _DOCUMENT_ENTITY_H_
#define _DOCUMENT_ENTITY_H_

#include <string>

namespace Entities
{
	class DocumentEntity
	{
	public:
		DocumentEntity() = default;
		DocumentEntity& operator=(const DocumentEntity& val) = default;
		DocumentEntity& operator=(DocumentEntity&& val) = default;
		DocumentEntity(const DocumentEntity& val) = default;
		DocumentEntity(DocumentEntity&& val) = default;
		~DocumentEntity() = default;

		DocumentEntity(const std::string& name, const std::string& type);
		DocumentEntity(std::string&& name, std::string&& type);

		std::string GetName() const;
		void SetName(const std::string& value);

		std::string GetType() const;
		void SetType(const std::string& value);

	private:
		std::string m_name;
		std::string m_type;
	};
}

#endif //_DOCUMENT_ENTITY_H_
#include "DocumentEditorModel.h"

namespace Models {
	DocumentEditorModel::DocumentEditorModel(QObject* parent) : QObject(parent)
	{
	}

	void DocumentEditorModel::receiveDialogParams(const Entities::DocumentEntity& value)
	{
		m_curDocName = QString::fromStdString(value.GetName());
		m_curDocType = QString::fromStdString(value.GetType());
	}

	QString DocumentEditorModel::getCurrentName() const
	{
		return m_curDocName;
	}

	QString DocumentEditorModel::getCurrentType() const
	{
		return m_curDocType;
	}
}
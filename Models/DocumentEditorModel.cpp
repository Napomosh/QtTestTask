#include "DocumentEditorModel.h"

namespace Models {
	DocumentEditorModel::DocumentEditorModel(QObject* parent) : QObject(parent)
	{
	}

	void DocumentEditorModel::receiveDialogParams(const Entities::DocumentEntity& value, bool isEditorMode /*=true*/)
	{
		m_isEditorMode = isEditorMode;
		m_curDocName = QString::fromStdString(value.GetName());
		m_curDocType = QString::fromStdString(value.GetType());
		m_curTimeCreated = QString::fromStdString(value.GetTimeCreated());
	}

	QString DocumentEditorModel::getCurrentName() const
	{
		return m_curDocName;
	}

	QString DocumentEditorModel::getCurrentType() const
	{
		return m_curDocType;
	}

	QString DocumentEditorModel::getCurrentTimeCreated() const
	{
		return m_curTimeCreated;
	}

	bool DocumentEditorModel::getMode() const
	{
		return m_isEditorMode;
	}

	void DocumentEditorModel::resetState()
	{
		m_curDocName = QString();
		m_curDocType = QString();
		m_curTimeCreated = QString();
		m_isEditorMode = false;
	}
}
#ifndef _DOCUMENT_EDITOR_MODEL_H_
#define _DOCUMENT_EDITOR_MODEL_H_

#include <qqml.h>
#include <QObject>
#include "DocumentEntity.h"

namespace Models {
	class DocumentEditorModel : public QObject {
		Q_OBJECT
	public:
		DocumentEditorModel(QObject* parent = nullptr);

		// ����������, ����� ���� ����������� � ������ ��������������,
		// ����� �������� ��������� � ���� � ��� �� ���������
		Q_INVOKABLE void receiveDialogParams(const Entities::DocumentEntity& value);

		Q_INVOKABLE QString getCurrentName() const;
		Q_INVOKABLE QString getCurrentType() const;

	private:
		QString m_curDocName;
		QString m_curDocType;

	};
}

#endif //_DOCUMENT_EDITOR_MODEL_H_

#ifndef _DOCUMENT_EDITOR_MODEL_H_
#define _DOCUMENT_EDITOR_MODEL_H_

#include <QObject>
#include "DocumentEntity.h"

namespace Models {
	class DocumentEditorModel : public QObject {
		Q_OBJECT
	public:
		DocumentEditorModel(QObject* parent = nullptr);

		// используем, когда окно запускается в режиме редактирования,
		// чтобы получить параметры в окно и там их выставить
		Q_INVOKABLE void receiveDialogParams(const Entities::DocumentEntity& value, bool isEditorMode = true);

		Q_INVOKABLE QString getCurrentName() const;
		Q_INVOKABLE QString getCurrentType() const;
		Q_INVOKABLE bool getMode() const;

		// нужно чтобы сбросить установленные параметры перед закрытием окна
		Q_INVOKABLE void resetState();
	private:
		QString m_curDocName;
		QString m_curDocType;
		bool m_isEditorMode = false;
	};
}

#endif //_DOCUMENT_EDITOR_MODEL_H_

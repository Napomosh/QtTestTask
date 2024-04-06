#ifndef _DOCUMENT_VIEWER_H_
#define _DOCUMENT_VIEWER_H_

#include <qqml.h>
#include <QObject>
#include <QAbstractTableModel>

#include "DocumentEntity.h"

namespace Models
{
    class DocumentViewerModel : public QAbstractTableModel
    {
        Q_OBJECT
    public:
        DocumentViewerModel(QObject* pParent = nullptr);

        int rowCount(const QModelIndex & = QModelIndex()) const override;
        int columnCount(const QModelIndex & = QModelIndex()) const override;
        QVariant data(const QModelIndex& index, int role) const override;
        QHash<int, QByteArray> roleNames() const override;
        Q_INVOKABLE QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

        Q_INVOKABLE void setCurrentIndex(const QModelIndexList& value);

        Q_INVOKABLE QStringList getDocTypes() const;
        Q_INVOKABLE Entities::DocumentEntity getCurrentDocEntity() const;

        Q_INVOKABLE void openDocumentEditor();
        Q_INVOKABLE void closeDocumentEditor(const QString& docName, const QString& docType,
									const QString& docCreationTime, bool isEditorMode = false);

        Q_INVOKABLE void deleteCurrentRecord();
        Q_INVOKABLE bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;
    private:
        void addNewDocument(const Entities::DocumentEntity& value);
        void addNewDocument(const Entities::DocumentEntity& value, int from, int to);
        void editDocument(const Entities::DocumentEntity& value);

        enum ETableRoles
        {
	        TableDataRole = Qt::UserRole + 1,
            HeaderRole,
        };

        QVector<Entities::DocumentEntity> m_docs;
        QHash<int, QByteArray>m_roles;
        QStringList m_listDocTypes;

        QModelIndex m_currentIndex;
    };
}

#endif //_DOCUMENT_VIEWER_H_

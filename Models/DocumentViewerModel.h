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
        Q_INVOKABLE void deleteCurrentRecord();
        Q_INVOKABLE QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
        Q_INVOKABLE bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;
        Q_INVOKABLE void setCurrentIndex(const QModelIndexList& value);

    private:
        enum ETableRoles
        {
	        TableDataRole = Qt::UserRole + 1,
            HeaderRole,
        };

        QVector<Entities::DocumentEntity> m_docs;
        QHash<int, QByteArray>m_roles;

        QModelIndex m_currentIndex;
    };
}

#endif //_DOCUMENT_VIEWER_H_

#include "DocumentViewerModel.h"

#include <QQuickView>

#include "constants.h"

namespace Models
{
	DocumentViewerModel::DocumentViewerModel(QObject* pParent) : QAbstractTableModel(pParent)
	{
		// save possible data roles int table
		m_roles[TableDataRole] = "TableDataRole";
		m_roles[HeaderRole] = "HeaderRole";

		m_listDocTypes = { "Основной", "Тестовый" };
		m_docs.append(Entities::DocumentEntity{"Документ 1", "Обычный"});
		m_docs.append(Entities::DocumentEntity{"Документ 2",  "Вид документа"});
	}

	int DocumentViewerModel::rowCount(const QModelIndex&) const
	{
		return m_docs.size();
	}
	int DocumentViewerModel::columnCount(const QModelIndex&) const
	{
		return DOCUMENT_VIEWER_MAX_COLUMN_COUNT;
	}
	QVariant DocumentViewerModel::data(const QModelIndex& index, int role) const
	{
		if (role != TableDataRole)
			return QVariant();
		const auto& doc = m_docs.at(index.row());
		return index.column() % 2 == 0
		? QString(doc.GetName().c_str())
		: QString(doc.GetType().c_str());
	}

	QHash<int, QByteArray> DocumentViewerModel::roleNames() const
	{
		return m_roles;
	}

	void DocumentViewerModel::setCurrentIndex(const QModelIndexList& value)
	{
		if (value.isEmpty())
			return;
		m_currentIndex = value.first();
	}

	void DocumentViewerModel::openDocumentEditor()
	{
		QQuickView view;
		view.setSource(QUrl::fromLocalFile("../QtTestTask/Views/DocumentEditor.qml"));
		view.show();
	}

	void DocumentViewerModel::closeDocumentEditor(const QString& docName, const QString& docType,
									const QString& docCreationTime, bool isEditorMode /*=false*/)
	{
		Entities::DocumentEntity newDoc(docName.toStdString(), docType.toStdString());
		if (isEditorMode)
			editDocument(newDoc);
		else			
			addNewDocument(newDoc);
	}

	QStringList DocumentViewerModel::getDocTypes() const
	{
		return m_listDocTypes;
	}

	Entities::DocumentEntity DocumentViewerModel::getCurrentDocEntity() const
	{
		return m_docs.at(m_currentIndex.row());
	}

	void DocumentViewerModel::deleteCurrentRecord() {
		if (!m_currentIndex.isValid())
			return;
		auto r = removeRow(m_currentIndex.row());
		m_currentIndex = QModelIndex();
	}

	QVariant DocumentViewerModel::headerData(int section, Qt::Orientation orientation, int role) const
	{
		if (role != HeaderRole)
			return QVariant();
		switch(section)
		{
		case 0:
			return QString(DOCUMENT_VIEWER_FIRST_COLUMN_HEADER);
		case 1:
			return QString(DOCUMENT_VIEWER_SECOND_COLUMN_HEADER);
		default:
			return QVariant();
		}
	}

	bool DocumentViewerModel::removeRows(int row, int count, const QModelIndex& parent)
	{
		beginRemoveRows(parent, row, row);
		m_docs.remove(row);
		endRemoveRows();

		return true;
	}

	void DocumentViewerModel::addNewDocument(const Entities::DocumentEntity& value)
	{
		m_docs.append(value);
		addNewDocument(value, rowCount(), rowCount());
	}

	void DocumentViewerModel::addNewDocument(const Entities::DocumentEntity& value, int from, int to)
	{
		beginInsertRows(QModelIndex(), from, to);
		insertRow(from);
		endInsertRows();
	}

	void DocumentViewerModel::editDocument(const Entities::DocumentEntity& value)
	{
		auto& curDoc = m_docs[m_currentIndex.row()];
		curDoc = value;
		addNewDocument(value, m_currentIndex.row(), m_currentIndex.row());
	}
}

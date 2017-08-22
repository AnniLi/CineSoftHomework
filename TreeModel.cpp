#include "TreeModel.h"
#include "TreeManager.h"

TreeModel::TreeModel() {
}

TreeModel::TreeModel(TreeManager *manager) {
    _manager = manager;
}

TreeModel::~TreeModel() {
    delete _manager;
}

QVariant TreeModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    QObject *item = static_cast<QObject*>(index.internalPointer());
    return item->objectName();
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const {
    QObject* parentItem = static_cast<QObject*>(parent.internalPointer());
    if (!parentItem)
        parentItem = _manager->root();

    QObject *childItem = parentItem->children().at(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const {
    if (!index.isValid())
        return QModelIndex();

    QObject* childItem = static_cast<QObject*>(index.internalPointer());
    QObject* parentItem = childItem->parent();

    if (parentItem == _manager->root())
        return QModelIndex();

    int row = 0;
    if (parentItem->parent())
        row = parentItem->parent()->children().indexOf(parentItem);

    return createIndex(row, 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const {
    auto parentObject = static_cast<QObject*>(parent.internalPointer());
    if (!parentObject)
        return _manager->rootCount();

    return parentObject->children().count();
}

int TreeModel::columnCount(const QModelIndex&) const {
    return 1;
}

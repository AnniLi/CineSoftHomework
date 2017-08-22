#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>

class TreeManager;

class TreeModel : public QAbstractItemModel {
public:
    TreeModel();
    TreeModel(TreeManager*);
    ~TreeModel();

public:
    QVariant data(const QModelIndex &index, int role) const;
    QModelIndex index(int row, int column,
                          const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex & = QModelIndex()) const override;

private:
    TreeManager* _manager = nullptr;
};

#endif // TREEMODEL_H

#ifndef TREEMANAGER_H
#define TREEMANAGER_H

#include <QObject>
#include <QPair>

class TreeManager {
public:
    TreeManager();
    ~TreeManager();

    void addNode(int);
    void addNodes(std::vector<int>);

    void addDependency(QPair<int, int>);
    void addDependencies(std::vector<QPair<int, int>>);

    QObject* root() const;
    int rootCount() const;


private:
    QObject* _root = nullptr;
};

#endif // TREEMANAGER_H

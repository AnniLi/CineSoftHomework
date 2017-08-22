#include "TreeManager.h"

TreeManager::TreeManager() {
    _root = new QObject();
    _root->setObjectName("root");
}

TreeManager::~TreeManager() {
    delete _root;
}

void TreeManager::addNode(int key) {
    auto node = new QObject(_root);
    node->setObjectName(QString::number(key));
}

void TreeManager::addNodes(std::vector<int> nodes) {
    for (int key : nodes)
        addNode(key);
}

void TreeManager::addDependency(QPair<int, int> dependency) {
    auto parent = _root->findChild<QObject*>(QString::number(dependency.first));
    if (!parent) {
        parent = new QObject(_root);
        parent->setObjectName(QString::number(dependency.first));
    }

    auto child = _root->findChild<QObject*>(QString::number(dependency.second));
    if (!child) {
        child = new QObject(parent);
        child->setObjectName(QString::number(dependency.second));
    }
    else
        child->setParent(parent);
}

void TreeManager::addDependencies(std::vector<QPair<int, int> > dependencies) {
    for (auto pair : dependencies)
        addDependency(pair);
}

QObject *TreeManager::root() const {
    return _root;
}

int TreeManager::rootCount() const {
    return _root->children().count();
}






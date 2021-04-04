/*
** EPITECH PROJECT, 2021
** two_same
** File description:
** b-tree
*/

#include "bTree.hpp"
#include <iostream>

template <typename T>
bTree<T>::bTree(int value)
{
    _value = value;
}

template <typename T>
bTree<T> *bTree<T>::addNode(T value, bTree *tree)
{
    bTree *toReturn;

    if (this->_size == 0) {
        this->_size += 1;
        _value = value;
        return this;
    }
    this->_size += 1;
    if (!tree)
        tree = this;
    if (value > tree->_value)
        (tree->right) ? toReturn = addNode(value, tree->right) : toReturn = tree->right = new bTree(value);
    else if (value < tree->_value)
        (tree->left) ? toReturn = addNode(value, tree->left) : toReturn = tree->left = new bTree(value);
    else
        toReturn = nullptr;
    return toReturn;
}

template <typename T>
bool bTree<T>::searchValue(T value, bTree *tree)
{
    bool toReturn = true;

    if (!tree)
        tree = this;
    if (value > tree->_value)
        (tree->right) ? toReturn = searchValue(value, tree->right) : toReturn = false;
    else if (value < tree->_value)
        (tree->left) ? toReturn = searchValue(value, tree->left) : toReturn = false;
    return toReturn;
}

template <typename T>
void bTree<T>::rootToLeaf(bTree<T>* tree, std::vector<T> path)
{
    if (tree == NULL)
        return;

    path.push_back(tree->_value);
    if (tree->left == NULL && tree->right == NULL)
        _rootPath.push_back(path);
    else {
        rootToLeaf(tree->left, path);
        rootToLeaf(tree->right, path);
    }
}

template <typename T>
void bTree<T>::displayTree(int flag)
{
    rootToLeaf(this);
        for (auto arrIt : _rootPath) {
            for (auto it: arrIt)
                std::cout << it << " ";
        std::cout << std::endl;
        }
}
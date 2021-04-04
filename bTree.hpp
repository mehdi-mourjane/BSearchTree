/*
** EPITECH PROJECT, 2021
** two_same
** File description:
** b-tree
*/

#include <vector>

template <typename T>
class bTree
{
    public:
        bTree(int = 0);
        ~bTree() = default;

        void displayTree(int = 0);
        void rootToLeaf(bTree<T>* tree, std::vector<T> path = *new std::vector<T>);
        bool searchValue(T value, bTree *tree = nullptr);
        bTree *addNode(T value, bTree *tree = nullptr);

    private:
        std::vector<std::vector<T>> _rootPath;
        int _size;
        T _value;
        bTree *right;
        bTree *left;
};


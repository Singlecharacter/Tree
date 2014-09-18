#ifndef TREE_H
#define TREE_H

template <class T> class node
{
public:

    T value;

    node<T> *left;
    node<T> *right;

};

template <class T> class Tree
{
public:

    Tree();
    ~Tree();

private:



};

#endif // TREE_H

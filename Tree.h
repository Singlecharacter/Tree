#ifndef TREE_H
#define TREE_H

#include <iostream>

template <class T> class node
{
public:

    node();
    ~node();

    T value;

    node<T> *left;
    node<T> *right;

};

template <class T> class Tree
{
public:

    Tree();
    ~Tree();

    void startInOrder();
    void startPreOrder();
    void startPostOrder();

    bool add(T newValue);

private:

    void printInOrder(node<T> *start = NULL);
    void printPreOrder(node<T> *start = NULL);
    void printPostOrder(node<T> *start = NULL);

    node<T> *root;

};

//Node methods
template<class T> node<T>::node() : value(0), left(NULL), right(NULL)
{

}

template<class T> node<T>::~node()
{
    delete left;
    delete right;
}

//Tree methods

template<class T> Tree<T>::Tree() : root(NULL)
{

}

template<class T> Tree<T>::~Tree()
{
    delete root;
}

template<class T> bool Tree<T>::add(T newValue)
{
    if(root == NULL)
    {
        root = new node<T>();
        root->value = newValue;
    }
    else
    {
        node<T> *traverse = root;
        while(true)
        {
            if(newValue < traverse->value)
            {
                if(traverse->left == NULL)
                {
                    traverse->left = new node<T>();
                    traverse->left->value = newValue;
                    return true;
                }
                else
                {
                    traverse = traverse->left;
                }
            }
            else if(newValue > traverse->value)
            {
                if(traverse->right == NULL)
                {
                    traverse->right = new node<T>();
                    traverse->right->value = newValue;
                    return true;
                }
                else
                {
                    traverse = traverse->right;
                }
            }
            else
            {
                return false;
            }
        }
    }
}

template<class T> void Tree<T>::startInOrder()
{
    printInOrder(root);
}

template<class T> void Tree<T>::startPreOrder()
{
    printPreOrder(root);
}

template<class T> void Tree<T>::startPostOrder()
{
    printPostOrder(root);
}

template<class T> void Tree<T>::printInOrder(node<T> *start)
{
    if(start != NULL)
    {
        if(start->left != NULL)
        {
            printInOrder(start->left);
        }
        std::cout << start->value << " ";
        if(start->right != NULL)
        {
            printInOrder(start->right);
        }
    }
}

template<class T> void Tree<T>::printPreOrder(node<T> *start)
{
    if(start != NULL)
    {
        std::cout << start->value << " ";
        if(start->left != NULL)
        {
            printPreOrder(start->left);
        }
        if(start->right != NULL)
        {
            printPreOrder(start->right);
        }
    }
}

template<class T> void Tree<T>::printPostOrder(node<T> *start)
{
    if(start != NULL)
    {
        if(start->left != NULL)
        {
            printPostOrder(start->left);
        }
        if(start->right != NULL)
        {
            printPostOrder(start->right);
        }
        std::cout << start->value << " ";
    }
}

#endif // TREE_H

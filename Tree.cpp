#include "tree.h"

//Node methods
template<class T> node<T>::node() : value(0), left(NULL), right(NULL)
{

}

template<class T> node<T>::~node()
{
    delete left;
    delete right;
}

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

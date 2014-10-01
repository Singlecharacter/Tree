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

    node<T> *leftRotate(node<T> *h);
    node<T> *rightRotate(node<T> *h);

    void removeValue(T val);

private:

    void printInOrder(node<T> *start = NULL);
    void printPreOrder(node<T> *start = NULL);
    void printPostOrder(node<T> *start = NULL);
    int getLeftWeight(node<T> *start, int w);
    int getRightWeight(node<T> *start, int w);

    node<T> *root;
    int leftWeight;
    int rightWeight;

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

template<class T> Tree<T>::Tree() : root(NULL), leftWeight(0), rightWeight(0)
{

}

template<class T> Tree<T>::~Tree()
{
    delete root;
}

template<class T> bool Tree<T>::add(T newValue)
{
    std::cout << getLeftWeight(root, 0) << std::endl;
    std::cout << getRightWeight(root, 0) << std::endl;

    if(root == NULL)
    {
        root = new node<T>();
        root->value = newValue;
        return true;
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

    if(getRightWeight(root,0) > getLeftWeight(root, 0) + 1)
    {
        if(getLeftWeight(root->right,0) > getRightWeight(root->right,0) + 1)
        {
            rightRotate(root->right);
            leftRotate(root);
        }
        else
        {
            leftRotate(root);
        }
    }
    else if(getLeftWeight(root,0) > getRightWeight(root, 0) + 1)
    {
        if(getRightWeight(root->left,0) > getLeftWeight(root->left, 0) + 1)
        {
            leftRotate(root->left);
            rightRotate(root);
        }
        else
        {
            rightRotate(root);
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

template<class T> node<T> *Tree<T>::leftRotate(node<T> *h)
{
    node<T> *temp = h->right;
    h->right = temp->left;
    temp->left = h;
    return temp;
}

template<class T> node<T> *Tree<T>::rightRotate(node<T> *h)
{
    node<T> *temp = h->left;
    h->left = temp->right;
    temp->right = h;
    return temp;
}

template<class T> int Tree<T>::getLeftWeight(node<T> *start, int w)
{
    if(start != NULL)
    {
        if(start == root)
        {
            w = getLeftWeight(start->left, w);
            w = getRightWeight(start->left, w);
        }
        else
        {
            w = w + 1;
            w = getLeftWeight(start->left, w);
            w = getRightWeight(start->left, w);
            w = getLeftWeight(start->right, w);
            w = getRightWeight(start->right, w);
        }
    }

    return w;
}

template<class T> int Tree<T>::getRightWeight(node<T> *start, int w)
{
    if(start != NULL)
    {
        if(start == root)
        {
            w = getLeftWeight(start->right, w);
            w = getRightWeight(start->right, w);
        }
        else
        {
            w = w + 1;
            w = getLeftWeight(start->left, w);
            w = getRightWeight(start->left, w);
            w = getLeftWeight(start->right, w);
            w = getRightWeight(start->right, w);
        }
    }

    return w;
}
#endif // TREE_H

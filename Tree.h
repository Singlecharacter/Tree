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

    int countChildren(node<T> *n, int num);

private:

    void printInOrder(node<T> *start = NULL);
    void printPreOrder(node<T> *start = NULL);
    void printPostOrder(node<T> *start = NULL);
    int getLeftWeight(node<T> *start);
    int getRightWeight(node<T> *start);

    node<T> *addPostRoot(node<T> *n, T newVal);
    node<T> *removePostRoot(node<T> *n, T val);
    node<T> *deleteNode(node<T> *n);

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
    bool successFlag = false;

    if(root == NULL)
    {
        root = new node<T>();
        root->value = newValue;
    }
    else
    {
        root = addPostRoot(root,newValue);
    }

    std::cout << "Left weight: " << getLeftWeight(root) << std::endl;
    std::cout << "Right weight: " << getRightWeight(root) << std::endl;

    return successFlag;
}

template<class T> node<T> *Tree<T>::addPostRoot(node<T> *n, T newValue)
{
    if(n == NULL)
    {
        n = new node<T>();
        n->value = newValue;
        return n;
    }

    if(newValue < n->value)
    {
        n->left = addPostRoot(n->left,newValue);
    }

    if(newValue > n->value)
    {
        n->right = addPostRoot(n->right,newValue);
    }

    int balance = getLeftWeight(n) - getRightWeight(n);

    //Left left
    if(balance > 1 && newValue < n->left->value)
    {
        return rightRotate(n);
    }

    //Left Right
    if(balance > 1 && newValue > n->left->value)
    {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }

    //Right right
    if(balance < -1 && newValue > n->right->value)
    {
        return leftRotate(n);
    }

    //Right left
    if(balance < -1 && newValue < n->right->value)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }

    return n;
}

template<class T> void Tree<T>::removeValue(T val)
{
    if(root != NULL)
    {
        root = removePostRoot(root,val);
    }

    std::cout << "Left weight: " << getLeftWeight(root) << std::endl;
    std::cout << "Right weight: " << getRightWeight(root) << std::endl;
}

template<class T> node<T> *Tree<T>::removePostRoot(node<T> *n, T val)
{
    if(n == NULL)
    {
        return n;
    }

    if(val < n->value)
    {
        n->left = removePostRoot(n->left,val);
        return n;
    }

    if(val > n->value)
    {
        n->right = removePostRoot(n->right,val);
        return n;
    }

    return deleteNode(n);
}

template<class T> node<T> *Tree<T>::deleteNode(node<T> *n)
{
    if(n->left == NULL && n->right == NULL)
    {
        return NULL;
    }
    else
    {
        if(n->left != NULL)
        {
            node<T> *temp = n->left;
            n->left = deleteNode(n->left);
            return temp;
        }
        else
        {
            node<T> *temp = n->right;
            n->right = deleteNode(n->right);
            return temp;
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

template<class T> int Tree<T>::getLeftWeight(node<T> *start)
{
    if(start != NULL)
    {
        int w = countChildren(start->left,0);

        return w;
    }

    return 0;
}

template<class T> int Tree<T>::getRightWeight(node<T> *start)
{
    if(start != NULL)
    {
        int w = countChildren(start->right,0);

        return w;
    }

    return 0;
}

template<class T> int Tree<T>::countChildren(node<T> *n, int num)
{
    if(n != NULL)
    {
        num++;
        num = countChildren(n->left,num);
        num = countChildren(n->right,num);
    }
    else
    {
        return num;
    }
}

#endif // TREE_H

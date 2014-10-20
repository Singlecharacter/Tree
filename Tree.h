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

    node<T> *addPostRoot(node<T> *n, T newVal);

    int countChildren(node<T> *n, int num);

private:

    void printInOrder(node<T> *start = NULL);
    void printPreOrder(node<T> *start = NULL);
    void printPostOrder(node<T> *start = NULL);
    int getLeftWeight(node<T> *start);
    int getRightWeight(node<T> *start);

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

/*struct node* insert(struct node* node, int key)
{
    /* 1.  Perform the normal BST rotation
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* 2. Update height of this ancestor node
    node->height = max(height(node->left), height(node->right)) + 1;

    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer
    return node;
}*/

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

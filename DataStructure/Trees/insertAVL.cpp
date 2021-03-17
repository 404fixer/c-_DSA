#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
};

Node *newNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

int height(Node *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    return (ptr->height);
}

int balanceAVL(Node *ptr)
{
    if (ptr == NULL)
        return 0;
    return (height(ptr->left) - height(ptr->right));
}

Node *rightRotation(Node *head)
{
    Node *temp = head->left;
    Node *temp2 = temp->right;

    temp->right = head;
    head->left = temp2;

    head->height = max(height(head->left), height(head->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;

    return temp;
}

Node *leftRotation(Node *head)
{
    Node *temp = head->right;
    Node *temp2 = temp->left;

    temp->left = head;
    head->right = temp2;

    head->height = max(height(head->left), height(head->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;

    return temp;
}

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return newNode(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        return root;
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = balanceAVL(root);

    //LL case
    if (balance > 1 && value < ((root->left)->data))
        return rightRotation(root);
    //RR case
    if (balance < -1 && value > ((root->right)->data))
    {
        return leftRotation(root);
    }
    //LR case
    if (balance > 1 && value > ((root->left)->data))
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    //RL case
    if (balance < -1 && value < ((root->right)->data))
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;

    /* Constructing tree given in 
    the above figure */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* The constructed AVL Tree would be 
                30 
            / \ 
            20 40 
            / \ \ 
        10 25 50 
    */
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);

    return 0;
}
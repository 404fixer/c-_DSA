#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *root = NULL;

Node *getNewNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node *insert(Node *currRoot, int data)
{
    if (currRoot == NULL)
    {
        currRoot = getNewNode(data);
    }
    else if (data <= currRoot->data)
    {
        currRoot->left = insert(currRoot->left, data);
    }
    else
    {
        currRoot->right = insert(currRoot->right, data);
    }

    return currRoot;
}

void inOrder(Node *temp)
{
    if (temp == NULL)
        return;
    inOrder(temp->left);
    cout<<temp->data<<" ";
    inOrder(temp->right);
}

int main()
{
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 13);
    cout << "DATA INSERTED SUCCESSFULLY \n";

    inOrder(root);
    cout << endl;
}
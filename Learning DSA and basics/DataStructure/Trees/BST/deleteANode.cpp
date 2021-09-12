// In this program, we are visiting every node two times. So, time complexity is O(n^2).

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

Node *minNum(Node *temp)
{
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

Node *deleteNode(Node *currRoot, int value)
{
    if (currRoot == NULL)
    {
        return currRoot;
    }
    if (currRoot->data > value)
        currRoot->left = deleteNode(currRoot->left, value);
    else if (currRoot->data < value)
        currRoot->right = deleteNode(currRoot->right, value);
    else
    {
        //currRoot->data == value
        if (currRoot->left == NULL && currRoot->right == NULL)
        {
            delete currRoot;
            currRoot = NULL;
        }
        else if (currRoot->left == NULL)
        {
            Node *temp = currRoot;
            currRoot = currRoot->right;
            delete temp;
        }
        else if (currRoot->right == NULL)
        {
            Node *temp = currRoot;
            currRoot = currRoot->left;
            delete temp;
        }
        else
        {
            Node *temp = minNum(currRoot->right);
            currRoot->data = temp->data;
            currRoot->right = deleteNode(currRoot->right, temp->data);
        }
    }
    return currRoot;
}

void inOrder(Node *temp)
{
    if (temp == NULL)
        return;
    inOrder(temp->left);
    cout << temp->data << " ";
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
    // root = insert(root, 7);
    // root = insert(root, 4);
    // root = insert(root, 1);
    // root = insert(root, 6);
    // root = insert(root, 9);
    int value;
    cout << "Enter the value : ";
    cin >> value;

    inOrder(root);
    cout << endl;
    Node *temp = deleteNode(root, value);
    inOrder(root);
    cout << endl;
}
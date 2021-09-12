#include <bits/stdc++.h>
using namespace std;

class BstNode
{
public:
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode *root = NULL;

BstNode *getNewNode(int data)
{
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

BstNode *insert(BstNode *currRoot, int data)
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

bool Search(BstNode *currNode, int data)
{
    if (currNode == NULL)
        return false;
    if (currNode->data == data)
        return true;
    if (data <= currNode->data)
        return Search(currNode->left, data);
    else
        return Search(currNode->right, data);
}

void printBst(BstNode *temp)
{
    if (temp == NULL)
    {
        return;
    }
    if (temp->left == NULL)
    {
        cout << temp->data << endl;
    }
    else
    {
        printBst(temp->left);
        cout << temp->data << endl;
    }

    if (temp->right == NULL)
    {
        return;
    }
    else
    {
        printBst(temp->right);
    }
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

    // Search(root, 245) ? cout << "Found \n" : cout << "Not Found \n";
    // cout << root->data << endl;

    printBst(root);
}
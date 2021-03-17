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

void minNum(BstNode *tempHead)
{
    if (tempHead == NULL)
    {
        cout << "ERROR : Tree is empty.\n";
        return;
    }

    while (tempHead->left != NULL)
    {
        tempHead = tempHead->left;
    }
    cout << "Min Num is " << (tempHead->data) << endl;
}

void maxNum(BstNode *tempHead)
{
    if (tempHead == NULL)
    {
        cout << "ERROR : Tree is empty.\n";
        return;
    }
    while (tempHead->right != NULL)
    {
        tempHead = tempHead->right;
    }
    cout << "Max Num is " << (tempHead->data) << endl;
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

    minNum(root);
    maxNum(root);
}
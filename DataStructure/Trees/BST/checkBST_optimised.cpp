// In this program, we are visiting every node two times. So, time complexity is O(n^2).

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

bool isBST(BstNode *temp, int min, int max)
{
    // cout << temp->data << endl;
    if (temp == NULL)
        return true;
    if (temp->data > min && temp->data < max && isBST(temp->left, min, temp->data) && isBST(temp->right, temp->data, max))
        return true;
    else
        return false;
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
    cout << "DATA INSERTED SUCCESSFULLY \n";

    cout << isBST(root, INT_MIN, INT_MAX) << endl;
}
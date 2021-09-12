// BREADTH FIRST TRAVERSAL or LEVEL ORDER TRAVERSAL

#include <bits/stdc++.h>
#include <queue>
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

void levelOrderTraversal(BstNode *temp)
{
    if (root == NULL)
        return;
    queue<BstNode *> Q;
    Q.push(temp);
    while (!Q.empty())
    {
        BstNode *current = Q.front();
        cout << current->data << " ";
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
        Q.pop();
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

    levelOrderTraversal(root);
    cout << endl;
}
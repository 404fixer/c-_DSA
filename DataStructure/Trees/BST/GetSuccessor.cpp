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

Node *search(Node *temp, int value)
{
    if (temp == NULL)
        return NULL;
    if (value < temp->data)
        return search(temp->left, value);
    else if (value > temp->data)
        return search(temp->right, value);
    else
        return temp;
}

Node *GetSuccessor(Node *currRoot, int value)
{
    if (currRoot == NULL)
        return NULL;
    Node *current = search(currRoot, value);
    if (current->right != NULL)
    {
        return minNum(current->right);
    }
    else
    {
        Node *successor = NULL;
        Node *ancestor = currRoot;
        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor;
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
    // root = insert(root, 7);
    // root = insert(root, 4);
    // root = insert(root, 1);
    // root = insert(root, 6);
    // root = insert(root, 9);

    int value;
    cin >> value;
    Node *successor = GetSuccessor(root, value);
    cout << successor->data << endl;
}
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};

void printInReverse(Node *temp)
{
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    Node *head = new Node();
    head->prev = NULL;
    cin >> head->data;
    head->next = NULL;

    Node *temp = head;
    for (int i = 0; i < n; i++)
    {
        Node *newNode = new Node();
        cin >> newNode->data;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
        temp = newNode;
    }

    printInReverse(head);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void printLinkedList(Node *temp)
{
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    int n;
    cin >> n;

    Node *head = new Node();
    cin >> head->data;
    head->next = NULL;

    Node *temp2 = head;
    for (int i = 0; i < n; i++)
    {
        Node *temp = new Node();
        temp2->next = temp;
        cin >> temp->data;
        temp->next = NULL;
        temp2 = temp;
    }

    Node *newNode = new Node();
    cin >> newNode->data;
    newNode->next = head;
    head = newNode;

    printLinkedList(head);

    return 0;
}
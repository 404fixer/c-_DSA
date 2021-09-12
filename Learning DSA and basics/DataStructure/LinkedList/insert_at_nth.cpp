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
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node();
    head->data = 2;
    head->next = NULL;

    int n;
    cin >> n;

    Node *temp2 = head;
    for (int i = 0; i < n; i++)
    {
        Node *temp = new Node();
        temp2->next = temp;
        cin >> temp->data;
        temp->next = NULL;
        temp2 = temp;
    }

    printLinkedList(head);

    int position;
    cin >> position;

    Node *newNode = new Node();
    cin >> newNode->data;
    Node *temp3 = head;
    for (int i = 0; i < (position - 2) && temp3 != NULL; i++)
    {
        temp3 = temp3->next;
    }
    newNode->next = temp3->next;
    temp3->next = newNode;

    printLinkedList(head);

    return 0;
}
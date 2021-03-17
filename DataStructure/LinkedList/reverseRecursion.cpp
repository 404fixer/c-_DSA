#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *head = new Node();

void printLinkedList(Node *temp)
{
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseRecursion(Node *temp)
{
    if (temp->next == NULL)
    {
        head = temp;
        return;
    }
    reverseRecursion(temp->next);
    Node *q = temp->next;
    q->next = temp;
    temp->next = NULL;
}

int main()
{
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

    reverseRecursion(head);
    printLinkedList(head);

    return 0;
}
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

Node *reverseLinkedList(Node *head)
{
    Node *prev, *current, *next;
    prev = NULL;
    current = head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
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
    head = reverseLinkedList(head);
    printLinkedList(head);

    return 0;
}
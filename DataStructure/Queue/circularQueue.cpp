#include<bits/stdc++.h>
using namespace std;

class Queue {
    public:
    int front, rear, size;
    int *arr;

    //making constructor
    Queue(int s) {
        size = s;
        front = rear = -1;
        arr = new int[size];
    }

    void enqueue(int data);
    int dequeue();
    void displayQueue();
};

void Queue::enqueue(int data) {
    if((front == 0 && rear == size-1) || rear == front-1) {
        cout<<"Queue is full"<<endl;
        return ;
    } else if(front == -1 && rear == -1) {
        front = rear = 0;
    } else if(rear == size-1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }
    arr[rear] = data;
}

int Queue::dequeue() {
    int data;
    if(front == -1 && rear == -1) {
        cout<<"Queue is empty\n";
        return INT_MIN;
    } else if(front == 0 && rear == 0) {
        data = arr[front];
        front = rear = -1;
    } else {
        data = arr[front];
        front = ((front == (size-1)) ? (front%(size-1)) : (front+1));
    }
    return data;
}

// Function displaying the elements 
// of Circular Queue 
void Queue::displayQueue() 
{ 
    if (front == -1) 
    { 
        printf("\nQueue is Empty"); 
        return; 
    } 
    printf("\nElements in Circular Queue are: "); 
    if (rear >= front) 
    { 
        for (int i = front; i <= rear; i++) 
            cout<<arr[i]<<" "; 
    } 
    else
    { 
        for (int i = front; i < size; i++) 
            cout<<arr[i]<<" "; 

  
        for (int i = 0; i <= rear; i++) 
            cout<<arr[i]<<" "; 

    } }



int main() {
    Queue q(5);

// Inserting elements in Circular Queue 
    q.enqueue(14); 
    q.enqueue(22); 
    q.enqueue(13); 
    q.enqueue(-6); 
  
    // Display elements present in Circular Queue 
    q.displayQueue(); 
  
    // Deleting elements from Circular Queue 
    cout<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

  
    q.displayQueue(); 
  
    q.enqueue(9); 
    q.enqueue(20); 
    q.enqueue(5); 
  
    q.displayQueue(); 
  
    q.enqueue(20);
    return 0;
}
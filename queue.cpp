/*  Queue

    An implementation of a stack in C++. Where is it FIFO, so the first
    element would be the first to come out. As if you're lining up in a
    queue.
*/

#include <iostream>
#include <stack>


struct Node{
    int data;
    Node* next;
};
Node* front = NULL;
Node* rear = NULL;

//Add value into the queue
void Enqueue(int value){
    Node* temp = new Node();

    temp->data = value;
    temp->next = NULL;

    //If queue is empty
    if(front == NULL && rear == NULL){
        front = rear = temp; //Change both to be equal to the address of the new node
        return;
    }

    rear->next = temp; //Change the address to temp
    rear = temp; //Point to the newly created node
}

//Remove value from the queue
void Dequeue(){
    Node* temp = front;
    
    //No elements in the queue
    if(front == NULL){
        return;
    }

    //Queue is not empty
    if(front == rear){
        front = rear = NULL;
    }
    else{
        front = front->next;
    }

    free(temp);
}

int main()
{
    Enqueue(2);
    Enqueue(5);
    Enqueue(10);
    Dequeue();
    //Reverse();
    //Print();

    return 0;
}

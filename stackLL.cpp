/*  Stack (Linked List Implementation in C++)

    An implementation of a stack in C++. Where is it LIFO, so the last
    element would be the first to come out like a stack of plates.
    
    This is an object implementation of a stack.
*/

#include <iostream>

struct Node{
    int data;
    Node* link;
};
Node* top = NULL;


void Push(int value);
void Pop();
bool isEmpty();
int Top();
void Print();

int main()
{
    Push(2);
    Push(5);
    Push(10);
    Pop();
    Print();

    return 0;
}

//Add element to top of the stack
void Push(int value){
    Node* temp = new Node(); //create a node in the heap
    temp->data = value; //Set the data pointer to value
    temp->link = top; //Build the link to the previous node
    top = temp; //Update the top element
}

//Remove the top element of the stack
void Pop(){
    Node* temp;
    //No element to remove
    if(top == NULL){
        return;
    }
    
    temp = top; //create pointer to node temp
    top = top->link; //change the link to point to the next node
    free(temp); //Free memory
}

//Checks if the list is empty, if it his return true
bool isEmpty(){
    //If top is NULL there are no elements are in stack
    return top == NULL;
}

//Returns the top elements of the stack
int Top(){
     
    //If stack is not empty, return the top element
    if (!isEmpty()){
        return top->data;
    }
    else{
        printf("Error! There are no elements in the stack.\n");
        exit(1);
    }
}

//Prints out the stack
void Print(){
    Node* temp;
 
    //Check if stack is empty
    if (top == NULL){
        printf("Stack is empty.\n");
        return;
    }

    temp = top;
    while (temp != NULL){

        //Print node data
        printf("%d ", temp->data);

        //Assign temp link to temp
        temp = temp->link;
    }
}
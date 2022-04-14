/*  Stack (Array based in C++)

    An implementation of a stack in C++. Where is it LIFO, so the last
    element would be the first to come out like a stack of plates.
    
    There are better ways to implement a stack, but this way is a good
    way to understand how stacks work.
*/

#include <iostream>
#define MAXSIZE 101
int A[MAXSIZE];
int top = -1;
//using namespace std;

void Push(int value);
void Pop();
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

//Add an element to the top of the stack
void Push(int value){
    
    if(top == MAXSIZE-1){
        printf("Stack overflow error.\n");
        return;
    }
    
    A[++top] = value; //Add one to top and set the new value
}

//Take out the top/last element in the Stack
void Pop(){
    if(top == -1){
        printf("There is no element to take out.\n");
        return;
    }
    top--; //Decrease the top index by one
}

//Returns the most recently added element at the top of the stack
int Top(){
    return A[top];
}

//Print all the elements in the stack
void Print(){
    printf("The stack is: ");
    for(int i = 0; i <= top; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}
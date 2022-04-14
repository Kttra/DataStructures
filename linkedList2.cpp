/*
    Linked list implementation in C++ (Global Head)

    The purpose of this program is to show how to implement a linked list in C++.
    In this program we have head as a global variable for easier understanding,
    but it is possible to replace the it by passing it through print and insert
    instead.

    This program will also cover some recursive functions.
    Note the linked list index we start with in this program is at index 1.
*/

#include <iostream>

using std::cout;

struct Node{
	int data;
	Node* next;
};
struct Node* head;

void InsertAt(int nodeValue, int index);
void InsertAtEnd(int nodeValue);
void Insert(int nodeValue);
void Delete(int index);
void Reverse();
void Reverse(Node* p)
void Print();
void Print(Node* p);
void PrintBackwards(Node* p);

int main()
{
    head = NULL; //empty list
    cout << "How many numbers will be in the linked list? ";
    int listLength, nodeValue;
    scanf("%d", &listLength);
    
    for(int i = 0; i < listLength; i++){
        scanf("%d", &nodeValue);
        Insert(nodeValue);
    }
    InsertAt(2,1); //List: 2
    InsertAt(3,2); //List: 2, 3
    InsertAt(4,1); //List: 4, 2, 3
    InsertAt(5,2); //List: 4, 5, 2, 3
    Reverse();
    Print();

    return 0;
}

//Insert a value at start of the linked list
void Insert(int nodeValue){
    Node* temp = new Node();
    temp->data = nodeValue;
    temp->next = head;
    head = temp;
}

//Insert a value at the end of the linked list, head pass by reference
void InsertAtEnd(int nodeValue){
    //Allocate node
    Node* newNode = new Node();

    //Assign data element
    newNode->data = nodeValue;

    //Assign null to the next of new node
    newNode->next = NULL; 

    //Check if the Linked List is empty or not,
    //If empty make the new node as head 
    if(head == NULL) {
        head = newNode;
    }
    else {
        //Traverse to the last node
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        //Change the next of last node to new node
        temp->next = newNode;
    }   
}

//Insert value exactly into the given index
void InsertAt(int nodeValue, int index){
    Node* temp = new Node();
    temp->data = nodeValue;
    temp->next = NULL;
    
    if(index == 1){
        temp->next = head;
        head = temp;
        return;
    }

    Node* temp1 = head;
    for(int i = 0; i < index-2; i++){
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

//Delete node at the index
void Delete(int index){
    Node* temp1 = head;

    if(index == 1){
        head = temp1->next;
        free(temp1);
        return;
    }

    for(int i = 0; i < index-2; i++){
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next; //nth node
    temp1->next = temp2->next; //(n+1)th node
    free(temp2); //delete temp2
}

//Reverse the linked list recursively
void Reverse(Node* p){
    if(p->next == NULL){
        head = p;
        return;
    }
    Reverse(p->next);
}

//Reverses the linked list
void Reverse(){
    Node *current, *prev, *next;
    current = head;
    prev = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

//Print Recursively
void Print(Node* p){
    if(p == NULL) return;
    printf("%d ", p->data);
    Print(p->next);
}

//Print linked list backwards
void PrintBackwards(Node* p){
    if(p == NULL) return;
    PrintBackwards(p->next);
    printf("%d ", p->data);
}

//Print out the linked list
void Print(){
    printf("The list is: ");
    
    //Create temp head so we don't alter our linked list
    Node* temp = head;

    while(temp != NULL){
        printf(" %d", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

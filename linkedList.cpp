/*
    Linked list implementation in C++ (Local Head)

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

void Insert(Node* &head, int nodeValue);
void InsertAtEnd(Node* &head, int nodeValue);
void InsertAt(Node* &head, int nodeValue, int index);
void Delete(Node* &head, int index);
void Reverse(Node* &head);
Node* ReverseRecursive(Node* p);
void Print(Node* head);
void PrintRecursively(Node* p);
void Printbackwards(Node* p);

int main()
{
    Node* head = NULL; //empty list

    //Get linked list length
    cout << "How many numbers will be in the linked list? ";
    int listLength, nodeValue;
    scanf("%d", &listLength);
    
    //Get linked list Values
    for(int i = 0; i < listLength; i++){
        cout << "Enter the number you want to insert into the list: ";
        scanf("%d", &nodeValue);
        Insert(head, nodeValue);
    }

    /*
    InsertAt(head,2,1); //List: 2
    InsertAt(head,3,2); //List: 2, 3
    InsertAt(head,4,1); //List: 4, 2, 3
    InsertAt(head,5,2); //List: 4, 5, 2, 3
    */

    InsertAtEnd(head, 5);
    InsertAtEnd(head, 6);
    InsertAtEnd(head, 4);
    InsertAtEnd(head, 2); //5, 6, 4, 2
    //Delete(head, 1);
    head = ReverseRecursive(head);
    Print(head);
    PrintRecursively(head);

    return 0;
}

//Insert a value at the start of the linked list, head pass by reference
void Insert(Node* &head, int nodeValue){
    //Create a new node
    Node* temp = new Node();

    //Set the new node's value
    temp->data = nodeValue;

    //Set pointer to the head address
    temp->next = head;

    //Overwrite the head
    head = temp;
}

//Insert a value at the end of the linked list, head pass by reference
void InsertAtEnd(Node* &head, int nodeValue){
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
void InsertAt(Node* &head, int nodeValue, int index){
    //Create node called temp in the stack with data in the heap
    Node* temp1 = new Node();
    temp1->data = nodeValue;
    temp1->next = NULL;
    
    //Insert at the start of the linked list
    if(index == 1){
        temp1->next = head; //Make the pointer to the previous head
        head = temp1; //Update to the new head
        return;
    }

    //Initially point to the head node
    Node* temp2 = head;

    //Loop through the linked list until we reach node index-1
    for(int i = 0; i < index-2; i++){
        temp2 = temp2->next;
    }

    //Building links
    temp1->next = temp2->next;
    temp2->next = temp1;
}

//Delete node at the index
void Delete(Node* &head, int index){
    Node* temp1 = head;

    if(index == 1){
        head = temp1->next; //head points to second node
        free(temp1);
        return;
    }

    for(int i = 0; i < index-2; i++){
        temp1 = temp1->next;
    }
    //temp1 points to (n-1)th node
    Node* temp2 = temp1->next; //nth node
    temp1->next = temp2->next; //(n+1)th node
    free(temp2); //delete temp2
}

//Reverses the linked list
void Reverse(Node* &head){
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

//Recursively reverse the linked list
Node* ReverseRecursive(Node* p){
    //List does not exist.
    if(p == NULL) return NULL;

    //List with only one node.
    if(p->next == NULL) return p; 

    //Recursive call on rest.
    Node* rest = ReverseRecursive(p->next); 

    //Make node p, link to the last node in the reversed rest.
    p->next->next = p;

    //Since p is the new last, make its link NULL.
    p->next = NULL; 
    
    return rest; //Rest now points to the head of the reversed list.
}

//Print Recursively
void PrintRecursively(Node* p){
    if(p == NULL) return;
    printf("%d ", p->data);
    PrintRecursively(p->next);
}

//Print linked list backwards
void Printbackwards(Node* p){
    if(p == NULL) return;
    Printbackwards(p->next);
    printf("%d ", p->data);
}

//Print out the linked list
void Print(Node* head){
    printf("The list is: ");

    //While we're not at the end of the list, print data out
    while(head != NULL){
        printf(" %d", head->data);
        head=head->next;
    }
    printf("\n");
}

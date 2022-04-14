/*  Doubly Linked List in C++ (Local Head)

    Implementation of a doubly linked list. In this version we have a local head
    and we use pass by reference instead of pass by pointer.
*/
#include <iostream>
using std::cout; using std::endl;
  
//A doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
  
void InsertAtFront(struct Node* &head, int new_data);
void InsertAfter(struct Node* prev_node, int new_data);
void InsertAtEnd(struct Node* &head, int new_data);
void Print(struct Node* node);
void reverse(Node* &head);
void deleteNodeAtGivenPos(struct Node* &head, int n);
void deleteNode(Node* &head, Node* del);

int main() {
    //Start with the empty list
    struct Node* head = NULL;

    //Insert 40 as last node
    InsertAtEnd(head, 40);

    //insert 20 at the head
    InsertAtFront(head, 20);

    //Insert 10 at the beginning.
    InsertAtFront(head, 10);

    //Insert 50 at the end.
    InsertAtEnd(head, 50);

    //Insert 30, after 20.
    InsertAfter(head->next, 30);

    deleteNodeAtGivenPos(head, 1);
    //deleteNode(&head, head->next->next);

    Print(head);

    return 0;
}

//Function to reverse a Doubly Linked List
void reverse(Node* &head)  {  
    Node *temp = NULL;  
    Node *current = head;  

    //Swap next and prev for all nodes of doubly linked list
    while (current != NULL)  
    {  
        temp = current->prev;  
        current->prev = current->next;  
        current->next = temp;              
        current = current->prev;  
    }  

    //Before changing head, check for the cases like empty list and list with only one node
    if(temp != NULL )  
        head = temp->prev;  
}  

//Inserts node at the front of the list
void InsertAtFront(struct Node* &head, int new_data)
{
    //Allocate memory for New node
    struct Node* newNode = new Node();
    
    //Assign data to new node
    newNode->data = new_data;
    
    //New node is head and previous is null, since we are adding at the front
    newNode->next = head;
    newNode->prev = NULL;
    
    //Previous of head is new node
    if (head != NULL)
    head->prev = newNode;
    
    //Head points to new node
    head = newNode;
}

// Given a node as prev_node, insert a new node after the given node
void InsertAfter(struct Node* prev_node, int new_data){
    //Check if prev node is null
    if (prev_node == NULL){
        cout<<"Previous node is required, it cannot be NULL";
        return;
    }

    //Allocate memory for new node
    struct Node* newNode = new Node;
    
    //Assign data to new node
    newNode->data = new_data;
    
    //Set next of newnode to next of prev node
    newNode->next = prev_node->next;
    
    //Set next of prev node to newnode
    prev_node->next = newNode;
    
    //Now set prev of newnode to prev node
    newNode->prev = prev_node;
    
    //Set prev of new node's next to newnode
    if (newNode->next != NULL)
    newNode->next->prev = newNode;
}
  
//insert a new node at the end of the list
void InsertAtEnd(struct Node* &head, int new_data){
    //Allocate memory for node
    struct Node* newNode = new Node;

    struct Node* last = head; //Set last node value to head

    //Set data for new node
    newNode->data = new_data;

    //New node is the last node , so set next of new node to null
    newNode->next = NULL;

    //Check if list is empty, if yes make new node the head of list
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    //Otherwise traverse the list to go to last node
    while (last->next != NULL)
        last = last->next;

    //Set next of last to new node
    last->next = newNode;

    //Set last to prev of new node
    newNode->prev = last;
    return;
}
  
//Print contents of linked list starting from the given node
void Print(struct Node* node) {
    struct Node* last;

    cout << "Doubly linked list is: " <<endl;
    while (node != NULL) {
        cout<< node->data <<" ";
        last = node;
        node = node->next;
    }

    //If you want to print null
    if(node == NULL){
        //cout<<"NULL";
    }
}

//Delete a node in a Doubly Linked List
//del = pointer to node to be deleted
void deleteNode(Node* &head, Node* del){
    //Base case
    if (head == NULL || del == NULL){
        return;
    }

    //If node to be deleted is head node
    if (head == del){
        head = del->next;
    }

    //Change next only if node to be deleted is not the last node
    if (del->next != NULL){
        del->next->prev = del->prev;
    }

    //Change prev only if node to be deleted is not the first node
    if (del->prev != NULL){
        del->prev->next = del->next;
    }

    //Free the memory occupied by del
    free(del);
    return;
}

//Delete the node at the given position in the doubly linked list
void deleteNodeAtGivenPos(struct Node* &head, int n){
    //If list is NULL or an invalid position is given
    if (head == NULL || n <= 0){
        return;
    }
 
    Node* current = head;
 
    //Traverse up to the node at position n from the beginning
    for (int i = 1; current != NULL && i < n; i++){
        current = current->next;
    }
 
    //If n is greater than the number of nodes in the doubly linked list
    if (current == NULL){
        return;
    }
 
    //delete the node pointed to by current
    deleteNode(head, current);
}
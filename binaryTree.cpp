/*  Binary Search Tree (Implemented in C++)

    An implementation of a Binary Search Tree (BST) using structs. In this program
    we create functions to create a new node, insert a node, search, find the min,
    find the max, and the height of the BST.
*/

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data);
BstNode* Insert(BstNode* root, int data);
bool Search(BstNode* root, int data);
int FindMin(BstNode* root);
int FindMax(BstNode* root);
int FindHeight(BstNode* root);

int main(){
    BstNode* root = NULL; //Creating empty Tree
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    
    //Ask for user input
    int number;
    cout << "Enter a number to be searched: ";
    cin >> number;

    if(Search(root, number)){
        cout << "Found!\n";
    }
    else{
        cout << "Not found!\n";
    }

    cout << "The maximum value in the BST is: " << FindMax(root) << '\n';
    cout << "The minimum value in the BST is: " << FindMin(root) << '\n';
    cout << "The height of the BST is: " << FindHeight(root) << '\n';
    return 0;
}

//Return a new node
BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

//Inserts a new node
BstNode* Insert(BstNode* root, int data){
    
    //If the tree is empty
    if(root == NULL){
        root = GetNewNode(data);
        return root;
    }
    //Tree is not empty, data is less than the node
    else if(data <= root->data){
        root->left = Insert(root->left, data);
    }
    //Tree is not empty, data is greater than the node
    else{
        root->right = Insert(root->right, data);
    }
    return root;
}

//Search the tree to see if the data value exists
bool Search(BstNode* root, int data){
    //Empty tree or reached empty node
    if(root == NULL){
        return false;
    }
    //Data exists
    else if(root->data == data){
        return true;
    }
    //Data is less than current node
    else if(data <= root->data){
        return Search(root->left, data);
    }
    //Data is greater than current node
    else{
        return Search(root->right, data);
    }
}

//Returns the minimum value in the BST, not using recursion
int FindMin(BstNode* root){

    if(root == NULL){
        cout << "Error: Tree is empty!\n";
        return -1;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}

//Returns the maximum value in the BST, using recursion
int FindMax(BstNode* root){

    if(root == NULL){
        cout << "Error: Tree is empty!\n";
        return -1;
    }
    else if(root->right == NULL){
        return root->data;
    }
    return FindMax(root->right);
}

//Returns the height of the tree (number of edges in longest path from root to a leaf)
//Height of tree with 1 node = 0
int FindHeight(BstNode* root){
    if(root == NULL){
        return -1;
    }
    return std::max(FindHeight(root->left), FindHeight(root->right)) + 1;
}
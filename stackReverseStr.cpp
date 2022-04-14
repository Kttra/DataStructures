/*  Reverse a string using stack
*/
#include<iostream>
#include <cstring> //strlen

using std::cout;

//structure 
class Stack{ 
  public: 
  int top; 
  unsigned cap; 
  char* arr; 
}; 
//Create a stack of capacity (given)
Stack* createst(unsigned cap){ 
  Stack* st = new Stack(); 
  st->cap = cap; 
  st->top = -1; 
  st->arr = new char[(st->cap * sizeof(char))]; 
  return st; 
} 

int isFull(Stack* st);
int isEmpty(Stack* st);
void push(Stack* st, char character);
char pop(Stack* st);
void reversestring(char string[]);

int main() 
{ 
  char string[] = "RandomString"; 
  reversestring(string); 
  cout<< string; 
  return 0; 
}

//Stack will be full when top will equal to the last index 
int isFull(Stack* st){ 
  return st->top == st->cap - 1;
} 
//Stack will be empty when top will equal to -1 
int isEmpty(Stack* st){
  return st->top == -1;
} 
//Add an item to stack, increase top by 1 
void push(Stack* st, char character){ 
  if (isFull(st)){
    return; 
  } 
  st->arr[++st->top] = character; 
} 
//Function to remove the character 
char pop(Stack* st){ 
  if (isEmpty(st)){
    return -1; 
  } 
  return st->arr[st->top--]; 
}
void reversestring(char string[]){ 
  //Create a stack
  int strsm = strlen(string); 
  Stack* st = createst(strsm); 
  //Push all characters  
 
  for (int i = 0; i < strsm; i++) 
    push(st, string[i]); 
  //Pop all characters
  for (int i = 0; i < strsm; i++) 
    string[i] = pop(st); 
} 
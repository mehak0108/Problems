#include<stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

 
/* Link list node */
struct Node
{
  int data;
  struct Node* next;
};
 
/* Function to get the counts of node in a linked list */
int getCount(struct Node* head);
 
/* function to get the intersection point of two linked
   lists head1 and head2 where head1 has d more nodes than
   head2 */
Node* get(int d, struct Node* head1, struct Node* head2);
 
/* function to get the intersection point of two linked
   lists head1 and head2 */
Node *  getIntesectionNode(struct Node* A, struct Node* B)
{
  if(!A && !B)
        return 0;
    int c1 = getCount(A);
    int c2 = getCount(B);
    int d;
    if(c1>c2){
        d = c1-c2;
        return get(d,A,B);
    }
    else{
        d = c2-c1;
        return get(d,B,A);
    }
}
 
/* function to get the intersection point of two linked
   lists head1 and head2 where head1 has d more nodes than
   head2 */
Node* get(int d, struct Node* A, struct Node* B)
{
  int i;
    Node* cur1 = A;
    Node* cur2 = B;
    for(i=0;i<d;i++){
        cur1 = cur1->next;
    }
    while(cur1 && cur2){
        if(cur1 == cur2 )
            return cur1;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    if(!cur1)
        return cur1;
    cout<<cur1->data;
}
 
/* Takes head pointer of the linked list and
   returns the count of nodes in the list */
int getCount(struct Node* head)
{
  struct Node* current = head;
  int count = 0;
 
  while (current != NULL)
  {
    count++;
    current = current->next;
  }
 
  return count;
}
 
/* IGNORE THE BELOW LINES OF CODE. THESE LINES
   ARE JUST TO QUICKLY TEST THE ABOVE FUNCTION */
int main()
{
  /*
    Create two linked lists
 
    1st 3->6->9->15->30
    2nd 10->15->30
 
    15 is the intersection point
  */
 
  struct Node* newNode;
  struct Node* head1 =
            (struct Node*) malloc(sizeof(struct Node));
  head1->data  = 10;
 
  struct Node* head2 =
            (struct Node*) malloc(sizeof(struct Node));
  head2->data  = 3;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 6;
  head2->next = newNode;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 9;
  head2->next->next = newNode;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 30;
  head1->next->next= newNode;
 
  head1->next->next->next = NULL;
 
  /*printf("\n The node of intersection is %d \n",
          getIntesectionNode(head1, head2));*/
  Node * res = getIntesectionNode(head1, head2);
  cout<< res->data;
  getchar();
}
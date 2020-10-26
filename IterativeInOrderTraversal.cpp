#include<iostream>
#include<stack>
#include<stdio.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

void inOrder(node *root){
    if(root==NULL)
        return;

    stack<node *>nodeStack;
    node *current = root;

    while(current->left){
    if(current!=NULL){
        nodeStack.push(current);
        current = current->left;
        cout<<current->data;
        }
    else{
        if(!nodeStack.empty()){
            current = nodeStack.top();
            cout<<current->data;
            current = current->right;
            nodeStack.pop();
            }
        else{
            return;
        }
        }

    }
}

int main(){

    struct node *root = newNode(10);
    root->left        = newNode(8);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);
    inOrder(root);

    /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */

}

#include<stdio.h>
#include<queue>
#include<stdlib.h>
using namespace std;

/* A tree node structure */
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

/* Helper function for getLevel(). It returns level of the data if data is
present in tree, otherwise returns 0.*/


/* Returns level of given data value */
int getLevel(node* p, int data)
{
    if(p==NULL)
        return 0;
    int level =1;
	queue<node* > q;
	q.push(p);
	q.push(NULL);
	node* temp;
	while(!q.empty()){
	    temp = q.front();
	    q.pop();
	    if(temp == NULL){
	        if(!q.empty())
	            q.push(NULL);
	       level++;
	    }
	    else{
	        if(temp->data == data)
	            return level;
	        if(temp->left)
	            q.push(temp->left);
	        if(temp->right)
	            q.push(temp->right);
	    }

	}
}

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
	//struct node *temp = new struct node;
	struct node* temp = (struct node*)
						malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

/* Driver function to test above functions */
int main()
{
	struct node *root = new struct node;
	int x;

	/* Constructing tree given in the above figure */
	root = newNode(3);
	root->left = newNode(2);
	root->right = newNode(5);
	root->left->left = newNode(1);
	root->left->right = newNode(4);

	for (x = 1; x <=5; x++)
	{
	int level = getLevel(root, x);
	if (level)
		printf(" Level of %d is %d\n", x, getLevel(root, x));
	else
		printf(" %d is not present in tree \n", x);

	}

	getchar();
	return 0;
}

#include<stdio.h>
#include<iostream>
#include<stack>
#include<stdlib.h>

typedef struct node{
	int data;
	node* left;
	node* right;
}node;

node* createnode(int dat){
	node* n=(node*)malloc(sizeof(node));
	n->data=dat;
	n->left=NULL;
	n->right=NULL;
	return n;
}

node* insertnode(node* root, int data){
	if(root==NULL){
		node* newnode=createnode(data);
		return newnode;
	}
	else if(data<root->data){
		root->left=insertnode(root->left,data);
		return root;
	}
	else if(data>root->data){
		root->right=insertnode(root->right,data);
		return root;
	}
	
}

void inorder_recursion(node* root){
	if(root!=NULL){
		inorder_recursion(root->left);
		printf("%d\t",root->data);
		inorder_recursion(root->right);
	}
}

void inorder_stack(node* root){
	stack<node*> st;
	while(root!=NULL){
		st.push(root);
		root->left;
	}
	
	
}


int main(){
	node* n1=createnode(50);
	n1=insertnode(n1,30);
	n1=insertnode(n1,20);
	n1=insertnode(n1,100);
	n1=insertnode(n1,60);
	inorder_recursion(n1);
}

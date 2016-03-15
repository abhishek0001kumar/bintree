#include<stdio.h>
#include<stdlib.h>

typedef struct treenode{
	int data;
	struct treenode* left;
	struct treenode* right;
}treenode;

typedef struct bintree{
	int size;
	treenode* root;
}bintree;

treenode* createnode(int data){
	treenode* newnode=(treenode*)malloc(sizeof(treenode));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
/*
bintree* createbin(){
	bintree* newnode=(bintree*)malloc(sizeof(bintree));
	newnode->root=NULL;
	newnode->size=0;
	return newnode;
}

void insertnode(int data,bintree* b){
	
	treenode* newnode=b->root;
	newnode=insertutil(newnode,data);
	(b->size)++;
	}

treenode* insertutil(treenode* b, int data){
	if((b->left==NULL)&&(b->right==NULL)){
		treenode* n=createnode(data);
		return n;
	}
	else if((b->data)<data){
		b->right=insertutil(data,b->right);
	}
	else if((b->data)>data){
		b->left=insertutil(data,b->left);
	}
}*/

void printtree(treenode* b){
	if(b!=NULL){
	printtree(b->left);
	printf("%d",b->data);
	printtree(b->right);
	}
}

void insertnode1(treenode* r,int data){
	if(data<r->data){
		if(r->left!=NULL){
			insertnode1(r->left,data);
		}
		else{
			r->left=createnode(data);
		}
	}
	if(data>r->data){
		if(r->right!=NULL){
			insertnode1(r->right,data);
		}
		else{
			r->right=createnode(data);
		}
	}
}

int main(){
	treenode* root=createnode(50);
	insertnode1(root,40);
	insertnode1(root,60);
	insertnode1(root,80);
	insertnode1(root,10);
	printtree(root);
}

#include<stdio.h>
#include<stdlib.h>

typedef struct vertex{
	int data;
	struct vertex* next;
	struct edge* firstedge;
}vertex;

typedef struct edge{
	struct vertex* dest;
	struct edge* nextedge;
}edge;

struct vertex* createvertex(int data){
	struct vertex* newnode=(struct vertex*)malloc(sizeof(vertex));
	newnode->data=data;
	newnode->firstedge=NULL;
	newnode->next=NULL;
	return newnode;
}
struct vertex* insertvertex(struct vertex* root,int data){
	struct vertex* temp=createvertex(data);
	if(root==NULL){
		root=temp;
		return root;
	}
	struct vertex* t;
	t=root;
	while(t->next!=NULL){
		t=t->next;
	}
	t->next=temp;
	return root;
}
struct vertex* findvertex(struct vertex* root,int data){
	struct vertex* temp;
	temp=root;
	while(temp->data!=data){
		temp=temp->next;
	}
	return temp;
}
struct edge* create_edge(int data){
	struct egde* tempedge=(struct edge*)malloc(sizeof(edge));
	tempedge->nextedge=NULL;
	struct vertex* temp=findvertex(data);
	tempedge->dest=temp;
	return tempedge;
}

struct vertex* insertedge(struct vertex* root,int from_data,int to_data){
	struct vertex* temp;
	temp=root;
	while(temp->data!=from_data){
		temp=temp->next;
	}
	if(temp->firstedge==NULL){
		struct edge* tedge=create_edge(root,to_data);
		temp->firstedge=tedge;
		return root;
	}
	struct edge* tempe=temp->firstedge;
	while(tempe->nextedge!=NULL){
		tempe=tempe->nextedge;
	}
	struct edge* tedge=create_edge(root,to_data);
	tempe->nextedge=tedge;
	return root;
}

void display(struct vertex* root){
	struct vertex* temp;
	temp=root;
	struct edge* tempe;
	while(temp!=NULL){
		tempe=temp->firstedge;
		printf("%d\t",temp->data);
		while(tempe!=NULL){
			printf("%d\t",tempe->dest->data);
			tempe=tempe->nextedge;
		}
		printf("\n");
		temp=temp->next;
	}
}
int main(){
	struct vertex* root=createvertex(1);
	root=insertvertex(root,2);
	root=insertvertex(root,3);
	root=insertedge(root,1,2);
	root=insertedge(root,2,1);
	root=insertedge(root,3,1);
	display(root);
}

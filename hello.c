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

vertex* createvertex(int data){
vertex* newnode=(vertex*)malloc(sizeof(vertex));
newnode->data=data;
newnode->next=NULL;
newnode->firstedge=NULL;
return newnode;
}

vertex* findvertex(vertex* root,int data){
vertex* temp;
temp=root;
while(temp->data!=data){
temp=temp->next;
}
return temp;
}


edge* createedge(vertex* root,int data){
edge* newedge=(edge*)malloc(sizeof(edge));
vertex* temp=findvertex(root,data);
newedge->dest=temp;
newedge->nextedge=NULL;
return newedge;
}

void insertedge(vertex* root,int data1,int data2){
vertex* temp;
temp=findvertex(root,data1);
if(temp->firstedge==NULL){
temp->firstedge=createedge(root,data2);
return;
}
else{
edge* temp1=temp->firstedge;
while(temp1->nextedge!=NULL){
temp1=temp1->nextedge;
}
temp1->nextedge=createedge(root,data2);
}
return;
}


void insertvertex(vertex* root,int data){
vertex* temp;
temp=root;
while(temp->next!=NULL){
temp=temp->next;
}
vertex* newnode=createvertex(data);
temp->next=newnode;
}

void printlist(vertex* root){
vertex* temp;
temp=root;
while(temp!=NULL){
printf("%d\t",temp->data);
edge* t;
t=temp->firstedge;
while(t!=NULL){
printf("%d\t",t->dest->data);
t=t->nextedge;
}
printf("\n");
temp=temp->next;
}
return;
}

int main(){
vertex* root=createvertex(10);
insertvertex(root,20);
insertvertex(root,40);
insertvertex(root,30);
insertedge(root,10,40);
printlist(root);
return 0;
}

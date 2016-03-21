#include<stdio.h>
#include<stdlib.h>
 typedef struct treenode{
	int data;
	struct treenode* left;
	struct treenode* right;
}treenode;

typedef struct binnode{
	int size;
	struct binnode* root;
}binnode;

typedef struct srchnode{
	struct srchnode* position;
	struct srchnode* previous;
}srchnode;

srchnode* createsearch(){
	srchnode* s=(srchnode*)malloc(sizeof(srchnode));
	s->position=NULL;
	s->previous=NULL;
}

treenode* createtree(int data){
	treenode* t=(treenode*)malloc(sizeof(treenode));
	t->data=data;
	t->left=NULL;
	t->right=NULL;
	return t;
}

binnode* createbin(){
	binnode* b=(binnode*)malloc(sizeof(binnode));
	b->size=0;
	b->root=NULL;
	return b;
}

/*int height(treenode* root){
   if(root==NULL){
       return 0;
   } 
    else{
        int l=height(root->left);
        int r=height(root->right);
        
        if(l>=r){
            return l+1;
        }
        else
            return r+1;
    }
}

void printnodelevel(treenode* root,int i){
    if(root==NULL){
        return;
    }
    else if(i==1){
        printf("%d\t",root->data);
    }
    else if(i>1){
        printnodelevel(root->left,i-1);
        printnodelevel(root->right,i-1);
    }
}

void printnodel(treenode* root){
    int h=height(root);
    int i;
    for(i=1;i<=h;i++){
        printnodelevel(root,i);
       
    }
}


void LevelOrder(treenode * root)
{
  printnodel(root);
  
}*/

treenode* insertutil(treenode* d,int item){
	if(d==NULL){
		treenode* newnode=createtree(item);
		return newnode;
	}
	else if(item<(d->data)){
		d->left=insertutil(d->left,item);
		return d;
		}
		
	else if(item>(d->data)){
		d->right=insertutil(d->right,item);
		return d;
	}
	
	
}

void insertnode(binnode* b,int data){
	treenode* t=b->root;
	t=insertutil(t,data);
	(b->size)++;
}

void printjustnode(treenode* t){
	printf("node value=%d\n",t->data);
}

void printinorder(treenode* t){
	if(t!=NULL){
		printinorder(t->left);
		printf("%d\t",(t->data));
		printinorder(t->right);
	}
}


void printnode(binnode* b){
	treenode* t=b->root;
	printinorder(t);
	printf("%d\n",(b->size));
}

void printpreorder(treenode* t){
	if(t!=NULL){
		printf("%d",t->data);
		printpreorder(t->left);
		printpreorder(t->right);
	}
}

void printnode1(binnode* b){
	treenode* t=b->root;
	printpreorder(t);
	printf("\n");
}

void printpostorder(treenode* t){
	if(t!=NULL){
		printpostorder(t->left);
		printpostorder(t->right);
		printf("%d",(t->data));
	}
}

void printnode2(binnode* b){
	treenode* t=b->root;
	printpostorder(t);
	printf("\n");
}

void search_node(treenode* t,int info,srchnode* sr){
	if(t!=NULL){
	if(info<(t->data)){
		sr->previous=t;
		search_node(t->left,info,sr);
	}
	else if(info>(t->data)){
		sr->previous=t;
		search_node(t->right,info,sr);
	}
	else{
		printf("found\n");
		sr->position=t;
	}
}
	if(t==NULL){
		printf("not found\n");
		return;
	}
}

void searchnode(binnode* b,int info,srchnode* s){
	treenode* t=b->root;
	search_node(t,info,s);
}

void minnode(treenode* t){
	if(t==NULL){
		printf("false input\n");
	}
	else if((t->left)==NULL){
		printf("min value=%d\n",(t->data));
	}
	else{
		minnode(t->left);
	}
}

void maxnode(treenode* t){
	if(t==NULL){
		printf("false input\n");
	}
	else if((t->right)==NULL){
		printf("max value=%d\n",(t->data));
	}
	else{
		maxnode(t->right);
	}
}

/*void casea(treenode* t,treenode* pos,treenode* prv){
	if(pos==NUll){//check condition
		root=NULL;
	}
	else if(pos==prv->left){
		prv->left=NULL;
	}
	else{
		prv->right=NULL;
	}
}

void caseb(treenode* t,treenode* pos,treenode* prv){
	treenode* temp;
	if(pos->left==NULL){
		temp=pos->right;
		}
	else{
		temp=pos->left;
	}	
	if(pos==NULL){//check condition
		root=temp;
	}
	else if(pos==ptr->left){
		ptr->left=temp;
	}
	else{
		ptr->right=temp;
	}
}

void casec(treenode* t,treenode* pos,treenode* prv){
	
}

void deleteutil(binnode* b,treenode* t,int data,srchnode* s){
	searchnode(b,data,s);
	treenode* n1=s->position;
	treenode* n2=s->previous;
	if(((n1->left)==NULL) && ((n1->right)==NULL)){
		casea(t,n1,n2);
	}
	else if(((n1->left)==NULL) || (n1->right)==NULL){
		caseb(t,n1,n2);
	}
	else{
		casec(t,n1,n2);
	}
}

void deletenode(binnode* b,int data,srchnode* s){
	treenode* t=b->root;
	deleteutil(b,t,data,s);
	(b->size)--;
}
*/

int main(){
	binnode* b1=createbin();
	treenode* n1=createtree(50);
	srchnode* s1=createsearch();
	b1->root=n1;
	insertnode(b1,40);
	insertnode(b1,30);
	insertnode(b1,10);
	insertnode(b1,100);
	insertnode(b1,120);
	printnode(b1);
	printnode1(b1);
	printnode2(b1);
	searchnode(b1,10,s1);
	searchnode(b1,15,s1);
	minnode(n1);
	maxnode(n1);
}

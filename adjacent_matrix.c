#include<stdio.h>
#include<stdlib.h>

void create_adjacent_matrix(int adj[50][50],int v){
int i,j;
int temp;
printf("enter 1 or 0");
for(i=0;i<v;i++){
for(j=0;j<v;j++){
scanf("%d",&temp);
adj[i][j]=temp;
}
}
return;
}

void print_adjacent_matrix(int adj[50][50],int v){
int i,j;
for(i=0;i<v;i++){
for(j=0;j<v;j++){
printf("%d\t",adj[i][j]);
}
printf("\n");
}
return;
}

void cal_index(int adj[50][50],int n){
int i,j;
int indeg,outdeg;
for(i=0;i<n;i++){
indeg=0;
outdeg=0;
for(j=0;j<n;j++){
if(adj[i][j]==1)
outdeg++;
}
for(j=0;j<n;j++){
if(adj[j][i]==1)
indeg++;
}
printf("indegree and outdegree of %d is\t %d \t %d\n",i,indeg,outdeg);
}
return;
}

int main(){
int adj[50][50];
int n;
printf("enter no. of vertices\n");
scanf("%d",&n);
create_adjacent_matrix(adj,n);
print_adjacent_matrix(adj,n);
cal_index(adj,n);
return 0;
}

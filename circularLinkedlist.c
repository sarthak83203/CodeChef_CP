#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
    
};
struct Node * createNode(int value){
    struct Node * newNode=(struct Node * )malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void insertBegning(struct Node ** head,int value){
    struct Node * newNode=createNode(value);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    newNode->next=*head;
    (*head)->prev=newNode;
    *head=newNode;
}

void insertEnd(struct Node ** head,int value){
    struct Node * newNode=createNode(value);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    struct Node * temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=newNode; // this is not in singly linkedlist.....
}

void displayList(struct Node * head){
    struct Node * temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


int main(){
    int n,value;
    scanf("%d",&n);
    struct Node * headBegin=NULL;
    struct Node * headEnd=NULL;
    
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        insertBegning(&headBegin,value);
    }
    displayList(headBegin);
    
    
    
    
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=headBegin->data;
        headBegin=headBegin->next;
    }
    
    for(int i=n-1;i>=0;i--){
        insertEnd(&headEnd,arr[i]);
    }
     displayList(headEnd);
    
}
//maximum Element using Circular Linkedlist.....
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * prev;// this should be fullfilled...
    struct Node * next;
};

struct Node * createNode(int value){
    struct Node * newNode=(struct Node * )malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=NULL;
    return  newNode;
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
    newNode->prev=temp;
}

int maxele(struct Node * head){ // the best thing is use head not *head.....
    if(head==NULL){ //here i am seeing the pointer not th pointer value....
        return -1; 
    }
    int max=head->data;
    struct Node * temp=head->next;
    while(temp!=NULL){
        if(temp->data>max){
            max=temp->data;
        }
        temp=temp->next;
    }
    return max;
}

int main(){
    int value,n;
    scanf("%d",&n);
    struct Node * head=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        insertEnd(&head,value);
    }
    int maxscore=maxele(head);
    printf("%d",maxscore);
    
}

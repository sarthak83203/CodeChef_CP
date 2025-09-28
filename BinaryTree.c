//Traveser of preordre,postorder,inorder.........
#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node* left;
    struct node* right;

};

struct node* createnode(int data){
    struct node* u; //creating node pointer
    u=(struct node *)malloc(sizeof(struct node)); //this code will work properly
    u->data=data;//data given
    u->left=NULL;
    u->right=NULL;
    return u; //return the node .........

}
//recursion
void * preorder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
        

    }

}
//recursion
void * postorder(struct node* root){
    if(root!=NULL){
       
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }

}
//recursion
void * inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }

}

int main(){
    struct node* p=createnode(7); //root 
    struct node* p1=createnode(2); //children
    struct node* p2=createnode(1); //children
    struct node* p3=createnode(0);//children
    struct node* p4=createnode(4);//children
  
    
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
      preorder(p);
      printf("\n");
      postorder(p);
      printf("\n");
      inorder(p);
   





    return 0;
}
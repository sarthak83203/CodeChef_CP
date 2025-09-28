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


//Deletion code start...
struct node* inorderProcedure(struct node *root){
    //left subtree ka right most child...is an inorder[Procedure//]
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;

}

struct node *deletenode(struct node *root,int value){
     struct node* inpre;
    if(root==NULL){
        return NULL;

    }
    if(root->left==NULL && root->right==NULL){
        free(root); //free the meemory location ....
        return NULL;
    }


    if(value>root->data){
        root->right=deletenode(root->right,value);
    }else if(value<root->data){
       root->left= deletenode(root->left,value);
    }
    //Deletion actual start...
    else{
        inpre=inorderProcedure(root);
        root->data=inpre->data;
        root->left=deletenode(root->left,inpre->data);
    }
    return root; //return those node...
}


int main(){
    struct node* p=createnode(5); //root 
    struct node* p1=createnode(3); //children
    struct node* p2=createnode(6); //children
    struct node* p3=createnode(1);//children
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
      deletenode(p,3);
      printf("\n");
      inorder(p);
   





    return 0;
}
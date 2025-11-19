#include<stdio.h>
#include<stdlib.h>

struct Node {
    char data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(char data){
    struct Node * root=(struct Node * )malloc(sizeof(struct Node));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}
struct Node * insert(struct Node * root,char data){
    if(root==NULL){
        return createNode(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}
struct Node * findMin(struct Node * root){
    while(root && root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct Node * deleteNode(struct Node * root,char data){
    if(root==NULL){
        return root;
    }
    if(data<root->data){
        root->left=deleteNode(root->left,data);
    }
    else if(data>root->data){
        root->right=deleteNode(root->right,data);
    }
    else{
        //Checking For Both......
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        //Checking for Only One child that is left....
        else if(root->left==NULL){
            struct Node * temp=root->right;
            free(root);
            return temp;
            
        }
        //Checking For Only One child that is right
        else if(root->right==NULL){
            struct Node  *temp=root->left;
            free(root);
            return temp;
        }
        //Two children.......
            struct Node * temp=findMin(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
            
      
    }
    return root;
    
}



void inorder(struct Node * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%c ",root->data);
        inorder(root->right);
    }
}





int main(){
    int n;
    struct Node * root=NULL;
    scanf("%d",&n);
    char ch,py;
    for(int i=0;i<n;i++){
        scanf(" %c",&ch);
        root=insert(root,ch);
    }
    
    scanf(" %c",&py);
    root=deleteNode(root,py);
    inorder(root);
    return 0;
    
}
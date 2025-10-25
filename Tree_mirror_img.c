/*Deepa needs assistance in determining if two given binary trees are mirrors of each other. To assist Deepa, you need to implement a program that does the following:



Accepts integers indicating the number of nodes and their values for two binary trees.
Constructs the binary trees using a level-order insertion approach.
Determines if the two trees are mirrors of each other.
Input format :
The first line consists of an integer n1, representing the number of nodes in the first binary tree.

The second line consists of n1 space-separated integers, denoting the values of the nodes in the first binary tree.

The third line consists of an integer n2, representing the number of nodes in the second binary tree.

The fourth line consists of n2 space-separated integers, denoting the values of the nodes in the second binary tree.



Note: If a node is not present, it is represented by -1.

Output format :
If the given binary trees are mirrors of each other, then the output displays "The two binary trees are mirrors of each other."

If the given binary trees are not mirrors of each other, then the output displays "The two binary trees are not mirrors of each other."



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n1 ≤ 15

1 ≤ n2 ≤ 15

1 ≤ elements ≤ 100

Sample test cases :
Input 1 :
5
1 2 3 4 5
5
1 2 3 -1 -1
Output 1 :
The two binary trees are not mirrors of each other.
Input 2 :
7
1 3 2 -1 -1 5 4
7
1 2 3 4 5 -1 -1
Output 2 :
The two binary trees are mirrors of each other.
Input 3 :
7
1 3 5 7 9 11 13
7
1 5 3 13 11 9 7
Output 3 :
The two binary trees are mirrors of each other.

*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int data){
    struct Node * root=(struct Node * )malloc(sizeof(struct Node));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}

struct Node * buildTree(int arr[],int i,int n){
    if(i>=n || arr[i]==-1){
        return NULL;
    }
    struct Node * root=createNode(arr[i]);
    root->left=buildTree(arr,2 * i+1,n);
    root->right=buildTree(arr,2 * i+2,n);
    return root;
    
}
int areMirror(struct Node * t1,struct Node * t2){
    if(t1==NULL && t2==NULL){
        return 1; //if both are empty then both are  mirror image of each other.....
    }
    if(t1==NULL || t2==NULL){
        return 0;
    }
    
    return (t1->data==t2->data) && areMirror(t1->left,t2->right) && areMirror(t1->right,t2->left);
}

int main(){
    int n1,n2;
    scanf("%d",&n1);
    int arr1[n1];
    for(int i=0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }
    scanf("%d",&n2);
    int arr2[n2];
    for(int i=0;i<n2;i++){
        scanf("%d",&arr2[i]);
    }
    
    struct Node * root1=buildTree(arr1,0,n1);
    struct Node  * root2=buildTree(arr2,0,n2);
    
    
    if(areMirror(root1,root2)){
        printf("Yes Two Binary Trees are mirror image of each other");
    }else{
        printf("No they are not mirror image of each other");
    }
    return 0;
    
    
}






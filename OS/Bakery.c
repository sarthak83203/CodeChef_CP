//Ok in bakery we use 
#include<stdio.h>
#define  N 3
int entering[N]={0};
int number[N]={0};
 //Removing Maximum Elements 
int max(int arr[],int n){
    int m=0;
    for(int i=0;i<n;i++){
        if(arr[i]>m){
            m=arr[i];
        }
    }
    return m;
}

void lock(int i){
    entering[i]=1;
    number[i]=max(number,N)+1;
    entering[i]=0;

    //Inside for loop
    for(int j=0;j<N;j++){
        while(entering[j]);

        while(number[j]!=0 &&
        (number[j]<number[i] ||
        (number[j]==number[i] && j<i)));
    }
}

void unlock(int i){
    number[i]=0;
}

int main(){
    lock(0);
    printf("Process 0 is going on\n");
    unlock(0);
    lock(1);
    printf("Process 1 is going on\n");
    unlock(1);
    lock(2);
    printf("Process 2 is going on\n");
    unlock(2);
    lock(3);
    printf("Process 3 is going on\n");
    unlock(3);
}


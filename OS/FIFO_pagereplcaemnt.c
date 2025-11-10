#include<stdio.h>
int main(){
    //now the pages
    int n,f;
    scanf("%d",&n);
    int pages[n];
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }

    //Now the number of frames
    scanf("%d",&f);
    int frames[f];
    

    for(int i=0;i<f;i++){
        frames[i]=-1;
    }

    int faults=0,index=0;
    for(int i=0;i<n;i++){ //Now i want to see the number of hits
        int hit=0;
        for(int j=0;j<f;j++){
            if(frames[j]==pages[i]){
                hit=1;
            }
        }
        if(!hit){
            frames[index]=pages[i];
            index=(index+1)%f;
            faults++;
        }

    }
    printf("%d",faults);


}
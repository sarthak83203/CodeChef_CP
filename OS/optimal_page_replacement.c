#include<stdio.h>
int main(){
    int n,f;
    scanf("%d",&n);
    int pages[n];
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }

    scanf("%d",&f);
    int frames[f];
    for(int j=0;j<f;j++){
        frames[j]=-1;
    }

    int faults=0;
    for(int i=0;i<n;i++){
        int hit=0;
        for(int j=0;j<f;j++){
            if(frames[j]==pages[i]){
                hit=1;
            }
        }
        if(!hit){
            int replace=0;
            int pos[f];

            for(int j=0;j<f;j++){
                pos[j]=-1;
                for(int k=i+1;k<n;k++){
                    if(frames[j]==pages[k]){
                        pos[k]=j;
                        break;
                    }
                }
               
            }
            for(int j=1;j<f;j++){
                if(pos[j]>pos[replace]){
                    replace=j;

                }
            }
            frames[replace]=pages[i];
            faults++;
        }
    }
    printf("%d",faults);

}
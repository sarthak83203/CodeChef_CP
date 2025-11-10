#include<stdio.h>
int main(){
    //Now taking input of pages
    int n,f;
    scanf("%d",&n);
    int pages[n];
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    scanf("%d",&f);

    int frames[f],lastlru[f];
    for(int i=0;i<n;i++){
        frames[i]=-1;
    }

    int faults=0;
    for(int i=0;i<n;i++){
        int hit=0;
        for(int j=0;j<f;j++){
            if(frames[j]==pages[i]){
                hit=1;
                lastlru[j]=i;
            }
        }
        if(!hit){
            int lru=0;
            for(int j=1;j<f;j++){
                if(lastlru[j]<lastlru[lru]){
                    lru=j;
                }
            }
            frames[lru]=pages[i];
            lastlru[lru]=i;
            faults++;
        }
    }
    printf("%d",faults);



}
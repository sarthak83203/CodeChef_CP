#include<stdio.h>
#include<limits.h>

int main(){
    int n;
    scanf("%d",&n);
    int pid[n];
    int at[n],rt[n],bt[n],st[n],tat[n],ct[n],wt[n];
    int done=0;
    int time=0;
    for(int i=0;i<n;i++){
        pid[i]=i+1;
        printf("Enter the process for arrival time: %d",pid[i]);
        scanf("%d",&at);
        printf("Enter the process for arrival time: %d",pid[i]);
        scanf("%d",&bt);
        rt[i]=bt[i];
        st[i]=-1;
    }
    while(done<n){
        int index=-1,min=INT_MAX;
        for(int i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0 && rt[i]<min){
                min=rt[i];
                index=i;
            }
        }
        if(index==-1){
            time++;
            continue;
        }
        if(st[index]==-1){
            st[index]=-1;
            rt[index]--;
            time++;
        }

        if(rt[index]==0){
            done++;
            ct[index]=time;
            tat[index]=ct[index]-at[index];
            wt[index]=tat[index]-bt[index];

        }
        
    }
}
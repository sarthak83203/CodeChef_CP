#include<stdio.h>
#define N 99999999
int main(){
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    int graph[100][100];
    //First of all initializing graph with INFINITE...
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j]=N;

        }
    }
    //Read edges .....
    for(int i=0;i<m;i++){
       int u,v,w;
       scanf("%d %d %d",&u,&v,&w);
       graph[u][v]=w;
       graph[v][u]=w;
    }

    int selected[105]={0};
    selected[0]=1;

    int edges=0;
    int totalcost=0;
    while(edges<n-1){
        //now i want to remove minimum
        int min=N;
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(selected[i]){
                for(int j=0;j<n;j++){
                    if(!selected[j] && graph[i][j]<min){
                        min=graph[i][j];
                        x=i;
                        y=j;
                    }
                }
            }
        }
        selected[y]=1;
        totalcost+=min;
        edges++;

    }
    printf("%d",totalcost);
    return 0;
    
}
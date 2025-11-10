#include<stdio.h>
int main(){
    int n,m;
    printf("Enter a Process\n");
    scanf("%d",&n);
    printf("Enter a Resources\n");
    scanf("%d",&m);
    int allo[n][m],max[n][m],need[n][m];
    int available[n],safe[n],finish[n];

    //Taking input of allocation
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&allo[n][m]);
        }
    }
    //Taking max

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&max[n][m]);
        }
    }

     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&need[n][m]);
        }
    }

    for(int j=0;j<m;j++){
        scanf("%d",&available[j]);
    }

    //need =max-allo

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=max[i][j]-allo[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int count=0;
    while(count<n){
        int f=0;

        for(int i=0;i<n;i++){
            if(!finish[i]){
                int ok=1;
                for(int j=0;j<m;j++){
                    if(need[i][j]>available[j]){
                        ok=0;
                    }
                }
                if(ok){
                    for(int j=0;j<m;j++){
                        available[j]+=allo[i][j];
                    }
                    safe[count++]=i;
                    finish[i]=1;
                    f=1;
                }
            }

        }
        if(!f){
            break;
        }


    }
    if(count==n){
        printf("Safe");
        for(int i=0;i<n;i++){
            printf("%d ",safe[i]);
        }
    }else{
        printf("Not Safe");
    }



}
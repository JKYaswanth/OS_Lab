#include<stdio.h>

int main(){
    
    int bsize[20],psize[20];
    int all[20],m,n,i,j;
    printf("Enter the number of blocks :- ");
    scanf("%d",&m);
    printf("Enter the size of each block :- ");
    for(i=0;i<m;i++){
        scanf("%d",&bsize[i]);
    }
    
    printf("Enter the number of processes :- ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&psize[i]);
    }
    return 0;
}
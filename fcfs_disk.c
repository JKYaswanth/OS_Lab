#include<stdio.h>
#include<stdlib.h>

int main(){
    int initial,rq[50],n,i,total_head=0;
    printf("Enter the Number of Requests :- ");
    scanf("%d",&n);
    printf("Enter the Request Sequence : ");
    for(i=0;i<n;i++){
        scanf("%d",&rq[i]);
    }
    printf("Enter the initial head position :- ");
    scanf("%d",&initial);
    printf("\n");
    printf("\nThe Resulting Disk movement :- \n\n");
    for(i=0;i<n;i++){
        printf("%d ",rq[i]);
        total_head+=abs(rq[i]-initial);
        initial=rq[i];
    }
    printf("\n\nTotal Head Movement : %d",total_head);
}
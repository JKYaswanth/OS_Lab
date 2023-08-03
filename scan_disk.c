#include<stdio.h>
#include<stdlib.h>

int main(){
    int rq[50],i,j,n,total_head=0,initial,move,temp,size;
    printf("Enter the number of requests :- ");
    scanf("%d",&n);
    printf("Enter the Requests Sequence :- ");
    for(i=0;i<n;i++){
        scanf("%d",&rq[i]);
    }
    printf("Enter initial head position :- ");
    scanf("%d",&initial);
    printf("Enter total disk size :- ");
    scanf("%d",&size);
    printf("Enter the head movement ( high for 1 and low for 0 ) :- ");
    scanf("%d",&move);
    
    // sorting
    
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(rq[j]>rq[j+1]){
                temp=rq[j];
                rq[j]=rq[j+1];
                rq[j+1]=temp;
            }
        }
    }
    
    int index;
    for(i=0;i<n;i++){
        if(initial<rq[i]){
            index=i;
            // printf("\nindex value :- %d",rq[i]);
            break;
        }
    }
    
    printf("\n\nThe SCAN Disk Scheduling :- ");
    // if move = 1
    
    if(move==1){
        for(i=index;i<n;i++){
            total_head+=abs(rq[i]-initial);
            initial=rq[i];
            printf("%d ",initial);
        }
        total_head+=abs(rq[i-1]-size-1);
        initial=size-1;
        
        for(i=index-1;i>=0;i--){
            total_head+=abs(rq[i]-initial);
            initial=rq[i];
            printf("%d ",initial);
        }
    }
    
    // if move = 0
    
    else{
        for(i=index-1;i>=0;i--){
            total_head+=abs(rq[i]-initial);
            initial=rq[i];
            printf("%d ",initial);
        }
        total_head+=abs(rq[i+1]-0);
        initial=0;
        for(i=index;i<n;i++){
            total_head+=abs(rq[i]-initial);
            initial=rq[i];
            printf("%d ",initial);
        }
        
    }
    
    printf("\n\nTotal Head Movement :- %d\n",total_head);
    
    return 0;
}
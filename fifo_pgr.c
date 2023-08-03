#include<stdio.h>

int main(){
    
    int i,j,k,pf=0,count=0,rs[30],m[10],n,hit=0,f;
    printf("\n Enter the length of the refernce string :- ");
    scanf("%d",&n);
    printf("\n Enter the refernce string :- ");
    for(i=0;i<n;i++){
        scanf("%d",&rs[i]);
    }
    printf("\n Enter no. of frames :- ");
    scanf("%d",&f);
    
    for(i=0;i<f;i++){
        m[i]=-1;
    }
    
    for(i=0;i<n;i++){
        for(k=0;k<f;k++){
            if(m[k]==rs[i]){
                hit++;
                break;
            }
        }
        if(k==f){
            m[count++]=rs[i];
            pf++;
        }
        for(j=0;j<f;j++){
            printf("\t%d",m[j]);
        }
        if(k==f){
            printf("\tPF no. : %d",pf);
        }
        printf("\n");
        if(count==f){
            count=0;
        }
    }
    
    printf("Number of Page Hit :- %d\n",hit);
    printf("Number of Page Faults :- %d\n",pf);
    
    
    
    
    return 0;
}
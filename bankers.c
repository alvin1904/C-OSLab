#include<stdio.h>

void main(){
    int p=0,r=0,i=0,j=0;
    printf("Enter the number of processes: ");
    scanf("%d",&p);
    printf("Enter the number of resources: ");
    scanf("%d",&r);
    int allocation[p][r], max[p][r], need[p][r], available[r];
    
    //TAKING INPUTS
    printf("\n");    
    for(i=0;i!=p;i++){
        printf("Enter the current ALLOCATION for P%d: ",i);
        for(j=0;j!=r;j++)
            scanf("%d",&allocation[i][j]);
    }
    printf("\n");
    for(i=0;i!=p;i++){
        printf("Enter the MAX allocation for P%d: ",i);
        for(j=0;j!=r;j++)
            scanf("%d",&max[i][j]);
    }
    printf("\n");
    printf("Enter the AVAILABLE resources: ");
    for(j=0;j!=r;j++)
        scanf("%d",&available[j]);
    printf("\n");

    //LOGIC PART







}
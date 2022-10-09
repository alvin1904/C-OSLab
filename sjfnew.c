#include<stdio.h>

struct process {
    int n, at, bt, ct, wt, tat, status; 
}p[10], temp;

void sort(int num);
int takedetails();
void printprocess(int num);
void swap(int i, int j);

void main(){
    int num = takedetails();
    printprocess(num);
    sort(num);

    p[0].wt = 0;
    p[0].ct = p[0].bt;
    p[0].tat = p[0].bt;
    int ct = p[0].ct;
    int i, j, flag=0, sum_wt = 0, sum_tat = 0;
    for(i=1;i<num;i++){
        if(p[i].at<=ct){
            for(j=i+1;j<num;j++){
                if(p[j].at<=ct && p[j].bt<p[i].bt)
                    swap(i,j);
            }
            flag=1;
        }
        if(flag==1){
            ct = ct+p[i].bt;
            flag=0;
        }else{
            ct = p[i].at + p[i].bt; 
        }

       ct = p[0].ct;
       for(i=1;i<num;i++){
            p[i].ct = ct + p[i].bt;
            p[i].wt = ct - p[i].at;
            p[i].tat = p[i].wt + p[i].bt;
            sum_wt += p[i].wt;
            sum_tat += p[i].tat; 
            ct = p[i].ct;
        }
        float avg_wt = sum_wt / num;
        float avg_tat = sum_tat / num;

    }    

    printprocess(num);
}

int takedetails(){
    int i, num;
    printf("Enter the number of processes: ");
    scanf("%d",&num);
    for(i=0;i!=num;i++){
        printf("Enter the details for process: P%d\n",i);
        p[i].n = i;
        printf("Enter the AT of process P%d: ",i);       
        scanf("%d",&p[i].at);
        printf("Enter the BT of process P%d: ",i);       
        scanf("%d",&p[i].bt);
        p[i].status = 0;
    }
    return num;
}

void sort(int num){
    int i=0, j=0;
    for(i=0;i<num;i++){
        for(j=0;j<num-i-1;j++){
            if(p[j].at>p[j+1].at)
                swap(j,j+1);
            if(p[j].at == p[j+1].at && p[j].bt>p[j+1].bt)
                swap(j,j+1);
        }
    }
}

void swap(int i, int j){
    temp = p[i];
    p[i] = p[j];
    p[j] = temp;
}

void printprocess(int num){
    int i;
    printf("\nN  |  AT  |  BT  |  CT  |  WT  | TAT  |  Status\n");
    for(i=0;i!=num;i++){
        printf("%d  |   %d  |   %d  |   %d  |   %d  |   %d  |   %d\n",p[i].n, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat, p[i].status);       
    }
}

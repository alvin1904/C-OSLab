#include<stdio.h>
#include<string.h>

int takedetails();

struct process{
    int n, at, bt, ct, wt, tat, status;
}p[20],temp;

void main(){
	int nop = takedetails();

   	p[0].ct = p[0].at + p[0].bt;
  	p[0].wt = 0;
    	p[0].tat = p[0].ct - p[0].at;
	int n=0;
	for(n=1;n<=nop;n++){

    		if(p[n].at<p[n-1].ct)
			p[n].wt = p[n-1].ct - p[n].at;
		else
			p[n].wt = 0;
		p[n].ct = p[n].at + p[n].bt + p[n].wt;
		p[n].tat = p[n].ct - p[n].at;
	}
	int i;
    printf("\nN  |  AT  |  BT  |  CT  |  WT  | TAT  |  Status\n");
    for(i=0;i!=nop;i++){
        printf("%d  |   %d  |   %d  |   %d  |   %d  |   %d  |   %d\n",p[i].n, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat, p[i].status);       
    }

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


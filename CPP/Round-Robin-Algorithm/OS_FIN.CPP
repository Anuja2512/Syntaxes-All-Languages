#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include"c:\TURBOC3\BIN\OS_PROJ\BEG.h"

struct times
{
       int p,art,but,wtt,tat,rnt;
};

void sortart(struct times a[],int pro)
{
       int i,j;
       struct times temp;
       for(i=0;i<pro;i++)
       {
	      for(j=i+1;j<pro;j++)
	      {
		     if(a[i].art > a[j].art)
		     {
			   temp = a[i];
			   a[i] = a[j];
			   a[j] = temp;
		     }
	      }
       }
       return;
}

int main()
{
       int i,j,pro,time,remain,flag=0,ts,x=50;
       struct times a[100];
       float avgwt=0,avgtt=0;
       clrscr();
       start();
       textbackground(YELLOW);
       textcolor(WHITE);
       clrscr();
       printf("\n\t\t\tROUND ROBIN SCHEDULING ALGORITHM\n\n");
       printf("********************************************************************************\n");
       printf("Note -\n1. Arrival Time of at least on process should be 0\n2. CPU should never be idle\n");
       printf("********************************************************************************\n");
      input: printf("Enter Number Of Processes : ");
       scanf("%d",&pro);
       remain=pro;
       /*if(pro<=5)
       {
       goto cont;
       }
       else
       { printf("Enter less than 6\n");
       goto input;
       }*/
    cont:printf("|---------------------------------------------------------|\n");
       for(i=0;i<pro;i++)
       {
	      printf("| Enter arrival time and Burst time for Process P%d : ",i);
	      scanf("%d%d",&a[i].art,&a[i].but);
	      a[i].p = i;
	      a[i].rnt = a[i].but;
	       printf("|---------------------------------------------------------|\n");
       }
       sortart(a,pro);
       printf("| Enter Time Slice OR Quantum Number : ");
       scanf("%d",&ts);
       printf("|---------------------------------------------------------|\n");
       textbackground(YELLOW);
       clrscr();
       printf("\n******************************************************************************\n");
       textcolor(WHITE+BLINK);
       printf("\t\t\t\tGANTT CHART\n");
       textcolor(WHITE);
       printf("******************************************************************************\n");
       printf("0");
       for(time=0,i=0;remain!=0;)
       {
	      if(a[i].rnt<=ts && a[i].rnt>0)
	      {
		     time = time + a[i].rnt;
		     printf(" -> [P%d] <- %d",a[i].p,time);
		     a[i].rnt=0;
		     flag=1;
	      }
	      else if(a[i].rnt > 0)
	      {
		     a[i].rnt = a[i].rnt - ts;
		     time = time + ts;
		     printf(" -> [P%d] <- %d",a[i].p,time);
	      }
	      if(a[i].rnt==0 && flag==1)
	      {
		     remain--;
		     a[i].tat = time-a[i].art;
		     a[i].wtt = time-a[i].art-a[i].but;
		     avgwt = avgwt + time-a[i].art-a[i].but;
		     avgtt = avgtt + time-a[i].art;
		     flag=0;
	      }
	      if(i==pro-1)
		     i=0;
	      else if(a[i+1].art <= time)
		     i++;
	      else
		     i=0;
       }
       printf("\n\n");
       printf("|-------------------------------------------------------------------------|\n");
       printf("| Process | Arrival Time | Burst Time | Turnaround Time | Waiting Time    |\n");
       printf("|-------------------------------------------------------------------------|\n");
       for(i=0;i<pro;i++)
       {
	      x=x+60;
	      sound(x);
	      printf("|  P%d     |      %d       |      %d     |        %d       |       %d        |\n",a[i].p,a[i].art,a[i].but,a[i].tat,a[i].wtt);
	      printf("|-------------------------------------------------------------------------|\n");
       delay(200);
       }
       nosound();
       avgwt = avgwt/pro;
       avgtt = avgtt/pro;
       printf("| Average Waiting Time : %.2f\t\t\t\t\t\t  |\n",avgwt);
       printf("|-------------------------------------------------------------------------|\n");
       printf("| Average Turnaround Time : %.2f\t\t\t\t\t  |\n",avgtt);
       printf("|-------------------------------------------------------------------------|\n");
       getch();
       return 0;
}
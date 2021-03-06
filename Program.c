#include<stdio.h>
#include<string.h>
//P FOR PROCESS NAME || PT FOR PROCESS TIME || WT FOR WAITING TIME
//NOG FOR NO OF GIFTS || NOP FOR NO OF PERSONS
//TOTWT FOR TOTAL WAITING TIME || AVGWT FOR AVERAGE WAITING TIME
struct process
{	char p[10];
	int pt, wt, nog;
}s[20];
//overall complexity is O(n^2)
int main()
{	char temp[10];
	int i, j, totwt=0, temp1;
	int nop;
	float avgwt;
	printf("\n\t***Welcome everyone to the operating system*\n");
	printf("\t	  **Process execution started**\n");
   	printf("_____________________\n");
	printf("Enter number of persons:\t");
	scanf("%d",&nop);
//complexity is O(n)
	for(i=0;i<nop;i++)
	{
		printf("\nEnter person %d name:\t",i+1);
  		scanf("%s",s[i].p);
		printf("Enter process time:\t");
		scanf("%d",&s[i].pt);
		printf("Enter number of gifts:\t");
		scanf("%d",&s[i].nog);
	}
//complexity is O(n^2)
  	for(i=0;i<nop-1;i++)
	{	for(j=i+1;j<nop;j++)
		{	if(s[j].nog>s[i].nog)
			{	//gift order
				temp1=s[i].nog;
				s[i].nog=s[j].nog;
				s[j].nog=temp1;
				//process time order
				temp1=s[i].pt;
				s[i].pt=s[j].pt;
				s[j].pt=temp1;
				//process name order
				strcpy(temp,s[i].p);
				strcpy(s[i].p,s[j].p);
				strcpy(s[j].p,temp);
	}	}	}
	s[0].wt=0;
//complexity is O(n)
	for(i=1;i<nop;i++)
	{	s[i].wt=s[i-1].pt+s[i-1].wt;
		totwt=totwt+s[i].wt;
	}
//converting int to float type conversion
	avgwt=(float)totwt/nop;
	printf("_____________________");
	printf("\nPersons_Name\tProcess_Time\tNo_Of_Gifts\tWaiting_Time\n");
      	printf("_____________________\n");
//complexity is O(n)
	for(i=0;i<nop;i++)
	{	   printf(" %s\t\t%d\t\t%d\t\t%d\n",s[i].p,s[i].pt,s[i].nog,s[i].wt);
	}
	printf("\nTotal waiting time=%d\nAvg waiting time=%f\n",totwt,avgwt);
    	printf("_____________________\n");
	printf("\t	  **Process execution completed**\n");	}

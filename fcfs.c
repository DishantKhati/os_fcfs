#include <stdio.h>
int waitingtime(int proc[], int n,int bt[], int wt[]){wt[0] = 0;
   for (int i = 1; i < n ; i++ )wt[i] = bt[i-1] + wt[i-1] ;
   return 0;}
int turnaroundtime( int proc[], int n,int bt[], int wt[], int tat[]) {int i;
   for ( i = 0; i < n ; i++)tat[i] = bt[i] + wt[i];
   return 0;}
int avgtime( int proc[], int n, int bt[]) {
   int wt[n], tat[n], tw = 0, tt = 0;
   int i;
   waitingtime(proc, n, bt, wt);
   turnaroundtime(proc, n, bt, wt, tat);
   printf("arrival  Burst    Waiting   Turn around \n");
   for ( i=0; i<n; i++) {
      tw = tw + wt[i];
      tt = tt + tat[i];
      printf(" %d\t  %d\t\t %d \t%d\n", i+1, bt[i], wt[i], tat[i]);
   }
   printf("Average waiting time = %f\n", (float)tw / (float)n);printf("Average turn around time = %f\n", (float)tt / (float)n);return 0;}
int main()
{int proc[50],n;
 printf("Enter the number of Processes: ");
 scanf("%d",&n);
 printf("Enter the arrival time: ");
 for(int i=0;i<n;scanf("%d",&proc[i++]));
 int bt[50];
 printf("Enter the burst time: ");
 for(int i=0;i<n;scanf("%d",&bt[i++]));
 avgtime(proc, n, bt);
 return 0;}

#include <stdio.h>

struct process
{
  int pid, burst, arrival, wt, tat, comp;
};

void printline (int x);

int
main ()
{
  int i, n, j;

  int tot_wt = 0, tot_tat = 0;

  float sum = 0.0, avg_wt = 0.0, avg_tat = 0.0;

  struct process p[10], temp;
  printf ("Enter the number of process :- ");
  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {
      printf ("Enter Arrival time and Burst time for process %d :-", i + 1);
      scanf ("%d %d", &p[i].arrival, &p[i].burst);
      p[i].pid = i + 1;
    }

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n - i - 1; j++)
	{
	  if (p[j].arrival > p[j + 1].arrival)
	    {
	      temp = p[j];
	      p[j] = p[j + 1];
	      p[j + 1] = temp;
	    }
	}
    }



  for (i = 0; i < n; i++)
    {
      if (i == 0)
	{
	  p[0].wt = 0;
	  p[0].tat = p[0].burst;
	  tot_wt += 0;
	  tot_tat += p[0].tat;
	  p[0].comp = p[0].tat;
	}
      else
	{
	  p[i].comp += p[i - 1].comp + p[i].burst;
	  p[i].wt = p[i - 1].comp - p[i].arrival;
	  p[i].tat = p[i].wt + p[i].burst;
	  tot_wt += p[i].wt;
	  tot_tat += p[i].tat;
	}
    }

  avg_wt = tot_wt / (float) n;
  avg_tat = tot_tat / (float) n;

  printline (44);

  printf ("PID\tArrival\tBurst\tWait\tTurn-Around");

  printline (44);

  for (i = 0; i < n; i++)
    {
      printf ("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst,
	      p[i].wt, p[i].tat);
    }

  printline (44);

  printf ("Average Waiting Time :- %f\n", avg_wt);
  printf ("Average Turn-Around Time :- %f\n", avg_tat);

  return 0;
}

void
printline (int x)
{
  int i;
  for (i = 0; i < x; i++)
    {
      printf ("-");
    }
  printf ("\n");
}

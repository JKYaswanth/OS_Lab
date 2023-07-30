/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>

int
main ()
{
  int bsize[10], psize[10], bno, pno, allocation[10], flag[10], i;
  for (i = 0; i < 10; i++)
    {
      flag[i] = 0;
      allocation[i] = -1;
    }

  printf ("Enter the number of blocks :- ");
  scanf ("%d", &bno);
  for (i = 0; i < bno; i++)
    {
      printf ("Enter the size of block %d :-", i + 1);
      scanf ("%d", &bsize[i]);
    }

  printf ("\n");

  printf ("Enter the number of process :- ");
  scanf ("%d", &pno);
  for (i = 0; i < pno; i++)
    {
      printf ("Enter the size of process %d", i + 1);
      scanf ("%d", &psize[i]);
    }

  printf ("\n");
  int j;

  for (i = 0; i < pno; i++)
    {
      for (j = 0; j < bno; j++)
	{
	  if (bsize[j] >= psize[i])
	    {
	      allocation[i] = j;
	      bsize[j] -= psize[i];
	      break;
	    }
	}
    }

  printf ("Process_no\tProcess_Size\tBlock_no\n");
  for (i = 0; i < pno; i++)
    {
      printf ("%d\t%d\t", i + 1, psize[i]);
      if (allocation[i] != -1)
	{
	  printf ("%d\t", allocation[i] + 1);
	}
      else
	{
	  printf ("Not Allocated\n");
	}

    }

  return 0;

}

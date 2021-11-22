//P Vishal
//191EE139
//CS252 Assignment

/* Q3.21 
C program to generate the Collatz Conjecture for a given starting number.
*/


//Required libraries
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


//Main function
int main(int argc, char *argv[])
{
	printf("\n\n        Collatz Conjecture\n");

	//Local variable declaration
    int n=0,num;
	
	pid_t pid;

    if (argc == 1)
    {
        printf("\nERROR: First number of the Collatz conjecture sequence not entered \n Please enter a positive integer the command line\n\n");
        exit(1);
    }
    else if (argc == 2)
    {
        if(atoi(argv[1]) <= 0) //Error Checking
        {
            printf("\nInvalid Input \n Please enter a positive integer\n\n");
            exit(1);
        }
        num = atoi (argv[1]);
        printf("\nThe entered first number is: %d\n", num);
    }


	//Process ID of parent
    printf("\nParent process created having pid %d\n", (int) getpid());
        
    //Forking a child process
    pid = fork();

	if (pid == 0) //child process
		{
			printf("\nChild process created having pid %d\n",(int) getpid());
            printf("\nChild is working...\n");
            //Finding the Collatz conjecture
            printf("\nThe Collatz Conjecture Sequence is as follows:\n");
			printf("%d  ",num);
			while (num!=1)
			{
				if (num%2 == 0)
				{
					num = num/2;
				}
				else if (num%2 == 1)
				{
					num = 3 * (num) + 1;
				}	
			
				printf("%d  ",num);
			}
		
			printf("\nChild process is done.\n");
		}
		else //Parent process
		{
			printf("\nParents is waiting on child process...\n\n");
			wait(&n);
            //Parent process waiting for child process to complete after which it will get executed
			printf("\nParent process is done.\n");
		}
	return 0; 
}

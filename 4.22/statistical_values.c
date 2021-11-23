//P Vishal
//191EE139
//CS252 Assignment


/* Q4.22
Write a program in c multi-threaded program that calculates various statistical
values for a list of numbers. This program will be passed a series
of numbers on the command line and will then create
5 separate worker threads.
*/

//Required Libraries 
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>




//Global variable declaration
int *array;
int n;
float average;
int minimum;
int maximum;
float medn, variance, standard_dev;

//thread1 for calculating average
void *avg()
{
    float sum=0;
    for(int i=0;i<n;i++)
        sum=sum+array[i];
    average=(sum/n);
        
}

//Thread for calculating Minimum value
void *min()
{


    minimum=array[0];
    for(int i=0;i<n;i++)
        if(minimum>array[i])
            minimum=array[i];
        

}

//Thread for calculating Maximum value
void *max()
{

    maximum=array[0];
    for(int i=0;i<n;i++)
    {

        if(maximum<array[i])
        {
            maximum=array[i];
        }    
    }
}

//Thread for calculating Median
void *median()
{
	int i,j,temp;
	

	int *A = (int*) array;
	//Sorting the given inputs
	for (i = 0; i < (n - 1); i++)
	{
		
		for (j = i; j < n; j++)
		{
			if (A[i] > A[j])
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
			
		}
	} 


	//Calculating median
	if ((n + 1) % 2 == 0)
	{
		medn = A[((n + 1) / 2) - 1];
	}
	else
	{
		medn =   (A[ n/2 ]  +   A[n/2 - 1]) / 2.0;
	}
	pthread_exit(NULL);
} 

//Thread for calculating Standard Deviation
void *stddev()
{
    
    for(int i=0; i<n ; i++)
    {
        variance += pow(array[i] - average,2);
    }

    variance = variance/n;

    standard_dev = sqrt(variance);
    
    pthread_exit(NULL);
} 

//Main function
int main(int argc, char *argv[])
{
       
    n = argc - 1; // Passing data elements to command line

    array=(int * )malloc(sizeof(int)*n);
	

    for(int i=1;i<argc;i++)
    {
        array[i-1] = atoi(argv[i]);
    }
            
            
    printf("\n\nThe values entered are:");


    for (int i=0;i<n;i++)
    {
        printf("%d ", array[i]);

    }

    printf("\n");
    

    //Declaring 5 worker threads - t1, t2, t3, t4 and t5
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;
    pthread_t t5; 

    
    //creating threads
    pthread_create(&t1,NULL,&avg,NULL);
    pthread_join(t1,NULL);
    
    pthread_create(&t2,NULL,&min,NULL);
    pthread_join(t2,NULL);

    pthread_create(&t3,NULL,&max,NULL);
    pthread_join(t3,NULL);

    pthread_create(&t4,NULL,&median,NULL);
    pthread_join(t4,NULL);

    pthread_create(&t5,NULL,&stddev,NULL);
    pthread_join(t5,NULL);
       
        
    /*main is the parent thread.
    the parent thread will output the values
    once the workers have exited.
    */
    printf("\nThe Average value is %f",average);
    printf("\nThe Minimum  value is %d",minimum);
    printf("\nThe Maximum  value is %d",maximum);
    printf("\nThe Median is %f",medn);
    printf("\nThe Standard Deviation is %f\n",standard_dev);
        
    return 0;

}

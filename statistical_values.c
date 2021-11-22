//P Vishal
//191EE139
//CS252 Assignment


/* Q4.22
Write a program in c multi-threaded program that calculates various statistical
values for a list of numbers. This program will be passed a series
of numbers on the command line and will then create
three separate worker threads.
*/

//Required Libraries 
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


//Global variable declaration
int *array;
int n;
float average;
int minimum;
int maximum;

//thread1 for calculating average
void *th()
{
        float sum=0;
        for(int i=1;i<=n;i++)
                sum=sum+array[i];
        average=(sum/n);
        
}

//thread2 for calculating minimum value
void *th1()
{


        minimum=array[1];
        for(int i=1;i<=n;i++)
                if(minimum>array[i])
                minimum=array[i];
        

}

//thread3 for calculating maximum value
void *th2()
{

        maximum=array[1];
        for(int i=1;i<=n;i++)
                if(maximum<array[i])
                        maximum=array[i];
                        
}

//Main function
int main(int argc, char *argv[])
{
       
     n = argc - 1; // Passing data elements to command line

    array=(int * )malloc(sizeof(int)*n);
	

	for(int i=1;i<=n;i++)
	{
	    array[i] = atoi(argv[i]);
	}
            
            
        printf("\n\nThe values entered are:");


        for (int i=1;i<=n;i++)
        {
                printf("%d ", array[i]);

        }


    int t,i;

    //Declaring 3 worker threads - t1, t2 and t3
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    
    //creating threads
        t=pthread_create(&t1,NULL,&th,NULL);
        pthread_join(t1,NULL);
    
        t=pthread_create(&t2,NULL,&th1,NULL);
        pthread_join(t2,NULL);

        t=pthread_create(&t3,NULL,&th2,NULL);
        pthread_join(t3,NULL);
        
        
    /*main is the parent thread.
    the parent thread will output the values
    once the workers have exited.
    */
    printf("\nThe average value is %f",average);
    printf("\nThe Minimum  value is %d",minimum);
    printf("\nThe Maximum  value is %d\n",maximum);
        
return 0;

}

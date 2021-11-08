/*
Write a program in c multi-threaded program that calculates various statistical
values for a list of numbers. This program will be passed a series
of numbers on the command line and will then create
three separate worker threads.
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>



int *arg;
int n;


/*
 average, minimum, and maximum 
 values will be stored globally
*/
float average;
int minimum;
int maximum;

//thread1 for calculating average
void *th()
{
        float sum=0;
        for(int i=1;i<=n;i++)
                sum=sum+arg[i];
        average=(sum/n);
        
}
//thread2 for calculating minimum value
void *th1()
{


        minimum=arg[1];
        for(int i=1;i<=n;i++)
                if(minimum>arg[i])
                minimum=arg[i];
        

}
//thread3 for calculating maximum value
void *th2()
{

        maximum=arg[1];
        for(int i=1;i<=n;i++)
                if(maximum<arg[i])
                        maximum=arg[i];
                        
}
int main(int argc, char *argv[])
{
       
     n = argc - 1;
    arg=(int * )malloc(sizeof(int)*n);
	
   /* printf("enter how many elements \n");
    scanf("%d",&n);
    printf("enter elements\n");*/
	for(int i=1;i<=n;i++)
	{
	    arg[i] = atoi(argv[i]);
	}
            
            
        printf("\n\n");
        

        for (int i=1;i<=n;i++)
        {
                printf("%d ", arg[i]);

        }


    int t,i;
    //three object of worker threads are t1 ,t2 and t3
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
    printf("\n The average value is %f",average);
    printf("\nThe Minimum  value is %d",minimum);
    printf("\nThe Maximum  value is %d",maximum);
        
return 0;

}

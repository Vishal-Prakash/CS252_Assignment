# statistical_values.c

## Instructions to execute the code

1. Enter the following code on the command line in the terminal: <br> ``` gcc statistical_values.c -o values -lpthread -lm ``` <br> The code is compiled by the gcc compiler.
2. Now, enter the data in the command line: <br> ``` ./values data1, data2,.... ``` 
3. The code is executed and the results average, minimum, maximum, median and standard deviation are obtained on the command line

## Results Obtained
***Test cases***

1. Finding Statistical Values for even number of input values: 
![even](https://user-images.githubusercontent.com/72442915/142990842-44576db5-a907-4e4f-9660-d752c0c5a3e0.jpg)

2. Finding Statistical Values for odd number of input values:
![odd](https://user-images.githubusercontent.com/72442915/142991061-98bf3419-907d-42fa-9010-09a494b28469.jpg)

Function calls:
  1. ``` pthread_t {thread name }```
      * Used for declaring a thread.
      * Stores the thread ID of the new thread.
      
  2. ``` int pthread_join(pthread_t thread, void **status); ```
      * Used for waiting for the termination of a thread
    
      
  
  3. ``` int pthread_create(pthread_t *thread, pthread_attr_t *attr, void *(*start_routine) (void *arg), void *arg); ```
      * Used for creating a new thread
      * thread: location where the thread ID is stored
      * attr:  structure that specifies the attributes of the new thread.
      * start_routine: routine where the thread begins.
      * arg : arguments to pass to start_routine.

  4. ```  void pthread_exit(void *status); ```
      * Used for terminating a thread.


## References

  

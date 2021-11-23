# Collatz_Conjecture.c
## Instructions to execute the code

1. Enter the following code on the command line in the terminal: <br> ``` gcc Collatz_Conjecture.c -o Collatz_Conjecture ``` <br> The code is compiled by the gcc compiler.
2. Now, enter the data in the command line: <br> ``` ./Collatz_Conjecture first_number_of_the_sequence  ```
3. The code is executed and the Collatz Conjecture sequence is displayed on the command line.

## Results Obtained

1. The Collatz Conjecture sequence for starting number 15:

![col15](https://user-images.githubusercontent.com/72442915/142995922-600a4634-e67b-4a39-9c5a-fed617cf3cbe.jpg)



2. The Collatz Conjecture sequence for starting number 5:

![col5](https://user-images.githubusercontent.com/72442915/142996011-47b8745b-b4a1-42d6-a51a-4408cdaf7adb.jpg)

## Function Calls

1.  ``` fork() ```
    * Used to create a child process out of parent process.
    * In parent, fork() returns the process ID of the created process. In the child, it returns 0
    * Parent and child processes execute simultaneously.
  
2. ``` wait() ```
    * Used when we want the parent process to wait for the child process to complete.
    * The parent process continues execution after the child process teminates.

## References
  * [https://github.com/SeanStaz/theCollatzConjecture.c/blob/master/hailstone.c](https://github.com/SeanStaz/theCollatzConjecture.c/blob/master/hailstone.c) 
  * [http://ucmassignments.blogspot.com/2016/06/a-collatz-conjecture-collatz-conjecture.html](http://ucmassignments.blogspot.com/2016/06/a-collatz-conjecture-collatz-conjecture.html)
  * [https://www.section.io/engineering-education/fork-in-c-programming-language/](https://www.section.io/engineering-education/fork-in-c-programming-language/)

My code is based on the [Collatz Conjecture code by Sean Staz](https://github.com/SeanStaz/theCollatzConjecture.c/blob/master/hailstone.c) . Mainly, command line arguments argc and argv were added to take input from the command line. A few variable names were changed. A few additions like displaying pid of the code, changing the printf were added and structure of the code was modified at some places as per necessity. I wemt through the code available on [UCM Assignments](http://ucmassignments.blogspot.com/2016/06/a-collatz-conjecture-collatz-conjecture.html) to get an idea of how the code works and the structuring of the output.  


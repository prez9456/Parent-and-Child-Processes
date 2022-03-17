README
======

A. This package includes the following files.

|-- Starter.c
|-- Fibb.c
|-- Prime.c
|-- Total.c
|-- Makefile
|-- README.txt [This file]


B. Use your designed makefile 
To compile the code and build the executable using the command 

systemprompt>  make

To remove the  executable files use

systemprompt>  make clean

To run the program use (assuming data.txt) 

systemprompt> ./Starter data.txt

which will run the program and generate the outputs.


C. Answer the following questions (1 point each, select/type the right answer).

    1. How many of the least significant bits of the status does WEXITSTATUS return?
      - 8 bits

    2. Which header file has to be included to use the WEXITSTATUS?
      - #include <sys/wait.h>

    3. What is the return value for the fork() in a child process?
      - the value is 0

    4. Give a reason for the fork() to fail?
      -It can fail due to the lack of resources available like memory.

    5. In the program written by you, are we doing a sequential processing or a concurrent processing
      with respect to the child processes? Sequential processing is when only one of the child processes
      is running at one time, and concurrent processing is when more than one child
      process can be running at the same time.
      - I am doing sequential processing with respect to the child processes.

    6. Do you Observe any anomalies in the output from child process and the output from parent
      process. Provide a reason for that observation. ( 2 points )
      - When i test my code with 25 total returns the wrong number because there isn't enough bits
      in WEXITSTATUS to return 325.
 

D. Example Outputs
maggot:~/cs370/hw2$ ./Starter data.txt
Starter[2854079] : Forked process with ID 2854080.
Starter[2854079] : Waiting for process [2854080].
Fibb[2854080] : Number of terms in fibonacii series is 5
Fibb[2854080] : The first 5 numbers of the fibonacci sequence are:
0, 1, 1, 2, 3,
Starter: Child process 2854080 returned 3
Starter[2854079] : Forked process with ID 2854081.
Starter[2854079] : Waiting for process [2854081].
Prime[2854081] : First 5 prime numbers are:
2, 3, 5, 7, 11, 
Starter: Child process 2854081 returned 11
Starter[2854079] : Forked process with ID 2854082.
Starter[2854079] : Waiting for process [2854082].
Total[2854082] : Sum = 15
Starter: Child process 2854082 returned 15
Starter[2854079] : Forked process with ID 2854083.
Starter[2854079] : Waiting for process [2854083].
Fibb[2854083] : Number of terms in fibonacii series is 10
Fibb[2854083] : The first 10 numbers of the fibonacci sequence are:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34,
Starter: Child process 2854083 returned 34
Starter[2854079] : Forked process with ID 2854084.
Starter[2854079] : Waiting for process [2854084].
Prime[2854084] : First 10 prime numbers are:
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
Starter: Child process 2854084 returned 29
Starter[2854079] : Forked process with ID 2854085.
Starter[2854079] : Waiting for process [2854085].
Total[2854085] : Sum = 55
Starter: Child process 2854085 returned 55
fibb: 34
Prime: 29
total Count: 55
maggot:~/cs370/hw2$ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char *argv[]){
    int end = atoi(argv[1]);
    int prev = 0, current = 1, next;

    // Step 5
    // print Pid and it should match Pid from fork()
    printf("Fibb[%d] : Number of terms in fibonacii series is %d\n", getpid(), end);
    printf("Fibb[%d] : The first %d numbers of the fibonacci sequence are:\n", getpid(), end);
    // step 6
    // fibonacii
    for(int i = 1; i <= end; ++i){
        if(i == end){
            printf("%d,\n",prev);
            break;
        }
        printf("%d, ", prev);
        next = prev + current;
        prev = current;
        current = next;
    }
    // return nth fibonacii number ( n being value of string)
    return prev;
}
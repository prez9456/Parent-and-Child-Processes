#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    // variables
    int end = atoi(argv[1]);

    // step 6
    // total sum
    int sum = 0;
    for(int i = 0; i <= end; i++){
        sum += i;
    }
    // Step 5
    // print Pid and it should match Pid from fork()
    // return the sum of first n number (n being value of string)
    printf("Total[%d] : Sum = %d\n", getpid(), sum);
    return sum;
}

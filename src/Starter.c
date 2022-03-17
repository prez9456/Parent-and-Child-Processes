#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

# define MAXCHAR 100

int main(int argc, char *argv[]){
    if (argc != 2){
        fprintf(stderr, "Not enough arguments. Needs a total of 2\n");
        exit(1);
    }
    // variables
    char *fname = argv[1];
    int status;
    char str[MAXCHAR];
    int hold, hold1, hold2;

    // Step 1
    //MAKE ERROR IF BLANK INPUT IS GIVEN
    // read all lines from data.txt file using fopen()
    FILE *in = fopen(fname, "r");
    fseek(in,0,SEEK_END);
    int size = ftell(in);
    if(size == 0){
        fprintf(stderr, "File is empty, add input into file\n");
        exit(2);
    }
    rewind(in);
    while(fgets(str, MAXCHAR, in)){
        // Step 2
        // execute fork() to launch 3 children
        // send each line to a child one at a time
        // each program gets one line as argument
        int pid, pid1, pid2;

        // child 1
        pid = fork();
        
        if(pid < 0){
            fprintf(stderr, "Fork Failed\n");
            return 0; //  change this to exit
        }
        // child calls the program fibb
        else if(pid == 0){
            // step 4
            // use execlp() to run fibb program passing str the input from file
            execlp("./Fibb", "./Fibb", str, NULL);
        }
        // parent prints the return value from child using WEXITSTATUS
        else{
            // step 3
            // print out Pid that it created by checking return value from fork()
            printf("Starter[%d] : Forked process with ID %d.\n", getpid(), pid);
            printf("Starter[%d] : Waiting for process [%d].\n",getpid(), pid);
            wait(&status);
            // step 7
            // print return values from programs
            // WEXITSTATUS(status) function is used to get result as 8 bit int from children
            int rett = WEXITSTATUS(status);
            hold = rett;
            printf("Starter: Child process %d returned %d\n",pid, rett);
        }

        // child 2
        pid1 = fork();
        if(pid1 < 0){
            fprintf(stderr, "Fork Failed\n");
            return 0;
        }
        else if(pid1 == 0){
            execlp("./Prime", "./Prime", str, NULL);
        }
        else{
            printf("Starter[%d] : Forked process with ID %d.\n", getpid(), pid1);
            printf("Starter[%d] : Waiting for process [%d].\n",getpid(), pid1);
            wait(&status);
            int rett = WEXITSTATUS(status);
            hold1 = rett;
            printf("Starter: Child process %d returned %d\n",pid1, rett);
        }

        // child 3
        pid2 = fork();
        if(pid2 < 0){
            fprintf(stderr, "Fork Failed\n");
            return 0;
        }
        else if(pid2 == 0){
            execlp("./Total", "./Total", str, NULL);
        }
        else{
            printf("Starter[%d] : Forked process with ID %d.\n", getpid(), pid2);
            printf("Starter[%d] : Waiting for process [%d].\n",getpid(), pid2);
            wait(&status);
            int rett = WEXITSTATUS(status);
            hold2 = rett;
            printf("Starter: Child process %d returned %d\n",pid2, rett);
        }
    }
    // step 8
    // print the fibb, prime, and total of the last input number
    printf("fibb: %d\n",hold);
    printf("Prime: %d\n",hold1);
    printf("total Count: %d\n",hold2);
    fclose(in);

    return 0;
}
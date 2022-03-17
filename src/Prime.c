#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int end = atoi(argv[1]);
    int SIZE = 32;
    // Step 5
    // print Pid and it should match Pid from fork()
    printf("Prime[%d] : First %d prime numbers are:\n", getpid(), end);

    // step 6
    // prime
    int p = 2, i = 1, hold;
    while(i <= end){
        int check = 1;
        for(int count = 2; count <= p-1; count++){
            if(p%count == 0){
                check = 0;
                break;
            }
        }
        if(check == 1){
            printf("%d, ", p);
            i++;
            hold = p;
        }
        p++;
    }
    char SHM_P[] = "SHM_Prime";
    int SHM_FDP = shm_open(SHM_P, O_CREAT | O_RDWR, 0666);
    void* SHM_Pptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, SHM_FDP, 0);
    sprintf(SHM_Pptr, "%d", hold);
    unlink(SHM_P);
    printf("\n");
    // return nth prime number (n being value of string)
    return hold;
}
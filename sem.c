#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>

#define SEM 7

int main(int argc, char** argv){
  //printf("\n argc: %d\n",argc);
  //printf("\n argv[argc=%d]: %s\n\n", argc, argv[argc-1]);
  int sem_descriptor;
  if (argc<2){//if no arguments in the arg vector  or 1 ./a.out
    printf("I think you forgot something...");
  }

  //for the creation
  else if(!strcmp(argv[1],"-c") && argc==3){//./a.out -c N ==> argc==3
    sem_descriptor=semget(SEM,1, IPC_CREAT|IPC_EXCL|0644);
    if(sem_descriptor==-1){
      printf("oopsies you can't do that! Semaphore already exists\n");
    }
    else{
      int num;
      sscanf(argv[2],"%d",&num);
      //printf("num: %d\n",num);
      semctl(sem_descriptor,0,SETVAL,num);
      printf("semaphore created: %d\t with value: %d\n",sem_descriptor, num);
    }
  }

  //for viewing the value
  else if(!strcmp(argv[1],"-v")){
    sem_descriptor=semget(SEM,0,0);
    printf("Semaphore value: %d\n",semctl(sem_descriptor,0,GETVAL));

  }

  //for removal of semaphore
  else if(!strcmp(argv[1],"-r")){
    sem_descriptor=semget(SEM,0,0);
    printf("semaphore removed: %d\n", semctl(sem_descriptor,0,IPC_RMID));
  }
  return 0;
}

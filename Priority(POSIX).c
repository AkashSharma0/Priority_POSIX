// server
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <json/json.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h> 
#include <time.h>
#include <pthread.h> 

#define MAX_THREAD 2 

int var=0;	//Global reference

void *print(void *num)
{	
     int prio = *(int*)num;

     sleep(3);

     printf("\nValue of var::%d from thread %d ", var,prio);

}



int main(int argc, char const *argv[]) 
{ 

	int t=0;

        pthread_t thread[MAX_THREAD];

	for(t=0;t<MAX_THREAD;t++)
	{
	
      	pthread_create(&thread[t], NULL, print, (void*) &t); 

	unsigned int r = pthread_setschedprio(thread[t], t); //priority

	if(r==0)
	{
		printf("\npriority set\n");
    		printf("\nValue of r ::%d ", r);
	}

	sleep(2);
	}

	sleep(5);
 

}


















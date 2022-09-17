#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void grandchild()
{
	pid_t  grandchild_pid;
	fprintf(stderr, "I am the Grandchild. My pid is %d \n",getpid());
	execlp("/snap/bin/firefox","firefox",NULL);
}


void child()
{
	pid_t  child_pid;
	child_pid = fork();
    fprintf(stderr, "I am the Child. My pid is %d \n",getpid());

	if (child_pid < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if (child_pid == 0) { /* grandchild process */
		grandchild();
	}
	else { /* child process */
	/* child will wait for the grandchild to complete */
		wait(NULL);
		printf("\n Grandchild Complete \n");
	}
}

int main()
{
	pid_t  parent_pid;
	parent_pid = fork();
    fprintf(stderr, "I am the Parent. My pid is %d \n",getpid());

	if (parent_pid < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if (parent_pid == 0) { /* child process */
		child();
	}
	else { /* parent process */
	/* parent will wait for the child to complete */
		wait(NULL);
		printf("\n Child Complete \n");
		exit(0);
	}
}
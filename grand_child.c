#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

//code following professor's lecture
int main()
{
	int i;
	pid_t id;

	id = fork(); //creats the child process

	fprintf(stderr, "This is process %d \n", getpid());
	fprintf(stderr, "id %d \n\n", id);

	wait(NULL);
	id = fork(); //creats the grandchild process

	fprintf(stderr, "This is process %d \n", getpid());
	fprintf(stderr, "id %d \n\n", id);
	execlp("/snap/bin/firefox","firefox",NULL);

	wait(NULL);
	//sleep(40); //so we can test with htop
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	pid_t pid[argc];

	if (argc < 2)
	{
		fprintf(stderr, "Usage: file [textfile]\n");
		exit(-1);
	}

	for (int i = 1; i < argc; i++)
	{
		pid[i] = fork();

		if (pid[i] == 0)
		{
			if (execl("./file", file, argv[i], NULL) < 0)
			{
				fprintf(stderr, "Error: cannot start process file %s\n", argv[i]);
				exit(-2);
			}
			else
			{
				fprintf(stderr, "Start processing file %s\n", argv[i]);
			}
		}
	}

	sleep(1);

	for (int i = 1; i < argc; i++)
	{
		int exit_status;
		int status = waitpid(pid[i], &exit_status, WHOHANG);

		if (pid[i] == status)
		{
			fprintf(stderr, "Finished processing file %s, result=%d\n", argv[i], WEXITSTATUS(exit_status));
		}
	}
	int handle;

	return 0;
}
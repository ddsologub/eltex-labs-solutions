#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: file textfile\n");
		exit(0)
	}
	return 0;
}
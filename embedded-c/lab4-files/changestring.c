#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc < 3) {
		fprintf(stderr, "Too few arguments. Use: changechar <filename> <char>\n");
		exit(1);
	}

	char foutname[255];
	strcpy(foutname, argv[1]);
	strcat(foutname, ".out");

	char * exclude_str = argv[2];


	FILE *fin, *fout;
	
	if ((fin = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Cannot open input file %s\n", argv[1]);
		exit(1);
	}

	if ((fout = fopen(foutname, "w")) == NULL) {
		fprintf(stderr, "Cannot open output file\n");
		exit(1);
	}

	char line[255];
	while(fgets(line, 255, fin) != NULL) {

		if (strstr(line, exclude_str) == NULL){
			fputs(line, fout);
		}
	
	}	

	
	if (fclose(fin)) {
		fprintf(stderr, "Cannot close input file\n");
		exit(1);
	}

	if (fclose(fout)) {
		fprintf(stderr, "Cannot close output file\n");
		exit(1);
	}

	return 0;
}
